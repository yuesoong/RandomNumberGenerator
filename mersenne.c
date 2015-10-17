#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MASK 0xffffffff
uint32_t MT[624];
int index = 0;

void initialize(void);
void generate(void);
uint32_t extract(void);

int main(int argc, char* argv[]) {
    int num = 1, i;
    if (2 == argc) {
	num = atoi(argv[1]);
    }
    
    for (i = 0; i < num; ++i) {
	printf("%12ud  ", extract());
	if ((i + 1) % 10 == 0) {
	    printf("\n");
	}
    }
    
    return 0;    
}



uint32_t extract(void) {
    if (0 == index) {
	//initialize the generator
	initialize();
	//Generate an array of 624 untempered numbers
	generate();
    }

    uint32_t y = MT[index];
    y = y ^ (y >> 11);
    y = y ^ ((y << 7) & 2636928640);
    y = y ^ ((y << 15) & 4022730752);
    y = y ^ (y >> 18);    

    index = (index + 1) % 624;

    return y;
}


void initialize(void) {
    uint32_t seed = (uint32_t)time(NULL);
    int i = 0;
    MT[i] = seed;

    for (i = 1; i < 624; ++i) {
	MT[i] = (uint32_t)MASK & (1812433253UL * (MT[i - 1] ^ (MT[i - 1] >> 30)) + i);
    }
}

void generate(void) {
    int i;
    for (i = 0; i < 624; ++i) {
	uint32_t y = ((MT[i] & 0x80000000) + (MT[(i+1) % 624] & 0x7fffffff));
	MT[i] = MT[(i + 397) % 624] ^ y >> 1;
	if ((y % 2) != 0) {
	    MT[i] ^= 0x9908b0df;
	}
    }
}
