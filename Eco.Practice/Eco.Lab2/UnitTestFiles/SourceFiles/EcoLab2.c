/*
 * EcoLab2 unit test entrypoint
 */

#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"

#include "IEcoLab1.h"
#include "IEcoCalculatorX.h"
#include "IEcoCalculatorY.h"

#include "IdEcoLab1.h"
#include "IdEcoCalculatorA.h"
#include "IdEcoCalculatorB.h"
#include "IdEcoCalculatorD.h"
#include "IdEcoCalculatorE.h"

/* EcoLab2 CID = {F87CD666-E631-4B33-B2B4-508FDCD4BE15} */
static const UGUID CID_EcoLab2 = {
    0x01,
    0x10,
    {0xF8, 0x7C, 0xD6, 0x66, 0xE6, 0x31, 0x4B, 0x33, 0xB2, 0xB4, 0x50, 0x8F, 0xDC, 0xD4, 0xBE, 0x15}
};

#ifdef ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_F87CD666E6314B33B2B4508FDCD4BE15;
#endif

int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = ERR_ECO_POINTER;

    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;

    IEcoCalculatorX* pICalcX = 0;
    IEcoCalculatorY* pICalcY = 0;
    IEcoLab1* pIEcoLab1 = 0;

    IEcoCalculatorX* pICalcX_FromY = 0;
    IEcoCalculatorY* pICalcY_FromX = 0;
    IEcoLab1* pILab1_FromX = 0;
    IEcoLab1* pILab1_FromY = 0;
    IEcoCalculatorX* pICalcX_FromLab1 = 0;
    IEcoCalculatorY* pICalcY_FromLab1 = 0;
    IEcoUnknown* pIUnk_FromX = 0;
    IEcoUnknown* pIUnk_FromY = 0;
    IEcoUnknown* pIUnk_FromLab1 = 0;

    if (pIUnk == 0) {
        return ERR_ECO_POINTER;
    }

    result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem, (void**)&pISys);
    if (result != 0 || pISys == 0) {
        goto Release;
    }

    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void**)&pIBus);
    if (result != 0 || pIBus == 0) {
        goto Release;
    }

#ifdef ECO_LIB
    /* Register component under test and dependencies used by EcoLab2 */
    result = pIBus->pVTbl->RegisterComponent(
        pIBus,
        &CID_EcoLab2,
        (IEcoUnknown*)GetIEcoComponentFactoryPtr_F87CD666E6314B33B2B4508FDCD4BE15);
    if (result != 0) {
        goto Release;
    }

    result = pIBus->pVTbl->RegisterComponent(
        pIBus,
        &CID_EcoLab1,
        (IEcoUnknown*)GetIEcoComponentFactoryPtr_1F5DF16EE1BF43B999A434ED38FE8F3A);
    if (result != 0) {
        goto Release;
    }

    result = pIBus->pVTbl->RegisterComponent(
        pIBus,
        &CID_EcoCalculatorA,
        (IEcoUnknown*)GetIEcoComponentFactoryPtr_4828F6552E4540E78121EBD220DC360E);
    if (result != 0) {
        goto Release;
    }

    result = pIBus->pVTbl->RegisterComponent(
        pIBus,
        &CID_EcoCalculatorB,
        (IEcoUnknown*)GetIEcoComponentFactoryPtr_AE202E543CE54550899603BD70C62565);
    if (result != 0) {
        goto Release;
    }

    result = pIBus->pVTbl->RegisterComponent(
        pIBus,
        &CID_EcoCalculatorD,
        (IEcoUnknown*)GetIEcoComponentFactoryPtr_3A8E44677E82475CB4A3719ED8397E61);
    if (result != 0) {
        goto Release;
    }

    result = pIBus->pVTbl->RegisterComponent(
        pIBus,
        &CID_EcoCalculatorE,
        (IEcoUnknown*)GetIEcoComponentFactoryPtr_872FEF1DE3314B87AD44D1E7C232C2F0);
    if (result != 0) {
        goto Release;
    }
