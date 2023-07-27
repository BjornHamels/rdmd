#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"


#include "include/max7219.h"
#include "include/rdmdlogo.h"
#include "include/bininfo.h"




int main()
{
    stdio_init_all();

    // Init max and display the version for 2 seconds.
    init_7segd();
    show_7segd(atoi(VBUILDTS));
    sleep_ms(2000);
    clear_7segd();

    // Some art.
    printf(rDMDLines);
    printf("\nrDMD Version %s. See https://github.com/BjornHamels/rdmd\n\n", VBUILDTS);




    int j = 0;

    while (true) {
        show_7segd(j++);
        if (j > 99999999) {
            j = 0;
        }
    }

    
}
