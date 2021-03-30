#include <bits/stdc++.h>
#include "pageRank.h"
#include "coordRepr.h"
#include "system.h"

using namespace std;

bool printNodes(char *f, CSR c) {
    FILE *fp;
    fp = fopen (f, "w");

    // list or array of page ranks, 
    // where each index represents the node number - 1
    struct node* pageRanks = pageRankAlgorithm(c);

    double label;
    for(int i = 0; i < c.nodes; i++) {
        label = pageRanks[i].currentPR;
        fprintf(fp, "%d %0.4lf\n", i+1, label);
    }
    
    fclose(fp);

}

struct node* initializePageRanks(CSR c) {
    // return an array of page ranks, where each index represents the node number
    struct node *pageRanks;
    pageRanks = (struct node *) malloc(c.nodes * sizeof(struct node));
    // initialize all node values to 1/N
    for(int i = 0; i < c.nodes + 1; i++) {
        pageRanks[i].prevPR = 1.0 / c.nodes;
    }
    
    // currentPR should be null
    // count # outgoing edges from CSR
    // put all incoming neighbor nodes in a list
    return pageRanks;

}

struct node* pageRankAlgorithm(CSR c) {
    struct node* pageRanks = initializePageRanks(c);
    // terminate the page-rank iterations when no node changes its page-rank value by more than 10^-4 between successive iterations
    bool nodeChanged = true;
    while(nodeChanged) {
        nodeChanged = false;
        for(int i = 0; i < c.nodes; i++) {
            // algorithm


            // check if miniscule change occurred
            if(pageRanks[i].prevPR - pageRanks[i].currentPR >= 10^-4 || pageRanks[i].currentPR - pageRanks[i].prevPR >= 10^-4)
                nodeChanged = true;
        }

    }
}