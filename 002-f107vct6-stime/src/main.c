
#include "config.h"

// ============================================================================
int main( void ) {
    utils.initSystemClock();
    utils.initNvic( 4 );
    utils.setPinMode( GPIOC, 6, GPIO_MODE_OUTPUT_PP );
    stime.config();

    while ( 1 ) {
        ;
    }
}
