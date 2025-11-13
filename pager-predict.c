#include <stdio.h> 
#include <stdlib.h>

#include "simulator.h"

void pageit(Pentry q[MAXPROCESSES]) { 
    
    /* This file contains the stub for a predictive pager */
    /* You may need to add/remove/modify any part of this file */

    /* Static vars */
    static int initialized = 0;
    static int tick = 1; // artificial time
    
    /* Local vars */
    static int timestamps[MAXPROCESSES][MAXPROCPAGES];

    /* initialize static vars on first run */
 //    if(!initialized){
	// /* Init complex static vars here */
	// initialized = 1;
 //    }

    if (!initialized) {
		for (int proc=0; proc < MAXPROCESSES; proc++) {
			for (page=0; page < MAXPROCPAGES; page++) {
				timestamps[proc][page] = 0;
			}
		}
		initialized = 1;
	}
    
    /* TODO: Implement Predictive Paging */
    //fprintf(stderr, "pager-predict not yet implemented. Exiting...\n");
    //exit(EXIT_FAILURE);

    for (int proc = 0; proc < MAXPROCESSES; proc++) {

		int pc = q[proc].pc;
		int page = pc/PAGESIZE;

		if (q[proc].pages[page]) { break; }
		if (pagein(proc, page)) {
			timestamps[proc][page] = tick;
			break;
		}

		int lru = 0;
		for (int i = 0; i < MAXPROCPAGES; i++) {
			if (q[proc].pages[i] == page) { break; }
			if (q[proc].pages[i] == 0) { break; }

			if (timestamps[proc][i] < timestamps[proc][lru]) {
				lru = i;
			}
		}

		pageout(proc, lru);

	}


    /* advance time for next pageit iteration */
    tick++;
} 
