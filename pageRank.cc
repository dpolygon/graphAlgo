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
    
    bool nodeChanged = true;
    double dampeningFactor = 0.85;
    int totalPageRank = 0;
    while(nodeChanged) {
        nodeChanged = false;
        for(int i = 1; i < p->size; i++) {
            double juice = p->ranks[i].prevPR;
            int total = p->ranks[i].outgoingEdges.size();
            double outJuice = total ? (juice / total) * dampeningFactor : 0;
            p->ranks[i].currentPR += (1.0 - dampeningFactor);
            totalPageRank += (1.0 - dampeningFactor);

            for(int j = 0; j < total; j++) {
                p->ranks[i].outgoingEdges.at(j)->currentPR += outJuice;
                totalPageRank += outJuice;
            }
        }

        // terminate the page-rank iterations when no node changes its page-rank value by more than 10^-4 between successive iterations
        for(int i = 1; i < p->size; i++) {
            if(p->ranks[i].prevPR - p->ranks[i].currentPR >= 0.0001 || p->ranks[i].currentPR - p->ranks[i].prevPR >= 0.0001)
                    nodeChanged = true;

            p->ranks[i].prevPR = p->ranks[i].currentPR;
            p->ranks[i].currentPR = 0;
        }
    }

    return true;
}