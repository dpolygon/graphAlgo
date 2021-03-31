#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//graph edge
struct edge {
    int src;
    int dest;
    int weight;
    
    // constructor
    edge(int s, int d, int w): src(s), dest(d), weight(w){}
};

// Cordinate representation
struct COO {
    vector<edge> data;
    string format;
    int nodes, edges;
};

// Compressed Sparse Row
struct CSR {
    int *rp, *ci, *ai;
    int nodes, edges;
    
    // constructor
    CSR(int n, int e) : nodes(n), edges(e) {
        //dynamically allocating array for node and edge sizes
        rp = (int *) calloc((nodes + 1), sizeof(int));
        ci = (int *) malloc((edges + 1) * sizeof(int));
        ai = (int *) malloc((edges + 1) * sizeof(int));
    }
};

bool operator< (edge a, edge b);
bool buildCOO(COO *list, string f);
bool buildCSR(CSR *csr, COO list);
void printEdges(COO csr);
void printCSR(CSR c);

#endif