#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int num = 1;
    if (2 == argc) {
	num = atoi(argv[1]);
    }
    printf("num == %d\n", num);
    return 0;
}
