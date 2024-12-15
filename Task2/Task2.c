#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

double* full_elements(double* ptr_array, int size);
int put_elements(double* ptr_array, int n);
int delete_elements_greater_than_A(double* ptr_array, int* size, double A);
double* insert_after_last_negative(double* ptr_array, int* size);

int main() {

    printf("Введите размер массива: ");
    int size;
    scanf("%d", &size);

    double* ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("Error: memory allocation failed.");
        return -1;
    }

    full_elements(ptr_array, size);
    printf("Исходный массив:\n");
    put_elements(ptr_array, size);

    double A;
    printf("Введите значение A: ");
    scanf("%lf", &A);
    delete_elements_greater_than_A(ptr_array, &size, A);

    printf("Массив после удаления элементов > A:\n");
    put_elements(ptr_array, size);

    ptr_array = insert_after_last_negative(ptr_array, &size);
    printf("Массив после вставки -999 после последнего отрицательного элемента:\n");
    put_elements(ptr_array, size);

    free(ptr_array);
}


double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * 2 - 0.8;
    }
    return ptr_array;
}


int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %lf\n", i, ptr_array[i]);
    }
    return 0;
}


int delete_elements_greater_than_A(double* ptr_array, int* size, double A) {
    int j = 0;
    for (int i = 0; i < *size; i++) {
        if (ptr_array[i] <= A) {
            ptr_array[j] = ptr_array[i];
            j++;
        }
    }
    *size = j;
    return j;
}

double* insert_after_last_negative(double* ptr_array, int* size) {
    int last_negative_index = -1;

    for (int i = 0; i < *size; i++) {
        if (ptr_array[i] < 0) {
            last_negative_index = i;
        }
    }

    if (last_negative_index == -1) {
        printf("Отрицательные элементы не найдены.\n");
        return ptr_array;
    }

    int new_size = *size + 1;
    double* new_array = (double*)realloc(ptr_array, new_size * sizeof(double));
    if (new_array == NULL) {
        puts("Недостаточно памяти.");
        return ptr_array;
    }

    ptr_array = new_array;

    for (int i = new_size - 1; i > last_negative_index + 1; i--) {
        ptr_array[i] = ptr_array[i - 1];
    }

    ptr_array[last_negative_index + 1] = -999;

    *size = new_size;
    return ptr_array;
}
