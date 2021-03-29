#include <stdbool.h>
#include <stdio.h>
#include "system.h"
#include "coordRepr.h"

bool printAsDimacs(char *f, CSR c) {
    FILE *fp;
    fp = fopen (f, "w");

    fprintf(fp, "p sp %d %d\n", c.nodes, c.edges);
    int row = 0;
    int checkIn = 0;
    int temp, first, second;
    for(int i = 1; i < c.edges + 1; i++) {
        if(checkIn == 0) {
            do { 
                row++;
            } while(c.rp[row] == 0);
            first = c.rp[row];
            temp = row;
            do { 
                temp++;
            } while(c.rp[temp] == 0);
            second = c.rp[temp];
            checkIn = second - first;
        }
        fprintf(fp, "a %d %d %d\n", row, c.ci[i], c.ai[i]);
        checkIn--;
    }

    fclose(fp);
}
