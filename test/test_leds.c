#include "unity.h"
#include "leds.h"

static uint16_t ledsVirtuales;

void setUp( void )
{
    Leds_Create( &ledsVirtuales );
}

void tearDown( void )
{

}

/**
 * @brief Despues de la inicialización todos los LEDs deben quedar apagados
 * 
 */
void test_LedsOffAfterCreate( void )
{
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create( &ledsVirtuales );
    TEST_ASSERT_EQUAL_HEX16( 0, ledsVirtuales );
}

/**
 * @brief Se puede prender un LED individual
 * 
 */
void test_PrenderLedIndividual( void )
{
    Leds_On( 1 );
    TEST_ASSERT_EQUAL_HEX16( 1, ledsVirtuales );
}

/**
 * @brief Se puede apagar un LED individual
 * 
 */
void test_ApagarLedIndividual( void )
{
    Leds_On( 1 );
    Leds_Off( 1 );
    TEST_ASSERT_EQUAL_HEX16( 0, ledsVirtuales );
}

/**
 * @brief Se puede prender y apagar multiples LEDs
 * 
 */
void test_PrenderApagarMultiplesLeds( void )
{
    Leds_On( 3 );
    Leds_On( 4 );
    Leds_Off( 3 );
    TEST_ASSERT_EQUAL_HEX16( (1 << 3), ledsVirtuales );
}

/**
 * @brief Se puede prender todos los LEDs de una vez
 * 
 */
void test_PrenderTodosLeds( void )
{
    Leds_OnAll();
    TEST_ASSERT_EQUAL_HEX16( 0b1111111111111111, ledsVirtuales );
}

/**
 * @brief Se puede apagar todos los LEDs de una vez
 * 
 */
void test_ApagarTodosLeds( void )
{
    Leds_OffAll();
    TEST_ASSERT_EQUAL_HEX16( 0, ledsVirtuales );
}

/**
 * @brief Se puede consultar el estado de un LED
 * 
 */
void test_ConsultarEstadoLed( void )
{
    Leds_Off( 3 );
    TEST_ASSERT( false == Leds_getEstado( 3 ) );

    Leds_On( 3 );
    TEST_ASSERT( true == Leds_getEstado( 3 ) );
}