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
    double tot;
    for(int i = 1; i < p.size; i++) {
        n = p.ranks[i];
        tot += n.prevPR;
        fprintf(fp, "node number: %d   pageRank: %0.12lf   outgoing links:", i, n.prevPR);
        for(int i = 0; i < n.outgoingEdges.size(); i++)
            fprintf(fp, " %d", n.outgoingEdges.at(i)->nodeID);
        fprintf(fp, "\n");
    }
    fprintf(fp, "%lf\n", tot);
    cout << "printed Nodes to " << f << '\n';
    fclose(fp);
}

bool printHistogramData(char *f, pageRank p) {
    FILE *fp;
    fp = fopen (f, "w");

    // list or array of page ranks, 
    // where each index represents the node number - 1
    node n;
    fprintf(fp, "%d\n", p.size - 1);
    for(int i = 1; i < p.size; i++) {
        n = p.ranks[i];
        int edges = n.outgoingEdges.size();
        fprintf(fp, "%d\n", edges);
    }
    cout << "printed Histogram Data to " << f << '\n';
    fclose(fp);
}

bool pageRankAlgorithm(pageRank *p) {
    
    bool nodeChanged = true;
    double dampingFactor = 0.85;
    double tot;
    cout << "running pageRank algorithm\n"; 
    int calc = 0;
    while(nodeChanged && calc < 100) {
        tot = 0;
        nodeChanged = false;
        for(int i = 1; i < p->size; i++) {
            double juice = p->ranks[i].prevPR;
            int total = p->ranks[i].outgoingEdges.size();
            double outJuice = total ? (juice / total) * dampingFactor : 0;
            p->ranks[i].currentPR += (1.0 - dampingFactor) / p->size;
            tot += (1.0 - dampingFactor) / p->size;

            for(int j = 0; j < total; j++) {
                p->ranks[i].outgoingEdges.at(j)->currentPR += outJuice;
                tot += outJuice;
            }
        }

        calc++;
        // terminate the page-rank iterations when no node changes its page-rank value by more than 10^-4 between successive iterations
        for(int i = 1; i < p->size; i++) {
            if(p->ranks[i].prevPR - p->ranks[i].currentPR >= 0.0001 || p->ranks[i].currentPR - p->ranks[i].prevPR >= 0.0001)
                    nodeChanged = true;
                    
            double scaler = nodeChanged && calc < 100 ? 1.0 : tot;
            p->ranks[i].prevPR = p->ranks[i].currentPR / scaler;
            p->ranks[i].currentPR = 0;
        }
    }

    return true;
}