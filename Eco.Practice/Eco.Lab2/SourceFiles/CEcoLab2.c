/*
 * CEcoLab2 implementation
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "IdEcoCalculatorA.h"
#include "IdEcoCalculatorB.h"
#include "IdEcoCalculatorD.h"
#include "IdEcoCalculatorE.h"
#include "IdEcoLab1.h"
#include "CEcoLab2.h"

#include <stdio.h>

static uint32_t ECOCALLMETHOD CEcoLab2_AddRef(/* in */ IEcoCalculatorXPtr_t me);
static uint32_t ECOCALLMETHOD CEcoLab2_Release(/* in */ IEcoCalculatorXPtr_t me);

/* IEcoCalculatorX */
int16_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_QueryInterface(
    IEcoCalculatorXPtr_t me, const UGUID* riid, void** ppv) {

    CEcoLab2* pCMe = (CEcoLab2*)me;

    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    if (IsEqualUGUID(riid, &IID_IEcoCalculatorX) || IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIX;
    }
    else if (IsEqualUGUID(riid, &IID_IEcoCalculatorY)) {
        *ppv = &pCMe->m_pVTblIY;
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        int16_t result = ERR_ECO_NOINTERFACE;
        if (pCMe->m_pInnerLab1 != 0) {
            /* Запрашиваем интерфейс IEcoCalculatorX внутреннего компонента */
            result = pCMe->m_pInnerLab1->pVTbl->QueryInterface(pCMe->m_pInnerLab1, riid, ppv);
        }
        return result;
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }

    CEcoLab2_AddRef((IEcoCalculatorXPtr_t)pCMe);
    return ERR_ECO_SUCCESES;
}

uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_AddRef(IEcoCalculatorXPtr_t me) {
    return CEcoLab2_AddRef(me);
}

uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorX_Release(IEcoCalculatorXPtr_t me) {
    return CEcoLab2_Release(me);
}

int32_t ECOCALLMETHOD CEcoLab2_Addition(IEcoCalculatorXPtr_t me, int16_t a, int16_t b) {
    CEcoLab2* pCMe = (CEcoLab2*)me;

    if (pCMe == 0 || pCMe->m_pIX == 0) {
        return -1;
    }
    
    return pCMe->m_pIX->pVTbl->Addition(pCMe->m_pIX, a, b);
}

int16_t ECOCALLMETHOD CEcoLab2_Subtraction(IEcoCalculatorXPtr_t me, int16_t a, int16_t b) {
    CEcoLab2* pCMe = (CEcoLab2*)me;

    if (pCMe == 0 || pCMe->m_pIX == 0) {
        return -1;
    }
    
    return pCMe->m_pIX->pVTbl->Subtraction(pCMe->m_pIX, a, b);
}

/* IEcoCalculatorY */
int16_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_QueryInterface(
    IEcoCalculatorYPtr_t me, const UGUID* riid, void** ppv) {

    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - sizeof(IEcoCalculatorXVTbl*));

    if (me == 0 || ppv == 0) {
        return ERR_ECO_POINTER;
    }

    if (IsEqualUGUID(riid, &IID_IEcoCalculatorY) || IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIY;
    }
    else if (IsEqualUGUID(riid, &IID_IEcoCalculatorX)) {
        *ppv = &pCMe->m_pVTblIX;
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        int16_t result = ERR_ECO_NOINTERFACE;
        if (pCMe->m_pInnerLab1 != 0) {
            /* Запрашиваем интерфейс IEcoCalculatorX внутреннего компонента */
            result = pCMe->m_pInnerLab1->pVTbl->QueryInterface(pCMe->m_pInnerLab1, riid, ppv);
        }
        return result;
    }
    else {
        *ppv = 0;
        return ERR_ECO_NOINTERFACE;
    }

    CEcoLab2_AddRef((IEcoCalculatorXPtr_t)pCMe);
    return ERR_ECO_SUCCESES;
}

uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_AddRef(IEcoCalculatorYPtr_t me) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - sizeof(IEcoCalculatorXVTbl*));
    return CEcoLab2_AddRef((IEcoCalculatorXPtr_t)pCMe);
}

uint32_t ECOCALLMETHOD CEcoLab2_IEcoCalculatorY_Release(IEcoCalculatorYPtr_t me) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - sizeof(IEcoCalculatorXVTbl*));
    return CEcoLab2_Release((IEcoCalculatorXPtr_t)pCMe);
}

