#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t start = 0x02;

int main(int argc, char* argv[]) {
    int num;
    if (1 == argc) {
	num = 500;
    } else if (2 == argc) {
	num = atoi(argv[1]);
    } else {
	printf("Only one parameter is needed.\n");
	return 0;
    }
    uint32_t res[num];
    
    uint32_t a = start;
    int i;
    for(i = 0; i < num; ++i) {
	uint32_t newbit = (((a >> 30) ^ (a >> 27)) & 1);
	a = ((a << 1) | newbit) & 0x7fffffff;
	res[i] = a;
	if (a == start) {
	    printf("The repetition period is %d, smaller than the required number\n", i + 1);
	    break;
	}
    }

    for (i = 0; i < num; ++i) {
	printf("%12ud", res[i]);
	if ((i + 1) % 10 == 0) {
	    printf("\n");
	}
    }
    return 0;
}
