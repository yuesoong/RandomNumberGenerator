/*
 * This code refers to the code in the C programming language
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define CYCLE 4096 // Marsaglia recommended
#define MAX 809430660 //  Marsaglia recommended
static uint32_t Q[CYCLE];
static uint32_t c = 362436;

void initialize(uint32_t seed);
uint32_t generate(void);

int num = 1;

int main(int argc, char* argv[]) {
    if (2 == argc) {
	num = atoi(argv[1]);
    }
    int i;
    uint32_t seed = time(NULL);
    uint32_t res = 0;
    
    for (i = 0; i < num; ++i) {
	initialize(seed);
	res = generate();
	printf("%12ul", res);
	if ((i + 1) % 10 == 0) {
	    printf("\n");
	}
	seed = res;
    }
    return 1;
}

void initialize(uint32_t seed) {
    int i;
    srand(seed);

    for (i = 0; i < CYCLE; ++i) {
	Q[i] = rand();
    }

    do {
	c =rand();
    } while (c >= MAX);
}


uint32_t generate(void) {
    uint32_t i = CYCLE - 1;
    uint64_t t = 0;
    uint64_t a = 18782; // Marsaglia recommended
    uint32_t r = 0xfffffffe; // Marsaglia recommended
    uint32_t x = 0;

    i = (i + 1) & (CYCLE - 1);
    t = a * Q[i] + c;
    c = t >> 32;
    x = t + c;
    if (x < c) {
	x++;
	c++;
    }

    return Q[i] = r - x;
}
