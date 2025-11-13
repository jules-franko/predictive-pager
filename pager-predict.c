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
    

    /* initialize static vars on first run */
    if(!initialized){
	/* Init complex static vars here */
	
	initialized = 1;
    }
    
    /* TODO: Implement Predictive Paging */
    //fprintf(stderr, "pager-predict not yet implemented. Exiting...\n");
    //exit(EXIT_FAILURE);

	//My Implementation Starts Here LRU Pager
    for (int proc = 0; proc < MAXPROCESSES; proc++) {
		
		int pc = q[proc].pc;
		int page = pc/PAGE_SIZE;

		if (q[proc].pages[page]) {
				//Page is in!
				break;
		}
		if (pagein(q[proc], page)) {
				//Swapped in success
				break;
		}

		//Evict a page
		for (int i = 0; i < MAXPROCPAGES; i++) {
			if (q[proc].pages[i] == page) {
				break;
			}
			if (q[proc].pages[i] == 0) {
				break;
			}

			pageout(q[proc], i);
		}
	}

    /* advance time for next pageit iteration */
    tick++;
} 
