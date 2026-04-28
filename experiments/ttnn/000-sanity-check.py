import sys

import torch
import ttnn


def main() -> int:
    device = ttnn.open_device(device_id=0)
    try:
        torch_a = torch.arange(32 * 32, dtype=torch.bfloat16).reshape(32, 32)
        torch_b = torch.ones((32, 32), dtype=torch.bfloat16)
        expected = torch_a + torch_b

        tt_a = ttnn.from_torch(torch_a, dtype=ttnn.bfloat16, layout=ttnn.TILE_LAYOUT, device=device)
        tt_b = ttnn.from_torch(torch_b, dtype=ttnn.bfloat16, layout=ttnn.TILE_LAYOUT, device=device)
        tt_out = ttnn.add(tt_a, tt_b)
        actual = ttnn.to_torch(tt_out)

        if not torch.equal(actual, expected):
            print("FAIL")
            print("expected:")
            print(expected)
            print("actual:")
            print(actual)
            return 1

        print("PASS")
        print(actual[:2, :8])
        return 0
    finally:
        ttnn.close_device(device)


if __name__ == "__main__":
    sys.exit(main())
