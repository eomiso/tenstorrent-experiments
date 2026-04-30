TT_METAL_ROOT ?= $(abspath ../../tt-metal)
TT_METAL_BUILD ?= $(TT_METAL_ROOT)/build_RelWithDebInfo
TT_METALIUM_DIR := $(abspath $(TT_METAL_BUILD)/lib/cmake/tt-metalium)

.PHONY: configure build clean

SRC ?= 000-null-compute-kernel.cpp
OUT ?= $(basename $(SRC)).out

configure:
	cmake -S . -B build \
		-DCMAKE_PREFIX_PATH=$(TT_METAL_BUILD) \
		-DTT-Metalium_DIR=$(TT_METALIUM_DIR) \
		-DEXAMPLE_SRC=$(SRC) \
		-DEXAMPLE_OUT=$(OUT)

build: configure
	cmake --build build 

clean:
	rm -rf build

run: build
	TT_METAL_RUNTIME_ROOT=$(TT_METAL_ROOT) TT_METAL_KERNEL_PATH=$(CURDIR) ./build/$(OUT)
