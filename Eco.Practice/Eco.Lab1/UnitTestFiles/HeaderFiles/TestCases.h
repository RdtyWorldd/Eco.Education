#ifndef _INCLUDE_TEST_CASES_
#define _INCLUDE_TEST_CASES_

/* ECO OS */
#include "IdEcoMemoryManager1.h"
#include "IdEcoLab1.h"

/* STD LIB */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/*
 *
 * <сводка>
 *   Функции для тестирования реализованной функции компонента
 * </сводка>
 *
 * <описание>
 *   Сравнения работы функции MyBsearch компонента EcoLab1
 *      с реализацией из стандартной бибилотеки
 * </описание>
 *
 */

void test_integer_array(IEcoLab1* pIcomp);
void test_long_array(IEcoLab1* pIcomp);
void test_float_array(IEcoLab1* pIcomp);
void test_double_array(IEcoLab1* pIcomp);
void test_ldouble_array(IEcoLab1* pIcomp);
void test_string_array(IEcoLab1* pIcomp);

void performance_test();

#endif // _INCLUDE_TEST_CASES_
