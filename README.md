# Tenstorrent Experiments

A collection of Tenstorrent experiments and benchmarks for personal learning and research.

## Requirements

- Tenstorrent hardware
- Tenstorrent system software installed with `tt-installer`
- `tt-metal` submodule

## Setup

Install the Tenstorrent system software stack first:

- https://docs.tenstorrent.com/getting-started/README.html

The installer sets up the kernel driver, firmware, HugePages, `tt-smi`, and related system tools. After installation and reboot, verify that the card is visible:

```bash
source ~/.tenstorrent-venv/bin/activate
tt-smi
```

Then initialize the repository submodules:

```bash
git submodule update --init --recursive
```

Some `tt-metal` submodules are only needed for specific workflows:

- `tt_metal/third_party/umd`: needed for native source builds and low-level Metalium development.
- `tt_metal/third_party/tracy`: needed for Tracy profiling support.
- `models/demos/.../reference/llama`: only needed for related model demo workflows.

## Wheel vs Source Build

Start with the published `ttnn` package when the goal is to run small TT-NN experiments, sanity checks, or benchmarks without modifying `tt-metal` itself:

```bash
conda activate <env>
pip install ttnn torch
```

Use a source build from the `tt-metal` submodule when the experiment needs local `tt-metal` changes or lower-level Metalium development:

- editing TT-NN, TT-Metalium, kernels, runtime, or UMD-related code
- using a newer `tt-metal` commit than the published package provides
- building C++/Metalium examples directly from the source tree
- enabling development/profiling workflows such as Tracy

The source-build path is heavier and needs the recursive submodules:

```bash
cd tt-metal
git submodule update --init --recursive
./build_metal.sh
./create_venv.sh
source python_env/bin/activate
```

In short: use the wheel first for experiment scripts in this repo; compile `tt-metal` when the source tree itself becomes part of the experiment.

## Organization

- `tt-metal/`: Tenstorrent `tt-metal` repository as a submodule.
- `experiments/metalium/`: Low-level TT-Metalium kernel and runtime experiments.
- `experiments/ttnn/`: TT-NN API experiments.
- `experiments/benchmarks/`: Small benchmarks and performance notes.
- `experiments/notes/`: Scratch notes and observations.
