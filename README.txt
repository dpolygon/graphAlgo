Describe how to compile and run the program in a README.txt

Our C++ routines can be called from main.cc
In order to compile and run our code:
- first use the command `make clean` if applicable
- then use the command `make`
- `./main`

For the routine that takes DIMACS and constructs CSR:
The buildCSR() routine found in coordRepr.cc, line 53

For the routine that take CSR and prints DIMACS:
The printAsDimacs() routine found in system.cc, line 6

For the routine that takes CSR and prints node numbers and node labels:
The printNodes() routine found in pageRank.cc, line 8


In order to see the histograms:
- first use the command `make clean` if applicable
- then use the command `make`
- `./main`
- finally, run `python histogram-road-NY.py` or `python histogram-rmat15.py`
- whichever python program is run will save its corresponding histogram to histogram.png