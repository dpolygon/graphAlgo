
main: main.o coordRepr.o
	g++ main.o coordRepr.o -o main

main.o: main.cc
	g++ -c main.cc

coordRepr.o: coordRepr.cc
	g++ -c coordRepr.cc

clean:
	rm *.o main