void gpioInitPtrs();
void gpioSetModeIndividual(int pin, int mode);
int gpioGetModeIndividual(int pin);
void gpioWriteIndividual(int pin, int bit);
int gpioReadIndividual(int pin);
void gpioSetModeGroup(int mode);
void gpioGetModeGroup();
void gpioWriteGroup(int bit);
void gpioReadGroup();
