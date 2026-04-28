# Tenstorrent Experiments

A collection of Tenstorrent experiments and benchmarks for personal learning and research.

## Requirements

- Tenstorrent hardware
- `tt-metal` submodule

## Setup

```bash
git submodule update --init --recursive
```

## Organization

- `tt-metal/`: Tenstorrent `tt-metal` repository as a submodule.
- `experiments/metalium/`: Low-level TT-Metalium kernel and runtime experiments.
- `experiments/ttnn/`: TT-NN API experiments.
- `experiments/benchmarks/`: Small benchmarks and performance notes.
- `experiments/notes/`: Scratch notes and observations.
