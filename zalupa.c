#include <stdio.h>
#include <stdlib.h>

int isOddInt(const void *a) {
    return (*((int*)a) % 2 == 0);
}
int isOddDouble(const void *a) {
	int integer = (int)*((double*)a);
	double doub = *((double*)a) - (double)integer;
	printf("\n%lf", doub);
	return integer % 2 == 0 && doub < 0.000001;
}
int count_if(void* base, size_t num, size_t size,
			 int (*pred)(const void*)) {
	int sum = 0;
    for (int i = 0; i < num; i++) {
    	if(pred((base + i*size))){
        	if(size == 4) {
        		sum += *((int*)(base + i*size));
        	} else {
        		sum += (int)*((double*)(base + i*size));
        	}
    	}
    }
    return sum ;
}
int main(){
	int size;
	scanf("%d", &size);
	int num = 5;
	if(size == 4) {
		int base[num];
		for(int i = 0; i < num; i++) {
			scanf("%d", &base[i]);
		}
		printf( "\n%d\n ",count_if(base, num, 4, isOddInt));
	} else {
		double base[num];
		for(int i = 0; i < num; i++) {
			scanf("%lf", &base[i]);
			printf("%lf ", base[i]);
		}
		printf( "\n%d\n ",count_if(base, num, 8, isOddDouble));
	}

	return 0;
}
