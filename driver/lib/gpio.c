#include <config.h>

#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static unsigned GPIO_BASE = 0x3f200000;

volatile unsigned int *gpfsel0;
volatile unsigned int *gpset0;
volatile unsigned int *gpclr0;
volatile unsigned int *gplev0;

/**
 * Initializes the register pointers for the GPIO pins
 */
void gpioInitPtrs() {

	int fd = -1;
	
	if ((fd = open("/dev/mem", O_RDWR, 0)) == -1) {
	
		err(1, "Error opening /dev/mem");
	
	}
	
	gpfsel0 = (unsigned int *) mmap(0, getpagesize(), PROT_WRITE, MAP_SHARED, fd, GPIO_BASE);
	
	if (gpfsel0 == MAP_FAILED) {
	
		errx(1, "Error during maping GPIO");
	
	}
	
	gpset0 = gpfsel0 + 0x7;
	gpclr0 = gpfsel0 + 0xA;
	gplev0 = gpfsel0 + 0xD;
	
	return;

}

/**
 * Sets the mode of a pin
 * Receives the pin and the mode
 */
void gpioSetModeIndividual(int pin, int mode) {

	if (pin > 9 || pin < 2) {
	
		errx(1, "Error, the pins must be between 2 and 9");
	
	}
	
	if (mode > 7 || mode < 0) {
	
		errx(1, "Error, the mode must be between 0 and 7");
	
	}

	*gpfsel0 = *gpfsel0 | (mode << (pin * 3));
	
	return;

}

/**
 * Gets the mode of a pin
 * Receives the pin
 */
int gpioGetModeIndividual(int pin) {

	if (pin > 9 || pin < 2) {
	
		errx(1, "Error, the pins must be between 2 and 9");
	
	}
	
	return (*gpfsel0 >> (pin * 3)) & 7;

}

/**
 * Writes a value to a pin
 * Receives the pin and the bit
 */
void gpioWriteIndividual(int pin, int bit) {

	if (pin > 9 || pin < 2) {
	
		errx(1, "Error, the pins must be between 2 and 9");
	
	}

	if (bit) {
	
		*gpset0 = *gpset0 | (1 << pin);
	
	} else {
	
		*gpclr0 = *gpclr0 | (1 << pin);
	
	}
	
	return;

}

/**
 * Reads a value from a pin
 * Receives the pin
 */
int gpioReadIndividual(int pin) {

	if (pin > 9 || pin < 2) {
	
		errx(1, "Error, the pins must be between 2 and 9");
	
	}
	
	return (*gplev0 >> pin) & 1;

}

/**
 * Sets the mode of a group of pins
 * Receives the mode
 */
void gpioSetModeGroup(int mode) {

	if (mode > 7 || mode < 0) {
	
		errx(1, "Error, the mode must be between 0 and 7");
	
	}
	
	for (int i = 2; i <= 9; i++) {
	
		*gpfsel0 = *gpfsel0 | (mode << (i * 3));	
	
	}
	
	return;

}

/**
 * Gets the mode of all pins
 */
void gpioGetModeGroup() {

	for (int i = 2; i <= 9; i++) {
	
		printf("El pin %d se encuentra en el modo %u", i, (*gpfsel0 >> (i * 3)) & 7);
	
	}
	
	return;

}

/**
 * Writes a value to a group of pins
 * Receives the bit
 */
void gpioWriteGroup(int bit) {

	if (bit) {
	
		for (int i = 2; i <= 9; i++) {
	
			*gpset0 = *gpset0 | (1 << i);
		
		}
	
	} else {
	
		for (int i = 2; i <= 9; i++) {
	
			*gpclr0 = *gpclr0 | (1 << i);
		
		}
	
	}
	
	return;

}

/**
 * Reads a value from a group of pins
 */
void gpioReadGroup() {

	for (int i = 2; i <= 9; i++) {
	
		printf("El pin %d tiene el valor %u", i, (*gplev0 >> i) & 1);
	
	}
	
	return;

}
