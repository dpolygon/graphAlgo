
main: main.o coordRepr.o system.o pageRank.o
	g++ main.o coordRepr.o system.o pageRank.o -o main

main.o: main.cc
	g++ -c main.cc

coordRepr.o: coordRepr.cc
	g++ -c coordRepr.cc

system.o: system.cc
	g++ -c system.cc

pageRank.o: pageRank.cc
	g++ -c pageRank.cc

clean:
	rm *.o *.txt main