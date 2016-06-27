#include <map>
#include <iostream>
#include <string>
#include <vector>

#include "fasta_reader.hpp"
#include "sam_reader.hpp"

using namespace std;

int main(const int argc, const char *argv[]) {
	fasta_reader fr(argv[1]);
	map<string, struct record> records = fr.read();
	sam_reader sr(argv[2]);
	vector<alignment> alignments = sr.read();
	//std::cout << alignments.size() << std::endl;

	for(auto it = alignments.begin(); it != alignments.end(); ++it) {
		for(auto it2 = it->cigar.begin(); it2 != it->cigar.end(); ++it2) {
			cout << it2->first << " " << it2->second << endl;
		}
	}

	return 0;
}
