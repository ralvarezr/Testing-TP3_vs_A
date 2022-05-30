#include "build/test/mocks/mock_errores.h"
#include "src/leds.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static uint16_t ledsVirtuales;





void setUp(void)

{

        LedsInit(&ledsVirtuales);

}





void tearDown(void)

{



}





void test_LedsOffAfterCreate(void)

{

        uint16_t ledsVirtuales = 0xFFFF;

        LedsInit(&ledsVirtuales);



        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0X0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnOneLed(void)

{

        LedTurnOn(5);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffOneLed(void)

{



        LedTurnOn(5);

        LedTurnOff(5);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnAndOffManyLeds(void)

{

        LedTurnOn(5);

        LedTurnOn(5);

        LedTurnOn(11);

        LedTurnOff(3);

        LedTurnOff(11);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_HEX16);

}





void test_InvalidUpperLimitTurnOnLed(void)

{

        RegistrarMensaje_CMockExpect(72, ALERTA, "LedTurnOn", 0, "Numero de led invalido");

        RegistrarMensaje_CMockIgnoreArg_linea(73);

        LedTurnOn(17);

}



void test_InvalidLowerLimitTurnOnLed(void)

{

        RegistrarMensaje_CMockExpect(79, ALERTA, "LedTurnOn", 0, "Numero de led invalido");

        RegistrarMensaje_CMockIgnoreArg_linea(80);

        LedTurnOn(0);

}



void test_InvalidUpperLimitTurnOffLed(void)

{

        RegistrarMensaje_CMockExpect(86, ALERTA, "LedTurnOff", 0, "Numero de led invalido");

        RegistrarMensaje_CMockIgnoreArg_linea(87);

        LedTurnOff(17);

}



void test_InvalidLowerLimitTurnOffLed(void)

{

        RegistrarMensaje_CMockExpect(93, ALERTA, "LedTurnOff", 0, "Numero de led invalido");

        RegistrarMensaje_CMockIgnoreArg_linea(94);

        LedTurnOff(0);

}





void test_TurnOnAllLeds(void)

{

        LedsAllTurnOn();

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffAllLeds(void)

{

        LedsAllTurnOff();

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

       ((void *)0)

       ), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_HEX16);



}





void test_GetLedOnState(void)

{

        LedTurnOff(16);

        LedTurnOn(16);

        LedTurnOn(7);

        LedTurnOn(15);

        LedTurnOn(1);

        do {if ((GetLedState(16))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(121)));}} while(0);

}







void test_GetLedOffState(void)

{

        LedTurnOn(16);

        LedTurnOn(7);

        LedTurnOn(15);

        LedTurnOn(1);

        LedTurnOff(16);

        do {if (!(GetLedState(16))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(133)));}} while(0);

}
