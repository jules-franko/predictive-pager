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
			for (int page=0; page < MAXPROCPAGES; page++) {
				timestamps[proc][page] = 0;
			}
		}
		initialized = 1;
	}
    
    /* TODO: Implement Predictive Paging */
    //fprintf(stderr, "pager-predict not yet implemented. Exiting...\n");
    //exit(EXIT_FAILURE);

	for (int proc = 0; proc < MAXPROCESSES; proc++) {

		if (!q[proc].active) continue;

		int pc = q[proc].pc;
		int page = pc/PAGESIZE;

		timestamps[proc][page] = tick;

		if (q[proc].pages[page]) { continue; }
		if (pagein(proc, page)) {
			continue;
		}

		int lru_proc = 0;
		int lru = tick;
		for (int j = 0; j < MAXPROCESSES; j++) {

			if (!q[j].active) { continue; }

			for (int i = 0; i < MAXPROCPAGES; i++) {
				if (q[j].pages[i] == page) { continue; }
				if (q[j].pages[i] == 0) { continue; }

				if (timestamps[j][i] < lru) {
					lru_proc = j;
					lru = i;
				}
			}
		}

		pageout(lru_proc, lru);

	}


    /* advance time for next pageit iteration */
    tick++;
} 

// for (int proc = 0; proc < MAXPROCESSES; proc++) {
//
// 	if (!q[proc].active) continue;
//
// 	int pc = q[proc].pc;
// 	int page = pc/PAGESIZE;
//
// 	timestamps[proc][page] = tick;
//
// 	if (q[proc].pages[page]) { continue; }
// 	if (pagein(proc, page)) {
// 		continue;
// 	}
//
// 	int lru = tick;
// 	for (int i = 0; i < MAXPROCPAGES; i++) {
// 		if (q[proc].pages[i] == page) { continue; }
// 		if (q[proc].pages[i] == 0) { continue; }
//
// 		if (timestamps[proc][i] < lru) {
// 			lru = i;
// 		}
// 	}
//
// 	pageout(proc, lru);
//
// }
