#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

double* full_elements(double* ptr_array, int size);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);

void main() {


	printf("¬ведите размер массива: ");
	double *ptr_array;
	int size;
	scanf("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL) {

		puts("error");

		return -1;

	}
	full_elements(ptr_array, size);
	put_elements(ptr_array, size);
	calc_elements(ptr_array, size);

	free(ptr_array);

}

double* full_elements(double* ptr_array, int n) {
	double a = 2;
	for (int i = 0; i < n; i++) {
		double x2 = pow(2, a);
		double x3 = 2 * pow(a, 2);
		double y = x2 - x3 - 1;
		ptr_array[i] = y;
		a += 1;
	}
}
int put_elements(double* ptr_array, int n) {

	for (int i = 0; i < n; i++) {
		printf("array[%d] = %lf\n", i, ptr_array[i]);
	}

}
double* calc_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		ptr_array[i] = pow(ptr_array[i], 2);
	}
	return ptr_array;
}