#include <utility>

#include <tt-metalium/device.hpp>
#include <tt-metalium/distributed.hpp>
#include <tt-metalium/host_api.hpp>

using namespace tt;
using namespace tt::tt_metal;

int main() {
    int device_id = 0;
    auto mesh_device = distributed::MeshDevice::create_unit_mesh(device_id);
}
