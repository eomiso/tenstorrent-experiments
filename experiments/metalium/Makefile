TT_METAL_BUILD ?= ../../tt-metal/build_RelWithDebInfo
TT_METALIUM_DIR := $(abspath $(TT_METAL_BUILD)/lib/cmake/tt-metalium)
# TT_METAL_RUNTIME_ROOT

.PHONY: configure build clean

configure:
	cmake -S . -B build -DCMAKE_PREFIX_PATH=$(TT_METAL_BUILD) -DTT-Metalium_DIR=$(TT_METALIUM_DIR) 

build: configure
	cmake --build build

clean:
	rm -rf build

# run:
#	TT_METAL_RUNTIME_ROOT=$(TT_METAL_ROOT) \

