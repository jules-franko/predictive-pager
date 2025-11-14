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

	int pc;
	int page;
	int lru_page;
	int oldest_tick;

    if (!initialized) {
		for (int proc=0; proc < MAXPROCESSES; proc++) {
			for (int page=0; page < MAXPROCPAGES; page++) {
				timestamps[proc][page] = 0;
			}
		}
		initialized = 1;
	}

	for (int proc = 0; proc < MAXPROCESSES; proc++) {

		if (q[proc].active) {
			/*Look for a predicted page to page in*/
			/*pagein()*/
			/*If it fails, use LRU to evict a page on page fault*/
		} else {
			continue;
		}

		pc = q[proc].pc;
		page = pc/PAGESIZE;

		/*Handle current page if it's not swapped in*/
		if (!q[proc].pages[page]) {

			/*Try to page it in*/
			if (!pagein(proc, page)) {

				lru_page = 0;
				oldest_tick = tick; //Initialized to young time

				/*If paging fails, use Local LRU to evict something*/
				for (int i = 0; i < MAXPROCPAGES; i++) {

					if (q[proc].pages[i] && i != page) {
						if (timestamps[proc][i] < oldest_time) {
							oldest_tick = timestamps[proc][i];
							lru_page = i;
						}
					}
				}

				pageout(proc, lru_page);
			}

			}

			timestamps[proc][page] = tick;
		}
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
// 	int lru_proc = 0;
// 	int lru_page = 0;
// 	int oldest_tick = tick; //Initialized to young time
//
// 	int predicted_page;
//
// 	if (q[proc].pages[page]) { continue; }
// 	if (pagein(proc, page)) { continue; }
//
// 	//If pagein() fails, choose something to evict
// 	for (int process = 0; process < MAXPROCESSES; process++) {
//
// 		if (!q[process].active) { continue; }
//
// 		for (int i = 0; i < MAXPROCPAGES; i++) {
// 			if (process == proc && i == page) { continue; }
// 			if (q[process].pages[i] == 0) { continue; }
//
// 			if (timestamps[process][i] < oldest_time) {
// 				oldest_tick = timestamps[process][i];
// 				lru_proc = process;
// 				lru_page = i;
// 			}
// 		}
// 	}
//
// 	pageout(lru_proc, lru_page);
//
// 	// if (page+1 < MAXPROCPAGES && !q[proc].pages[page+1]) {
// 	// 	pagein(proc,page+1);
// 	// }
//
// }

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

/* TODO: Implement Predictive Paging */
//fprintf(stderr, "pager-predict not yet implemented. Exiting...\n");
//exit(EXIT_FAILURE);
