/**
 * CreateKernel / Enqueue / Finish
 * Check the kernel log with the generated logs
 * 2chips: 1 x 1 mesh per chip
 */

#include <utility>

#include <tt-metalium/device.hpp>
#include <tt-metalium/distributed.hpp>
#include <tt-metalium/host_api.hpp>

#include "misc.hpp"

using namespace tt;
using namespace tt::tt_metal;

int main() {

    /* CREATE KERNEL */
    /* Mesh Device, Program, Kernel */

    constexpr CoreCoord core = {0, 0};
    auto mesh_devices = distributed::MeshDevice::create_unit_meshes({0, 1});
    auto mesh0 = mesh_devices.at(0);
    auto mesh1 = mesh_devices.at(1);

    Program program0 = CreateProgram();
    Program program1 = CreateProgram();
    CreateKernel(program0, "kernels/null_compute_kernel.cpp", core, ComputeConfig{});
    CreateKernel(program1, "kernels/null_compute_kernel.cpp", core, ComputeConfig{});

    /* ENQUEUE*/
    /* workload */
    distributed::MeshCoordinateRange device_range0(mesh0->shape());
    distributed::MeshCoordinateRange device_range1(mesh1->shape());
    distributed::MeshWorkload workload0;
    distributed::MeshWorkload workload1;

    workload0.add_program(device_range0, std::move(program0));
    workload1.add_program(device_range1, std::move(program1));

    /* command queue */
    distributed::EnqueueMeshWorkload(mesh0->mesh_command_queue(), workload0, false);
    distributed::EnqueueMeshWorkload(mesh1->mesh_command_queue(), workload1, false);

    /* FINISH */
    if (checked("finish mesh0", [&] { distributed::Finish(mesh0->mesh_command_queue()); }));
    if (checked("finish mesh1", [&] { distributed::Finish(mesh1->mesh_command_queue()); }));

    return 0;
}
