#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int num = 0;
    
    if (argc != 2) {
	printf("Please provide the number of random numbers needed.\n");
	return 0;
    } else {
	num = atoi(argv[1]);
    }
    
    uint32_t res[num];
    
    unsigned long m = (1 << 31);
    unsigned long a = 1103515245;
    unsigned long c = 12345;

    unsigned long seed = (unsigned long)time(NULL);
   
    int i = 0;
    for (; i < num; ++i) {
	seed = (a * seed + c);
	res[i] = (uint32_t)(seed) % m;
	seed = res[i];
    }
    
    for (i = 0; i < num; ++i) {
	printf("%12ud ", res[i]);
	if ((i + 1) % 10 == 0) {
	    printf("\n");
	}
    }
    return 0;
}
