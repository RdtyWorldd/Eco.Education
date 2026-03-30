/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab2
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab2
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoLab2.h"

/* QueryInterface */
int16_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_QueryInterface(
    IEcoCalculatorXPtr_t me, const UGUID* riid, void** ppv) {

    CEcoLab2* pCMe = (CEcoLab2*)me;

    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    if (IsEqualUGUID(riid, &IID_IEcoCalculatorX)) {
        *ppv = &pCMe->m_pVTblIX;
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIX;
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }

    ((IEcoCalculatorX*)*ppv)->pVTbl->AddRef((IEcoCalculatorX*)pCMe);
    return ERR_ECO_SUCCESES;
}

/* AddRef */
uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_AddRef(IEcoCalculatorXPtr_t me) {
    return CEcoLab2_AddRef((IEcoLab2*)me);
}

/* Release */
uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_Release(IEcoCalculatorXPtr_t me) {
    return CEcoLab2_Release((IEcoLab2*)me);
}

/* Addition */
int32_t ECOCALLMETHOD CEcoLab2_Addition(
    IEcoCalculatorXPtr_t me, int16_t a, int16_t b) {

    return (int32_t)(a + b);
}

/* Subtraction */
int16_t ECOCALLMETHOD CEcoLab2_Subtraction(
    IEcoCalculatorXPtr_t me, int16_t a, int16_t b) {

    return (int16_t)(a - b);
}


/* QueryInterface */
int16_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_QueryInterface(
    IEcoCalculatorYPtr_t me, const UGUID* riid, void** ppv) {

    CEcoLab2* pCMe = (CEcoLab2*)me;

    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    if (IsEqualUGUID(riid, &IID_IEcoCalculatorY)) {
        *ppv = &pCMe->m_pVTblIY;
    }
    else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIY;
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }

    ((IEcoCalculatorY*)*ppv)->pVTbl->AddRef((IEcoCalculatorY*)pCMe);
    return ERR_ECO_SUCCESES;
}

/* AddRef */
uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_AddRef(IEcoCalculatorYPtr_t me) {
    return CEcoLab2_AddRef((IEcoLab2*)me);
}

/* Release */
uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_Release(IEcoCalculatorYPtr_t me) {
    return CEcoLab2_Release((IEcoLab2*)me);
}

/* Multiplication */
int32_t ECOCALLMETHOD CEcoLab2_Multiplication(
    IEcoCalculatorYPtr_t me, int16_t a, int16_t b) {

    return (int32_t)(a * b);
}

/* Division */
int16_t ECOCALLMETHOD CEcoLab2_Division(
    IEcoCalculatorYPtr_t me, int16_t a, int16_t b) {

    if (b == 0) {
        return 0; // или ERR / обработка ошибки
    }

    return (int16_t)(a / b);
}




/* Create Virtual Tables */
IEcoCalculatorXVTbl g_x9322111622484742AE0682819447843DVTblD = {
    CEcoLab2_IEcoCalculatorX_QueryInterface,
    CEcoLab2_IEcoCalculatorX_AddRef,
    CEcoLab2_IEcoCalculatorX_Release,
    CEcoLab2_Addition,
    CEcoLab2_Subtraction
};

IEcoCalculatorYVTbl g_xBD6414C29096423EA90C04D77AFD1CADVTblD = {
    CEcoLab2_IEcoCalculatorY_QueryInterface,
    CEcoLab2_IEcoCalculatorY_AddRef,
    CEcoLab2_IEcoCalculatorY_Release,
    CEcoLab2_Multiplication,
    CEcoLab2_Division
};


/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoLab2(/* in */ IEcoUnknownPtr_t pIUnkSystem, /* in */ IEcoUnknownPtr_t pIUnkOuter, /* out */ IEcoLab2Ptr_t* ppIEcoLab2) {
    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab2* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoLab2 == 0 || pIUnkSystem == 0) {
        return result; /* ERR_ECO_POINTER */
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);
    /* Проверка */
    if (result != 0 || pISys == 0) {
        return ERR_ECO_NOSYSTEM;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    /* Проверка */
    if (result != 0 || pIBus == 0) {
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_NOBUS;
    }
	
	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);
    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab2*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab2));
    if (pCMe == 0) {
        /* Освобождение в случае ошибки */
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_OUTOFMEMORY;
    }
	
    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейсов IEcoLab2 */
    pCme->m_pVTblIX = &g_x9322111622484742AE0682819447843DVTblD;
    pCme->m_pVTblIY = &g_xBD6414C29096423EA90C04D77AFD1CADVTblD;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoLab2 = (IEcoLab2*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return ERR_ECO_SUCCESES;
}

int16_t ECOCALLMETHOD initCEcoLab2(
    /*in*/ IEcoCalculatorXPtr_t me,
    /* in */ IEcoUnknownPtr_t pIUnkSystem) {

    CEcoLab2* pCMe = (CEcoLab2*)me;
    IEcoUnknown* pOuterUnknown = (IEcoUnknown*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = ERR_ECO_POINTER;

    /* Проверка указателей */
    if (me == 0) {
        return result;
    }

    /* Сохранение системного интерфейса */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейсной шины */
    result = pCMe->m_pISys->pVTbl->QueryInterface(
        pCMe->m_pISys,
        &IID_IEcoInterfaceBus1,
        (void**)&pIBus
    );

    if (result != 0 || pIBus == 0) {
        return result;
    }

    /* Включение компонента с интерфейсом X*/
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorB, 0, &IID_IEcoCalculatorX, (void**) &pCMe->m_pIX);
    /* Проверка */
    if (result != 0 || pCMe->m_pIX == 0) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorA, 0, &IID_IEcoCalculatorX, (void**) &pCMe->m_pIX);
    }


    /* Включение компонента с интерфейсом Y*/
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorD, 0, &IID_IEcoCalculatorY, (void**) &pCMe->m_pIY);
    /* Проверка */
    if (result != 0 || pCMe->m_pIX == 0) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorE, 0, &IID_IEcoCalculatorY, (void**) &pCMe->m_pIY);
    }

    /* Получение внутреннего компонента EcoLab1 */
    result = pCMe->m_pISys->pVTbl->QueryComponent(
        pIBus,
        &CID_EcoLab1,
        pOuterUnknown,
        &IID_IEcoUnknown,
        (void**)&pCMe->m_pInnerLab1
    );

    /* Освобождение шины */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

void ECOCALLMETHOD deleteCEcoLab2(
    /* in */ IEcoCalculatorXPtr_t pIEcoLab2) {

    CEcoLab2* pCMe = (CEcoLab2*)pIEcoLab2;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab2 != 0) {
        pIMem = pCMe->m_pIMem;

        /* Освобождение строки */
        if (pCMe->m_Name != 0) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }

        /* Освобождение внутреннего компонента */
        if (pCMe->m_pInnerLab1 != 0) {
            pCMe->m_pInnerLab1->pVTbl->Release(pCMe->m_pInnerLab1);
        }

        /* Освобождение системного интерфейса */
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }

        /* Освобождение самого объекта */
        pIMem->pVTbl->Free(pIMem, pCMe);

        /* Освобождение аллокатора */
        pIMem->pVTbl->Release(pIMem);
    }
}
