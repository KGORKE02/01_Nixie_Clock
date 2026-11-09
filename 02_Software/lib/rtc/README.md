# Real Time Clock (RTC)

**Purpose:** This module keeps time when supply voltage is not available
**Layer:** driver
**Depends on:** -
**Used by:** tbd

## Files
| File | Purpose |
|------|---------|
| ``   |  |
| `` |  |

## Public interface
- `bool init()`: what it does, what `false` means
- `void update()`: what it does, how often to call it

## Hardware (drivers only)
### Pins from `pins.h`:
| Pin | Dir | Description |
|------|---------|
| ``   |  | |
| `` |  |  |
| `` |  |  |

## How to test
- Bench: `pio run -e test_x -t upload`, expected output
- Unit: `pio test -e native -f test_x`

## Notes
Design decisions, limitations, known issues.