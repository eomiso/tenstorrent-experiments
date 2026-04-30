/**
 * CreateKernel / Enqueue / Finish
 * Check the kernel log with the generated logs
 */

#include <utility>

#include <tt-metalium/device.hpp>
#include <tt-metalium/distributed.hpp>
#include <tt-metalium/host_api.hpp>

using namespace tt;
using namespace tt::tt_metal;

int main() {

    /* CREATE KERNEL */
    /* Mesh Device, Program, Kernel */
    constexpr int device_id = 0;
    constexpr CoreCoord core = {0, 0};
    auto mesh_device = distributed::MeshDevice::create_unit_mesh(device_id);

    Program program = CreateProgram();
    CreateKernel(program, "kernels/null_compute_kernel.cpp", core, ComputeConfig{});

    /* ENQUEUE*/
    /* workload */
    distributed::MeshCoordinateRange device_range(mesh_device->shape());
    distributed::MeshWorkload workload;

    workload.add_program(device_range, std::move(program));

    /* command queue */
    auto& cq = mesh_device->mesh_command_queue();
    distributed::EnqueueMeshWorkload(cq, workload, false);

    /* FINISH */
    distributed::Finish(cq);

    if (!mesh_device->close()) {
        return 1;
    }

    fmt::print("PASS: null compute kernel completed on device {} core ({}, {})\n", device_id, core.x, core.y);
    fmt::print("Mesh Shape: {}\n", mesh_device->shape());

    return 0;
}
