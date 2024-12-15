#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 50

void fill_array(int* arr, int size);
void print_array(int* arr, int size, const char* name);
int create_array(int* a, int size_a, int* b, int size_b, int* d);

int main() {

    int size_a = MIN + rand() % (MAX - MIN + 1);
    int size_b = MIN + rand() % (MAX - MIN + 1);
    int size_c = MIN + rand() % (MAX - MIN + 1);

    int* a = (int*)malloc(size_a * sizeof(int));
    int* b = (int*)malloc(size_b * sizeof(int));
    int* c = (int*)malloc(size_c * sizeof(int));
    int d[MAX * 2];

    if (a == NULL || b == NULL || c == NULL) {
        printf("Ошибка выделения памяти.\n");
    }

    fill_array(a, size_a);
    fill_array(b, size_b);
    fill_array(c, size_c);

    print_array(a, size_a, "Массив A");
    print_array(b, size_b, "Массив B");
    print_array(c, size_c, "Массив C");

    int size_d = create_array(a, size_a, b, size_b, d);
    print_array(d, size_d, "Массив D (чётные из A и нечётные из B)");

    free(a);
    free(b);
    free(c);
}

void fill_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int* arr, int size, const char* name) {
    printf("%s: ", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int create_array(int* a, int size_a, int* b, int size_b, int* d) {
    int index = 0;

    for (int i = 0; i < size_a; i++) {
        if (a[i] % 2 == 0) {
            d[index++] = a[i];
        }
    }

    for (int i = 0; i < size_b; i++) {
        if (b[i] % 2 != 0) {
            d[index++] = b[i];
        }
    }

    return index;
}