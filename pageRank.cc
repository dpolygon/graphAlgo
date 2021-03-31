#include <bits/stdc++.h>
#include "pageRank.h"
#include "coordRepr.h"
#include "system.h"

using namespace std;

bool printNodes(char *f, pageRank p) {
    FILE *fp;
    fp = fopen (f, "w");

    // list or array of page ranks, 
    // where each index represents the node number - 1
    node n;
    for(int i = 1; i < p.size; i++) {
        n = p.ranks[i];
        fprintf(fp, "node number: %d   label: %0.9lf ", i, n.prevPR);
        for(int i = 0; i < n.outgoingEdges.size(); i++)
            fprintf(fp, " %d", n.outgoingEdges.at(i)->nodeID);
        fprintf(fp, "\n");
    }
    cout << "printed Nodes to " << f << '\n';
    fclose(fp);
}

bool pageRankAlgorithm(pageRank *p) {
    // terminate the page-rank iterations when no node changes its page-rank value by more than 10^-4 between successive iterations
    bool nodeChanged = true;
    while(nodeChanged) {
        nodeChanged = false;
        for(int i = 1; i < p->size; i++) {
            // algorithm


            // check if miniscule change occurred
            if(p->ranks[i].prevPR - p->ranks[i].currentPR >= 10^-4 || p->ranks[i].currentPR - p->ranks[i].prevPR >= 10^-4)
                nodeChanged = true;
        }

    }
}