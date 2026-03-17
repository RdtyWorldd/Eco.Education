#ifndef TESTCASES_H
#define TESTCASES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "IEcoLab1.h"
#include "IdEcoMemoryManager1.h"

// Тесты корректности
void test_integer_array(IEcoLab1* pIcomp);
void test_long_array(IEcoLab1* pIcomp);
void test_float_array(IEcoLab1* pIcomp);
void test_double_array(IEcoLab1* pIcomp);
void test_ldouble_array(IEcoLab1* pIcomp);
void test_string_array(IEcoLab1* pIcomp);

// Performance тесты
int16_t performance_test_int(IEcoLab1 *pIcomp, IEcoMemoryAllocator1* pIMem, uint32_t array_size, uint32_t seed);
int16_t performance_test_long(IEcoLab1 *pIcomp, IEcoMemoryAllocator1* pIMem, uint32_t array_size, uint32_t seed);
int16_t performance_test_float(IEcoLab1 *pIcomp, IEcoMemoryAllocator1* pIMem, uint32_t array_size, uint32_t seed);
int16_t performance_test_double(IEcoLab1 *pIcomp, IEcoMemoryAllocator1* pIMem, uint32_t array_size, uint32_t seed);
int16_t performance_test_ldouble(IEcoLab1 *pIcomp, IEcoMemoryAllocator1* pIMem, uint32_t array_size, uint32_t seed);
int16_t performance_test_string(IEcoLab1 *pIcomp, IEcoMemoryAllocator1* pIMem, uint32_t array_size, uint32_t seed);

// Функция для запуска всех performance тестов
int16_t run_all_performance_tests(IEcoLab1 *pIcomp, IEcoMemoryAllocator1* pIMem, uint32_t array_size, uint32_t seed);

#endif // TESTCASES_H
