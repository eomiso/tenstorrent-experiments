TT_METAL_ROOT ?= $(abspath ../../tt-metal)
TT_METAL_BUILD ?= $(TT_METAL_ROOT)/build_RelWithDebInfo
TT_METALIUM_DIR := $(abspath $(TT_METAL_BUILD)/lib/cmake/tt-metalium)

.PHONY: configure build clean

# SRC ?= 000-null-compute-kernel-1chip.cpp
SRC ?= 001-null-compute-kernel-2chip-2_1x1mesh.cpp
OUT ?= $(basename $(SRC)).out

configure:
	cmake -S . -B build \
		-DTT-Metalium_DIR=$(TT_METALIUM_DIR) \
		-DEXAMPLE_SRC=$(SRC) \
		-DEXAMPLE_OUT=$(OUT)

build: configure
	cmake --build build 

clean:
	rm -rf build

run: build
	TT_METAL_RUNTIME_ROOT=$(TT_METAL_ROOT) ./build/$(OUT)
