#include "TestCases.h"

// Функции сравнения для разных типов данных
int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_long(const void *a, const void *b) {
    long diff = *(long*)a - *(long*)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int compare_float(const void *a, const void *b) {
    float diff = *(float*)a - *(float*)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int compare_double(const void *a, const void *b) {
    double diff = *(double*)a - *(double*)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int compare_ldouble(const void *a, const void *b) {
    long double diff = *(long double*)a - *(long double*)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int compare_string(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}


/*
*** ТЕСТЫ
*/

// Тест 1: Массив целых чисел (int)
void test_integer_array(IEcoLab1* pIcomp) {
    printf("\n=== TEST 1: Integer Array (int) ===\n");
    
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35};
    uint32_t nmemb = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (uint32_t i = 0; i < nmemb; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int keys[] = {1, 9, 19, 35, 17, 2, 4, 20, 36, 0};
    
    for (int i = 0; i < 10; i++) {
        int *result_my = (int*)pIcomp->pVTbl->MyBsearch(pIcomp, &keys[i], arr, nmemb, sizeof(int), compare_int);
        int *result_std = (int*)bsearch(&keys[i], arr, nmemb, sizeof(int), compare_int);
        
        printf("Key %d: my=%p(%d), std=%p(%d) - %s\n", 
               keys[i], result_my, result_my ? *result_my : -1,
               result_std, result_std ? *result_std : -1,
               result_my == result_std ? "OK" : "FAIL");
    }
}

// Тест 2: Массив длинных целых чисел (long)
void test_long_array(IEcoLab1* pIcomp) {
    printf("\n=== TEST 2: Long Integer Array ===\n");
    
    long arr[] = {10L, 20L, 30L, 40L, 50L, 60L, 70L, 80L, 90L, 100L};
    uint32_t nmemb = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (uint32_t i = 0; i < nmemb; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");
    
    long keys[] = {10L, 50L, 100L, 25L, 110L};
    
    for (int i = 0; i < 5; i++) {
        long *result_my = (long*)pIcomp->pVTbl->MyBsearch(pIcomp, &keys[i], arr, nmemb, sizeof(long), compare_long);
        long *result_std = (long*)bsearch(&keys[i], arr, nmemb, sizeof(long), compare_long);
        
        printf("Key %ld: my=%p(%ld), std=%p(%ld) - %s\n", 
               keys[i], result_my, result_my ? *result_my : -1,
               result_std, result_std ? *result_std : -1,
               result_my == result_std ? "OK" : "FAIL");
    }
}

// Тест 3: Массив чисел с плавающей точкой (float)
void test_float_array(IEcoLab1* pIcomp) {
    printf("\n=== TEST 3: Float Array ===\n");
    
    float arr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.1f};
    uint32_t nmemb = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (uint32_t i = 0; i < nmemb; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    
    float keys[] = {1.1f, 5.5f, 10.1f, 2.5f, 11.0f};
    
    for (int i = 0; i < 5; i++) {
        float *result_my = (float*)pIcomp->pVTbl->MyBsearch(pIcomp, &keys[i], arr, nmemb, sizeof(float), compare_float);
        float *result_std = (float*)bsearch(&keys[i], arr, nmemb, sizeof(float), compare_float);
        
        printf("Key %.2f: my=%p(%.2f), std=%p(%.2f) - %s\n", 
               keys[i], result_my, result_my ? *result_my : 0,
               result_std, result_std ? *result_std : 0,
               result_my == result_std ? "OK" : "FAIL");
    }
}

// Тест 4: Массив чисел с плавающей точкой двойной точности (double)
void test_double_array(IEcoLab1* pIcomp) {
    printf("\n=== TEST 4: Double Array ===\n");
    
    double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    uint32_t nmemb = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (uint32_t i = 0; i < nmemb; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    
    double keys[] = {1.1, 5.5, 10.10, 2.5, 11.0};
    
    for (int i = 0; i < 5; i++) {
        double *result_my = (double*)pIcomp->pVTbl->MyBsearch(pIcomp, &keys[i], arr, nmemb, sizeof(double), compare_double);
        double *result_std = (double*)bsearch(&keys[i], arr, nmemb, sizeof(double), compare_double);
        
        printf("Key %.2f: my=%p(%.2f), std=%p(%.2f) - %s\n", 
               keys[i], result_my, result_my ? *result_my : 0,
               result_std, result_std ? *result_std : 0,
               result_my == result_std ? "OK" : "FAIL");
    }
}

// Тест 5: Массив чисел с плавающей точкой повышенной точности (long double)
void test_ldouble_array(IEcoLab1* pIcomp) {
    printf("\n=== TEST 5: Long Double Array ===\n");
    
    long double arr[] = {1.1L, 2.2L, 3.3L, 4.4L, 5.5L, 6.6L, 7.7L, 8.8L, 9.9L, 10.1L};
    uint32_t nmemb = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (uint32_t i = 0; i < nmemb; i++) {
        printf("%.2Lf ", arr[i]);
    }
    printf("\n");
    
    long double keys[] = {1.1L, 5.5L, 10.1L, 2.5L, 11.0L};
    
    for (int i = 0; i < 5; i++) {
        long double *result_my = (long double*)pIcomp->pVTbl->MyBsearch(pIcomp, &keys[i], arr, nmemb, sizeof(long double), compare_ldouble);
        long double *result_std = (long double*)bsearch(&keys[i], arr, nmemb, sizeof(long double), compare_ldouble);
        
        printf("Key %.2Lf: my=%p(%.2Lf), std=%p(%.2Lf) - %s\n", 
               keys[i], result_my, result_my ? *result_my : 0,
               result_std, result_std ? *result_std : 0,
               result_my == result_std ? "OK" : "FAIL");
    }
}

// Тест 6: Массив строк
void test_string_array(IEcoLab1* pIcomp) {
    printf("\n=== TEST 6: String Array ===\n");
    
    const char* arr[] = {"apple", "banana", "cherry", "grape", "orange", "pear", "strawberry"};
    uint32_t nmemb = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (uint32_t i = 0; i < nmemb; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
    
    const char* keys[] = {"cherry", "grape", "apple", "kiwi", "watermelon"};
    
    for (int i = 0; i < 5; i++) {
        char **result_my = (char**)pIcomp->pVTbl->MyBsearch(pIcomp, &keys[i], arr, nmemb, sizeof(char*), compare_string);
        char **result_std = (char**)bsearch(&keys[i], arr, nmemb, sizeof(char*), compare_string);
        
        printf("Key %s: my=%p(%s), std=%p(%s) - %s\n", 
               keys[i], result_my, result_my ? *result_my : "NULL",
               result_std, result_std ? *result_std : "NULL",
               result_my == result_std ? "OK" : "FAIL");
    }
}
