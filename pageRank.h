#ifndef PAGERANK_H
#define PAGERANK_H

#include <vector>
#include <string>
#include <iostream>
#include "coordRepr.h"

using namespace std;

struct node {
    int nodeID;
    double prevPR;
    double currentPR;
    vector<node*> outgoingEdges;
};



struct pageRank {
    node *ranks;
    int size;

    int help(int i, int index, CSR c) {
        int first, second;
        if(c.rp[i] == 0)
            return 0;

        if(i == size - 1)
            return c.edges - index + 1;

        
        first = c.rp[i];
        do { i++; } while(c.rp[i] == 0 && i < size);
        second = c.rp[i];

        if(second == 0) {
            return c.edges - index + 1;
        }

        return second - first;
    }

    pageRank(CSR c) : size(c.nodes + 1) {
        ranks = (node *) malloc((c.nodes + 1) * sizeof(node));

        int index = 1;
        for(int i = 1; i < size; i++) {
            ranks[i].nodeID = i;
            ranks[i].prevPR = 1.0 / c.nodes;    // initialize all node values to 1/N
            int outs = help(i, index, c);
            for(int j = 0; j < outs; j++) {
                ranks[i].outgoingEdges.push_back(&(ranks[c.ci[index]]));
                index++;
            }
        }
        cout << "pageRank initialized, ranks initialized\n";
    }


};



bool printNodes(char *f, pageRank p);
bool pageRankAlgorithm(pageRank *p);

#endif