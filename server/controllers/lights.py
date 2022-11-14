from libs.gpioman import *
from config import constants


def finish() -> None:
    """
    This function clears the pins used by seats.
    """
    for pin in constants.PINS['seats'].values():
        unexport_command(pin)

def start() -> None:
    """
    This function starts the pins used by seats.
    """
    for seat, pin in constants.PINS['seats'].items():
        if export_command(pin) == constants.FAIL:
            print(f'Light Error: Pin {pin} for {seat} failed to start.')
        else:
            if pin_mode(pin, constants.OUTPUT_MODE) == constants.FAIL:
                print(f'Light Error: Pin {pin} for {seat} failed to start.')


def get_state(seat: str) -> int:
    """
    This function returns the current state of a specific seat.

    Params
    ------------------------------------------------------------------
        room: str
            Name of the seat.
    
    Returns
    ------------------------------------------------------------------
        the current state of the seat.
    """
    pin: int = constants.PINS['seats'][seat]

    # Get the state of the door
    result = digital_read(pin)

    if (result == constants.FAIL):
        print('Light Error: {seat} in pin {pin} is not available.')
    
    return result
