#include "contiki.h"
#include <stdio.h> /* For printf() */

/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/

PROCESS_THREAD(hello_world_process, ev, data)
{
  static struct etimer timer;

  PROCESS_BEGIN();

  /* Setup a periodic timer that expires after 60 seconds. */
  etimer_set(&timer, CLOCK_SECOND * 60);

  while(1) {
    printf("Dummy node is ON!\n");

    /* Wait for the periodic timer to expire and then restart the timer. */
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    etimer_reset(&timer);
  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
