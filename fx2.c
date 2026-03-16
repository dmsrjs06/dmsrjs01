#include <stdio.h>

int main() {

	float input;
	
	scanf_s("%f", &input);

	unsigned int totalbits = *(unsigned int*)&input;

	unsigned int sign = (totalbits >> 31) & 0x1;
	unsigned int eightbits = (totalbits >> 23) & 0xFF;
	unsigned int twentythreebits = totalbits & 0x7FFFFF;
	
	printf("%u", sign);

	printf("/");

	for (int i = 7; i >= 0; i--) {
		printf("%u", (eightbits >> i) & 1);	
		if (i % 4 == 0 && i != 0)
			printf(" ");
	}
	printf("/");

	for (int i = 22; i >= 0; i--) {
		printf("%u", (twentythreebits >> i) & 1);
		if ((i+1) % 4 == 0 && i != 0)
		printf(" ");
	}
	
	return 0;
}