output: main.o fasta_reader.o sam_reader.o record.o sam_ratio.o utility.o
	g++ -std=c++11 main.o fasta_reader.o sam_reader.o record.o sam_ratio.o utility.o -o csa
main.o: main.cpp
	g++ -c -std=c++11 main.cpp
fasta_reader.o: fasta_reader.cpp
	g++ -c -std=c++11 fasta_reader.cpp
sam_reader.o: sam_reader.cpp
	g++ -c -std=c++11 sam_reader.cpp
record.o: record.cpp
	g++ -c -std=c++11 record.cpp
sam_ratio.o: sam_ratio.cpp
	g++ -c -std=c++11 sam_ratio.cpp
utility.o: utility.cpp
	g++ -c -std=c++11 utility.cpp
clean:
	rm *.o csa
