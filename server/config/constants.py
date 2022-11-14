# Dynamic library path
SRC_LIB: str = '/lib/libgpioman.so.0'


# When writing out one logic voltage
HIGH: int = 1
# When writing out zero logic voltage
LOW: int = 0


# When setting pin_mode to read values
INPUT_MODE: int = 0
# When setting pin_mode to write values
OUTPUT_MODE: int = 1
# When some function does not reach the goal, returns -1


FAIL: int = -1
# When some function reaches the goal, returns 0
SUCCESS: int = 0


# Pins values
PINS: dict = {
    'seats': {
        'V1-1': 2,
        'V1-2': 3,
        'V1-3': 4,
        'V1-4': 17,
        'V1-5': 27,
        'V1-6': 22,
        'V1-7': 10,
        'V1-8': 9,
        'V2-1': 14,
        'V2-2': 15,
        'V2-3': 18,
        'V2-4': 23,
        'V2-5': 24,
        'V2-6': 25,
        'V2-7': 8,
        'V2-8': 7
    }
}
