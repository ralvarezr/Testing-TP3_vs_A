#include "leds.h"
#include "errores.h"

#define LEDS_ALL_OFF    0
#define LED_TO_BIT      1
#define LED_SET_BIT     1
#define MASK_LSB        0X0001

static uint16_t *puerto;

static uint16_t SetBitLed(uint8_t led)
{
        return (LED_SET_BIT << (led - LED_TO_BIT));
}

void LedsInit(uint16_t *direccion)
{       
        puerto = direccion;
        *puerto = LEDS_ALL_OFF;
}

void LedTurnOn(uint8_t led)
{
        if(led > 16 || led <= 0)
        {
                Alerta("Numero de led invalido");
        }else
        {
                *puerto |= SetBitLed(led);
        }
}

void LedTurnOff(uint8_t led)
{

        if (led > 16 || led <= 0)
        {
                Alerta("Numero de led invalido");
        }
        else
        {
                *puerto &= ~(SetBitLed(led));
        }
       
}

void LedsAllTurnOn(void)
{
        *puerto = 0xFFFF;
}

void LedsAllTurnOff(void)
{
        *puerto = 0x0000;
}

bool GetLedState(uint8_t led)
{
        return (*puerto >> (led - LED_TO_BIT) & MASK_LSB);
}