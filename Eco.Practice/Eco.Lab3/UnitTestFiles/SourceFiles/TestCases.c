#include "TestCases.h"
#include "IEcoBase1.h"
// Функции сравнения для разных типов данных
int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/*
*** ТЕСТЫ
*/

// Тест 1: Массив целых чисел (int)
void test_integer_array_first(IEcoLab1* pIcomp) {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35};
    uint32_t nmemb = sizeof(arr) / sizeof(arr[0]);
    int keys[] = {1, 9, 20};
    int i = 0;

    printf("\n=== TEST 1: Integer Array (int) ===\n");
    for (i = 0; i < 3; i++) {
        int *result_my = (int*)pIcomp->pVTbl->MyBsearch(pIcomp, &keys[i], arr, nmemb, sizeof(int), compare_int);
    }
}


// Тест 2: Массив целых чисел (int)
void test_integer_array_second(IEcoLab1* pIcomp) {
	int arr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    uint32_t nmemb = sizeof(arr) / sizeof(arr[0]);
    int keys[] = {2, 19, 32};
    int i = 0;
    
    printf("\n=== TEST 2: Integer Array (int) ===\n");

    for (i = 0; i < 3; i++) {
        int *result_my = (int*)pIcomp->pVTbl->MyBsearch(pIcomp, &keys[i], arr, nmemb, sizeof(int), compare_int);
    }
}
