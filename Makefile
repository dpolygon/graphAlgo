
main:
	g++ -o main main.cc

clean:
	rm main

readable:
	objdump -d test.o >> test.txt