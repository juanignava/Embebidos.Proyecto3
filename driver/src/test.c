#include <gpio.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

	gpioInitPtrs();
	
	gpioSetModeIndividual(2, 0);
	gpioSetModeIndividual(3, 1);
	gpioSetModeIndividual(4, 2);
	
	printf("El pin %d se encuentra en el modo %u", 2, gpioGetModeIndividual(2));
	printf("El pin %d se encuentra en el modo %u", 3, gpioGetModeIndividual(3));
	printf("El pin %d se encuentra en el modo %u", 4, gpioGetModeIndividual(4));
	
	gpioWriteIndividual(3, 1);
	printf("El pin %d contiene el valor %u", 2, gpioReadIndividual(2));	
	
	gpioSetModeGroup(1);
	gpioGetModeGroup();
	gpioWriteGroup(1);
	usleep(1000000);
	gpioWriteGroup(0);
	
	gpioSetModeGroup(0);
	gpioReadGroup();
	
	return 0;

}
