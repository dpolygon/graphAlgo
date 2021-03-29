#include <bits/stdc++.h>
#include "coordRepr.h"

using namespace std;

/* overriding < operator to sort for src first then dest
increasing order */
bool operator< (edge a, edge b) {
        if (a.src == b.src) {
            return (a.dest < b.dest);
        }
    return (a.src < b.src);
}

/* construct the coordinate representation 
    (COO) of the graph from the DIMACS file. */
bool buildCOO(COO *list, string f) {
    ifstream fileStream(f);
    // check if file is open 
    if(fileStream.is_open()) {
        fileStream >> list->format >> list->format; // saving format field (not sure what its useful for yet)
        fileStream >> list->nodes >> list->edges; // storing number of nodes and edges
    } else {
        cout << "file is not found \n";
        return false;
    }

    string arc;
    while(fileStream >> arc){
        int src, dest, w;
        fileStream >> src >> dest >> w;
        list->data.push_back(edge(src, dest, w));
    }

    // Sort edges in COO by the source node ID. //
    sort(list->data.begin(), list->data.end());
    // printEdges(data);

    return true;
}

bool buildCSR(CSR *csr, COO list) {
    int currRow = 0;
    for(int i = 0; i < list.data.size(); i++) {
        edge currEdge = list.data.at(i);
        int src = currEdge.src;
        if(currRow != src){
            csr->rp[src] = i + 1;
            currRow = src;
        }
        csr->ci[i + 1] = currEdge.dest;
        csr->ai[i + 1] = currEdge.weight;
    }
    return true;
}

// print vector containing list of graph edges
void printEdges(vector<edge> csr) {
    // iterate over vector
    for (vector<edge>::iterator it=csr.begin(); it!=csr.end(); ++it)
        printf("src: %d, dest: %d \n", (*it).src, (*it).dest);
    cout << '\n';
}

/* prints out...
    rp: postion of which the next row starts
    ci: column placements of data
    ai: weight information */
void printCSR(CSR c) {
    cout << "rp:";
    for(int i = 1; i < c.nodes + 1; i++)
        printf(" %-3d",c.rp[i]);
    cout << '\n';

    cout << "ci:";
    for(int i = 1; i < c.edges + 1; i++)
        printf(" %-3d",c.ci[i]);
    cout << '\n';

    cout << "ai:";
    for(int i = 1; i < c.edges + 1; i++)
        printf(" %-3d",c.ai[i]);
    cout << '\n';
}