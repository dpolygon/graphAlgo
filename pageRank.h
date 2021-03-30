#ifndef PAGERANK_H
#define PAGERANK_H

#include <vector>
#include <string>

using namespace std;

struct node {
    double prevPR;
    double currentPR;
    int outgoingEdges;
    struct node* incomingNodes;
}

bool printNodes(char *f, CSR c);
struct node* initializePageRanks(CSR c);
struct node* pageRankAlgorithm(CSR c);

#endif