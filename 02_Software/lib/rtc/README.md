# Encoder

**Purpose:** This module 
**Layer:** driver
**Depends on:** -
**Used by:** tbd

## Files
| File | Purpose |
|------|---------|
| `encoder.h`   | Public interface |
| `encoder.cpp` | Implementation |

## Public interface
- `bool init()`: what it does, what `false` means
- `void update()`: what it does, how often to call it

## Hardware (drivers only)
### Pins from `pins.h`:
| Pin | Dir | Description |
|------|---------|
| `ENCODER_A`   | Input |A signal from encoder |
| `ENCODER_B` | Input | B signal |
| `ENCODER_SW` | Input | Push button from encoder |

## How to test
- Bench: `pio run -e test_x -t upload`, expected output
- Unit: `pio test -e native -f test_x`

## Notes
Design decisions, limitations, known issues.