#endif

    /* 1) Create EcoLab2 and obtain all primary interfaces */
    result = pIBus->pVTbl->QueryComponent(
        pIBus,
        &CID_EcoLab2,
        0,
        &IID_IEcoCalculatorX,
        (void**)&pICalcX);
    if (result != 0 || pICalcX == 0) {
        goto Release;
    }

    result = pIBus->pVTbl->QueryComponent(
        pIBus,
        &CID_EcoLab2,
        0,
        &IID_IEcoCalculatorY,
        (void**)&pICalcY);
    if (result != 0 || pICalcY == 0) {
        goto Release;
    }

    result = pIBus->pVTbl->QueryComponent(
        pIBus,
        &CID_EcoLab2,
        0,
        &IID_IEcoLab1,
        (void**)&pIEcoLab1);
    if (result != 0 || pIEcoLab1 == 0) {
        goto Release;
    }

    /* 2) Try obtaining other interfaces from each interface pointer */
    (void)pICalcX->pVTbl->QueryInterface(pICalcX, &IID_IEcoCalculatorY, (void**)&pICalcY_FromX);
    (void)pICalcX->pVTbl->QueryInterface(pICalcX, &IID_IEcoLab1, (void**)&pILab1_FromX);
    (void)pICalcX->pVTbl->QueryInterface(pICalcX, &IID_IEcoUnknown, (void**)&pIUnk_FromX);

    (void)pICalcY->pVTbl->QueryInterface(pICalcY, &IID_IEcoCalculatorX, (void**)&pICalcX_FromY);
    (void)pICalcY->pVTbl->QueryInterface(pICalcY, &IID_IEcoLab1, (void**)&pILab1_FromY);
    (void)pICalcY->pVTbl->QueryInterface(pICalcY, &IID_IEcoUnknown, (void**)&pIUnk_FromY);

    (void)pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void**)&pICalcX_FromLab1);
    (void)pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, (void**)&pICalcY_FromLab1);
    (void)pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoUnknown, (void**)&pIUnk_FromLab1);

    /* Smoke usage */
    (void)pICalcX->pVTbl->Addition(pICalcX, 2, 3);
    (void)pICalcY->pVTbl->Multiplication(pICalcY, 4, 5);

    result = ERR_ECO_SUCCESES;

Release:
    if (pIUnk_FromLab1 != 0) {
        pIUnk_FromLab1->pVTbl->Release(pIUnk_FromLab1);
    }
    if (pIUnk_FromY != 0) {
        pIUnk_FromY->pVTbl->Release(pIUnk_FromY);
    }
    if (pIUnk_FromX != 0) {
        pIUnk_FromX->pVTbl->Release(pIUnk_FromX);
    }

    if (pICalcY_FromLab1 != 0) {
        pICalcY_FromLab1->pVTbl->Release(pICalcY_FromLab1);
    }
    if (pICalcX_FromLab1 != 0) {
        pICalcX_FromLab1->pVTbl->Release(pICalcX_FromLab1);
    }

    if (pILab1_FromY != 0) {
        pILab1_FromY->pVTbl->Release(pILab1_FromY);
    }
    if (pILab1_FromX != 0) {
        pILab1_FromX->pVTbl->Release(pILab1_FromX);
    }

    if (pICalcX_FromY != 0) {
        pICalcX_FromY->pVTbl->Release(pICalcX_FromY);
    }
    if (pICalcY_FromX != 0) {
        pICalcY_FromX->pVTbl->Release(pICalcY_FromX);
    }

    if (pIEcoLab1 != 0) {
        pIEcoLab1->pVTbl->Release(pIEcoLab1);
    }
    if (pICalcY != 0) {
        pICalcY->pVTbl->Release(pICalcY);
    }
    if (pICalcX != 0) {
        pICalcX->pVTbl->Release(pICalcX);
    }

    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}