int32_t ECOCALLMETHOD CEcoLab2_Multiplication(IEcoCalculatorYPtr_t me, int16_t a, int16_t b) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - sizeof(IEcoCalculatorXVTbl*));
    return pCMe->m_pIY->pVTbl->Multiplication(pCMe->m_pIY, a, b);
}

int16_t ECOCALLMETHOD CEcoLab2_Division(IEcoCalculatorYPtr_t me, int16_t a, int16_t b) {
    CEcoLab2* pCMe = (CEcoLab2*)((uint64_t)me - sizeof(IEcoCalculatorXVTbl*));
    return pCMe->m_pIY->pVTbl->Division(pCMe->m_pIY, a, b);
}

IEcoCalculatorXVTbl g_x9322111622484742AE0682819447843DVTblEcoLab2 = {
    CEcoLab2_IEcoCalculatorX_QueryInterface,
    CEcoLab2_IEcoCalculatorX_AddRef,
    CEcoLab2_IEcoCalculatorX_Release,
    CEcoLab2_Addition,
    CEcoLab2_Subtraction
};

IEcoCalculatorYVTbl g_xBD6414C29096423EA90C04D77AFD1CADVTblEcoLab2 = {
    CEcoLab2_IEcoCalculatorY_QueryInterface,
    CEcoLab2_IEcoCalculatorY_AddRef,
    CEcoLab2_IEcoCalculatorY_Release,
    CEcoLab2_Multiplication,
    CEcoLab2_Division
};

static uint32_t ECOCALLMETHOD CEcoLab2_AddRef(/* in */ IEcoCalculatorXPtr_t me) {
    CEcoLab2* pCMe = (CEcoLab2*)me;

    if (me == 0) {
        return (uint32_t)-1;
    }

    return ++pCMe->m_cRef;
}

static uint32_t ECOCALLMETHOD CEcoLab2_Release(/* in */ IEcoCalculatorXPtr_t me) {
    CEcoLab2* pCMe = (CEcoLab2*)me;

    if (me == 0) {
        return (uint32_t)-1;
    }

    --pCMe->m_cRef;
    if (pCMe->m_cRef == 0) {
        deleteCEcoLab2((IEcoCalculatorXPtr_t)pCMe);
        return 0;
    }

    return pCMe->m_cRef;
}

int16_t ECOCALLMETHOD createCEcoLab2(
    /* in */ IEcoUnknownPtr_t pIUnkSystem,
    /* in */ IEcoUnknownPtr_t pIUnkOuter,
    /* out */ IEcoCalculatorXPtr_t* ppIEcoLab2) {

    int16_t result = ERR_ECO_POINTER;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab2* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;

    (void)pIUnkOuter;

    if (ppIEcoLab2 == 0 || pIUnkSystem == 0) {
        return result;
    }

    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem, (void**)&pISys);
    if (result != 0 || pISys == 0) {
        return ERR_ECO_NOSYSTEM;
    }

    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);
    if (result != 0 || pIBus == 0) {
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_NOBUS;
    }

    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**)&pIMem);
    if (result != 0 || pIMem == 0) {
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_GET_MEMORY_ALLOCATOR;
    }

    pCMe = (CEcoLab2*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab2));
    if (pCMe == 0) {
        pIMem->pVTbl->Release(pIMem);
        pIBus->pVTbl->Release(pIBus);
        pISys->pVTbl->Release(pISys);
        return ERR_ECO_OUTOFMEMORY;
    }

    pCMe->m_pVTblIX = &g_x9322111622484742AE0682819447843DVTblEcoLab2;
    pCMe->m_pVTblIY = &g_xBD6414C29096423EA90C04D77AFD1CADVTblEcoLab2;
    pCMe->m_cRef = 1;
    pCMe->m_pIMem = pIMem;
    pCMe->m_pISys = pISys;
    pCMe->m_Name = 0;
    pCMe->m_pIX = 0;
    pCMe->m_pIY = 0;
    pCMe->m_pInnerLab1 = 0;

    *ppIEcoLab2 = (IEcoCalculatorXPtr_t)pCMe;

    pIBus->pVTbl->Release(pIBus);
    return ERR_ECO_SUCCESES;
}

