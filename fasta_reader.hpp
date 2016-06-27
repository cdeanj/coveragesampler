#ifndef FASTA_READER_H
#define FASTA_READER_H

#include <vector>
#include <string>
#include <map>

class record {
public:
	record(std::string g, int n) : gene(g), base_hits(n, 0) {}
	std::vector<bool> base_hits;
	std::string gene;
};

class fasta_reader {
public:
	fasta_reader(std::string fp);
	std::map<std::string, record> read();
private:
	std::string _fp;
};





#endif // FASTA_READER_H
