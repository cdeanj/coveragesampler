#include <map>
#include <iostream>
#include <string>
#include <vector>

#include "fasta_reader.h"
#include "sam_reader.h"
#include "utility.h"

using namespace std;

int main(const int argc, const char *argv[]) {
	fasta_reader fr(argv[1]);
	map<string, struct record> records = fr.read();
	sam_reader sr(argv[2]);
	vector<alignment> alignments = sr.read();
	std::cout << alignments.size() << std::endl;

	/*for(auto it = records.begin(); it != records.end(); ++it) {
		cout << it->first << " " << it->second.gene << " " << it->second.base_hits.size() << endl;
	}*/


	return 0;
}
