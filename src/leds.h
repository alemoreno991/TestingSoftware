#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Constructor
 * 
 * @param puerto Indica el puerto con el que se desea trabajar
 */
void Leds_Create( uint16_t *puerto );

/**
 * @brief Enciende el \p led 
 * 
 * @param led Led que se desea encender
 */
void Leds_On( uint8_t led );

/**
 * @brief Apaga el \p led
 * 
 * @param led Led que se desea apagar
 */
void Leds_Off( uint8_t led );

/**
 * @brief Prende todos los led al mismo tiempo
 * 
 */
void Leds_OnAll( void );

/**
 * @brief Apaga todos los led al mismo tiempo
 * 
 */
void Leds_OffAll( void );

/**
 * @brief Permite obtener el estado de el \p led
 * 
 * @param led Led que se desea conocer su estado
 * @return true     Prendido
 * @return false    Apagado
 */
bool Leds_getEstado( uint8_t led );