#include <assert.h>
#include "coordRepr.h"

using namespace std;

int main() {
    // Change filename here to construct CSR for another file
    string file = "ex.dimacs"; 
    COO list{};
    /* construct the coordinate representation 
        (COO) of the graph from the DIMACS file. */
    assert(buildCOO(&list, file));
    // printEdges(list);  

    CSR csr{list.nodes, list.edges};
    assert(buildCSR(&csr, list));
    printCSR(csr);

    return EXIT_SUCCESS;
};