int16_t ECOCALLMETHOD initCEcoLab2(/*in*/ IEcoCalculatorXPtr_t me, /* in */ IEcoUnknownPtr_t pIUnkSystem) {
    CEcoLab2* pCMe = (CEcoLab2*)me;
    IEcoUnknown* pOuterUnknown = (IEcoUnknown*)pCMe;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = ERR_ECO_POINTER;
    int16_t resultX = ERR_ECO_NOINTERFACE;
    int16_t resultY = ERR_ECO_NOINTERFACE;
    int16_t resultLab1 = ERR_ECO_NOINTERFACE;

    if (me == 0 || pIUnkSystem == 0) {
        return result;
    }

    printf("CEcoLab2: initialization started\n");

    result = pCMe->m_pISys->pVTbl->QueryInterface(
        pCMe->m_pISys,
        &IID_IEcoInterfaceBus1,
        (void**)&pIBus);
    if (result != 0 || pIBus == 0) {
        printf("CEcoLab2: failed to get IEcoInterfaceBus1\n");
        return result;
    }

    /* Получение IEcoCalculatorX */
    resultX = pIBus->pVTbl->QueryComponent(
        pIBus,
        &CID_EcoCalculatorB,
        0,
        &IID_IEcoCalculatorX,
        (void**)&pCMe->m_pIX);

    if (resultX == 0 && pCMe->m_pIX != 0) {
        printf("CEcoLab2: IEcoCalculatorX obtained from EcoCalculatorB\n");
    } else {
        resultX = pIBus->pVTbl->QueryComponent(
            pIBus,
            &CID_EcoCalculatorA,
            0,
            &IID_IEcoCalculatorX,
            (void**)&pCMe->m_pIX);

        if (resultX == 0 && pCMe->m_pIX != 0) {
            printf("CEcoLab2: IEcoCalculatorX obtained from EcoCalculatorA\n");
        } else {
            printf("CEcoLab2: failed to obtain IEcoCalculatorX\n");
        }
    }

    /* Получение IEcoCalculatorY */
    resultY = pIBus->pVTbl->QueryComponent(
        pIBus,
        &CID_EcoCalculatorD,
        0,
        &IID_IEcoCalculatorY,
        (void**)&pCMe->m_pIY);

    if (resultY == 0 && pCMe->m_pIY != 0) {
        printf("CEcoLab2: IEcoCalculatorY obtained from EcoCalculatorD\n");
    } else {
        resultY = pIBus->pVTbl->QueryComponent(
            pIBus,
            &CID_EcoCalculatorE,
            0,
            &IID_IEcoCalculatorY,
            (void**)&pCMe->m_pIY);

        if (resultY == 0 && pCMe->m_pIY != 0) {
            printf("CEcoLab2: IEcoCalculatorY obtained from EcoCalculatorE\n");
        } else {
            printf("CEcoLab2: failed to obtain IEcoCalculatorY\n");
        }
    }

    /* Агрегация EcoLab1 */
    resultLab1 = pIBus->pVTbl->QueryComponent(
        pIBus,
        &CID_EcoLab1,
        pOuterUnknown,
        &IID_IEcoUnknown,
        (void**)&pCMe->m_pInnerLab1);

    if (resultLab1 == 0 && pCMe->m_pInnerLab1 != 0) {
        printf("CEcoLab2: EcoLab1 successfully aggregated (inner component)\n");
    } else {
        printf("CEcoLab2: failed to aggregate EcoLab1\n");
    }

    pIBus->pVTbl->Release(pIBus);

    printf("CEcoLab2: initialization finished\n");

    if (resultX != 0) {
        return resultX;
    }
    if (resultY != 0) {
        return resultY;
    }
    if (resultLab1 != 0) {
        return resultLab1;
    }

    return ERR_ECO_SUCCESES;
}

void ECOCALLMETHOD deleteCEcoLab2(/* in */ IEcoCalculatorXPtr_t pIEcoLab2) {
    CEcoLab2* pCMe = (CEcoLab2*)pIEcoLab2;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab2 == 0) {
        return;
    }

    pIMem = pCMe->m_pIMem;

    if (pCMe->m_Name != 0) {
        pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
    }

    if (pCMe->m_pIX != 0) {
        pCMe->m_pIX->pVTbl->Release(pCMe->m_pIX);
    }

    if (pCMe->m_pIY != 0) {
        pCMe->m_pIY->pVTbl->Release(pCMe->m_pIY);
    }

    if (pCMe->m_pInnerLab1 != 0) {
        pCMe->m_pInnerLab1->pVTbl->Release(pCMe->m_pInnerLab1);
    }

    if (pCMe->m_pISys != 0) {
        pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
    }

    pIMem->pVTbl->Free(pIMem, pCMe);
    pIMem->pVTbl->Release(pIMem);
}
