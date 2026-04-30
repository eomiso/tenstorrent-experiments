# Metalium Experiments

Low-level TT-Metalium experiments built out-of-tree against the `tt-metal` submodule.

## Setup

Build `tt-metal` first:

```bash
cd ../../tt-metal
git submodule update --init --recursive
./build_metal.sh
```

Then build and run Metalium experiments from this directory:

```bash
cd ../experiments/metalium
make run
```

The Makefile sets the runtime paths needed for out-of-tree execution:

- `TT_METAL_RUNTIME_ROOT`: points at the `tt-metal` submodule.
- `TT_METAL_KERNEL_PATH`: points at this experiment directory so kernel source paths resolve.

## Sanity Checks

Current examples:

- `000-null-compute-kernel-1chip.cpp`: opens device 0, dispatches a null compute kernel on core `(0, 0)`, and waits for completion.
- `001-null-compute-kernel-2chip-2_1x1mesh.cpp`: opens devices 0 and 1 as two 1x1 meshes, dispatches the same null compute kernel on each, and waits for both.

Run a specific example by overriding `SRC`:

```bash
make run SRC=000-null-compute-kernel-1chip.cpp
make run SRC=001-null-compute-kernel-2chip-2_1x1mesh.cpp
```

Successful runs create `generated/` logs. Useful files:

```bash
cat generated/watcher/kernel_names.txt
cat generated/watcher/kernel_elf_paths.txt
cat generated/inspector/kernels.yaml
```

For the null compute kernel sanity check, expect Metalium dispatch kernels plus the experiment kernel:

- `cq_prefetch`
- `cq_dispatch`
- `cq_dispatch_subordinate`
- `kernels/null_compute_kernel.cpp`

## Files

- `CMakeLists.txt`: out-of-tree CMake project linked against `TT::Metalium`.
- `Makefile`: convenience wrapper for configure, build, run, and clean.
- `kernels/null_compute_kernel.cpp`: minimal device-side compute kernel.
- `misc.hpp`: small host-side helpers shared by examples.
