
#include "config.h"
// =============================================================================
void taskHeartBeat( void ) {
    utils.togglePin( GPIOD, 4 );
}

// ============================================================================
int main( void ) {
    utils.initSystemClock();
    utils.initNvic( 4 );
    utils.setPinMode( GPIOD, 4, GPIO_MODE_OUTPUT_PP );
    stime.config();
    stime.scheduler.config();
    console.config( 921600, 8, 'n', 1 );
    console.printf( "\r\n\r\n" );
    stime.scheduler.regist( 200, 2, taskHeartBeat, "taskHeartBeat" );
    // also try _1_TICK, _2_TICK and _3_TICK
    stime.scheduler.show();

    while ( 1 ) {
        console.cliProcess();
        stime.scheduler.process();
    }
    return 0;
}
