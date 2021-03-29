#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector> 
#include <bits/stdc++.h>

using namespace std;

struct edge {
    int src;
    int dest;
    int weight;

    edge(int s, int d, int w): src(s), dest(d), weight(w){}
};

struct CSR {
    int *rp;
    int *ci;
    int *ai;
    
    CSR(int nodes, int edges) {
        rp = (int *) calloc((nodes + 1), sizeof(*rp));
        ci = (int *) malloc((edges + 1) * sizeof(*ci));
        ai = (int *) malloc((edges + 1) * sizeof(*ai));
    }
};

bool sortFunc(edge a, edge b){
    if (a.src == b.src) {
        return a.dest < b.dest;
    }
    return a.src < b.src;
}

void printEdges(vector<edge> csr) {
    for (vector<edge>::iterator it=csr.begin(); it!=csr.end(); ++it)
        printf("src: %d, dest: %d \n", (*it).src, (*it).dest);
    cout << '\n';
}

void printCSR(CSR csr, int nodes, int edges){
    cout << "rp:";
    for(int i = 0; i < nodes + 1; i++)
        printf(" %-3d",csr.rp[i]);
    cout << '\n';

    cout << "ci:";
    for(int i = 0; i < edges + 1; i++)
        printf(" %-3d",csr.ci[i]);
    cout << '\n';

    cout << "ai:";
    for(int i = 0; i < edges + 1; i++)
        printf(" %-3d",csr.ai[i]);
    cout << '\n';
}

int main() {
    
    string file = "wiki.dimacs";
    vector<edge> data;
    ifstream fileStream(file);

    string format;
    int nodes, edges;
    if(fileStream.is_open()){
        fileStream >> format >> format;
        fileStream >> nodes >> edges;

    } else {
        cout << "file is not found \n";
    }

    string arc;
    while(fileStream >> arc){
        int src, dest, w;
        fileStream >> src >> dest >> w;
        data.push_back(edge(src, dest, w));
    }

    // cout << "finished writing to vectors\n";
    sort(data.begin(), data.end(), sortFunc);
    // printEdges(data);

    CSR csr{nodes, edges};
    int currRow = 0;

    for(int i = 0; i < data.size(); i++) {
        edge currEdge = data.at(i);
        int src = currEdge.src;
        if(currRow != src){
            csr.rp[src] = i + 1;
            currRow = src;
        }
        csr.ci[i + 1] = currEdge.dest;
        csr.ai[i + 1] = currEdge.weight;
    }

    printCSR(csr, nodes, edges);


    return 0;
};

