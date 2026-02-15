#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

int main() {
	int rect_a;
	int rect_b;

	double circ_r;

	printf("Adja meg a téglalap oldalait (egész szám): \n");
	scanf("%d %d", &rect_a, &rect_b);

	printf("Terület: %d \n", (rect_a * rect_b)); 
	printf("Kerület: %d \n", (2 * (rect_a + rect_b)));

	printf("Adja meg a kör sugarát (valós szám): \n");
	scanf("%lf", &circ_r);

	printf("Kör területe: %f \n", (pow(circ_r, 2) * M_PI));
	printf("Kör kerülete: %f \n", (2 * circ_r * M_PI));


	return 0;
}
