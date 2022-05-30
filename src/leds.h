#ifndef _LEDS_H
#define _LEDS_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Configura la biblioteca y apaga los leds.
 * 
 * @param direccion Dirección de puerto GPIO.
 */
void LedsInit(uint16_t * direccion);

/**
 * @brief Enciende un led
 * 
 * @param led Número de led a encender (1 al 16).
 */
void LedTurnOn(uint8_t led);

/**
 * @brief Apaga un led.
 *
 * @param led Número de led a apagar (1 al 16).
 */
void LedTurnOff(uint8_t led);

/**
 * @brief Enciende todos los leds.
 * 
 */
void LedsAllTurnOn(void);

/**
 * @brief Apaga todos los leds.
 *
 */
void LedsAllTurnOff(void);

/**
 * @brief Devuelve el estado de un led.
 * 
 * @param led Número de led a consultar (1 al 16).
 * @return true Si está encendido.
 * @return false Si está apagado.
 */
bool GetLedState(uint8_t led);

#endif //_LEDS_H