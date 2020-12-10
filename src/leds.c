#include "leds.h"

#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON  0b1111111111111111

#define LED_OFFSET   1
#define LSB          1

#define LedToMask( led )  ( LSB << ( led - LED_OFFSET ) )

static uint16_t *direccion;


void Leds_Create( uint16_t *puerto )
{
    direccion = puerto;
    *direccion = LEDS_ALL_OFF;
}

void Leds_On( uint8_t led )
{
    *direccion |= LedToMask(led);
}

void Leds_Off( uint8_t led )
{
    *direccion &= ~LedToMask(led);
}

void Leds_OnAll( void )
{
    *direccion = LEDS_ALL_ON;
}

void Leds_OffAll( void )
{
    *direccion = LEDS_ALL_OFF;
}

bool Leds_getEstado( uint8_t led )
{
    return ( ( *direccion & LedToMask( led ) ) );
}