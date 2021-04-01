#include <assert.h>
#include "coordRepr.h"
#include "pageRank.h"
#include "system.h"

using namespace std;

int main() {
    // Change filename here to construct CSR for another file
    string file = "road-NY.dimacs"; 
    COO list{};
    /* construct the coordinate representation 
        (COO) of the graph from the DIMACS file. */
    assert(buildCOO(&list, file));
    // printEdges(list);  

    CSR csr{list.nodes, list.edges};
    assert(buildCSR(&csr, list));
    // printCSR(csr);

    /* takes in name of txt file 
        to write to and CSR */
    printAsDimacs("res.txt", csr);

    pageRank p{csr};
    printHistogramData("data.txt", p);
    pageRankAlgorithm(&p);
    printNodes("res2.txt", p);

    return EXIT_SUCCESS;
};



