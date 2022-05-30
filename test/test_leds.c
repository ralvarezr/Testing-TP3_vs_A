#include "unity.h"
#include "leds.h"
#include "mock_errores.h"

static uint16_t ledsVirtuales;

//Funcion que se ejecuta al entrar a un test.
void setUp(void)
{
        LedsInit(&ledsVirtuales);
}


// Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void)
{
        uint16_t ledsVirtuales = 0xFFFF;                
        LedsInit(&ledsVirtuales);                       
                                                        
        TEST_ASSERT_EQUAL_HEX16(0X0000, ledsVirtuales);
}

// Se puede prender un LED individual.
void test_TurnOnOneLed(void)
{
        LedTurnOn(5);
        TEST_ASSERT_EQUAL_HEX16(1 << 4, ledsVirtuales); 
}

// Se puede apagar un LED individual.
void test_TurnOffOneLed(void)
{       
        LedTurnOn(5);
        LedTurnOff(5);
        TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales); 
}

// Se pueden prender y apagar múltiples LEDs.
void test_TurnOnAndOffManyLeds(void)
{
        LedTurnOn(5);           
        LedTurnOn(5);           
        LedTurnOn(11);          
        LedTurnOff(3);          
        LedTurnOff(11);         
        TEST_ASSERT_EQUAL_HEX16(1 << 4, ledsVirtuales); 
}

//Revisar limites de los parametros.
void test_InvalidUpperLimitTurnOnLed(void)
{
        RegistrarMensaje_Expect(ALERTA, "LedTurnOn", 0, "Numero de led invalido");
        RegistrarMensaje_IgnoreArg_linea();
        LedTurnOn(17);
}

void test_InvalidLowerLimitTurnOnLed(void)
{
        RegistrarMensaje_Expect(ALERTA, "LedTurnOn", 0, "Numero de led invalido");
        RegistrarMensaje_IgnoreArg_linea();
        LedTurnOn(0);
}

void test_InvalidUpperLimitTurnOffLed(void)
{
        RegistrarMensaje_Expect(ALERTA, "LedTurnOff", 0, "Numero de led invalido");
        RegistrarMensaje_IgnoreArg_linea();
        LedTurnOff(17);
}

void test_InvalidLowerLimitTurnOffLed(void)
{
        RegistrarMensaje_Expect(ALERTA, "LedTurnOff", 0, "Numero de led invalido");
        RegistrarMensaje_IgnoreArg_linea();
        LedTurnOff(0);
}

// Se pueden prender todos los LEDs de una vez.
void test_TurnOnAllLeds(void)
{
        LedsAllTurnOn();
        TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

// Se pueden apagar todos los LEDs de una vez.
void test_TurnOffAllLeds(void)
{
        LedsAllTurnOff();
        TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);

}

// Se puede consultar el estado de un LED encendido.
void test_GetLedOnState(void)
{
        LedTurnOff(16);
        LedTurnOn(16);
        LedTurnOn(7);
        LedTurnOn(15);
        LedTurnOn(1);
        TEST_ASSERT_TRUE(GetLedState(16));
}

// Se puede consultar el estado de un LED apagado.
void test_GetLedOffState(void)
{
        LedTurnOn(16);
        LedTurnOn(7);
        LedTurnOn(15);
        LedTurnOn(1);
        LedTurnOff(16);
        TEST_ASSERT_FALSE(GetLedState(16));
}
