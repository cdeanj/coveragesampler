#include <map>
#include <iostream>
#include <string>
#include <vector>

#include "fasta_reader.hpp"
#include "sam_reader.hpp"
#include "sam_ratio.hpp"
#include "args.hpp"

using namespace std;

int main(const int argc, const char *argv[]) {
	if(argc != 17) {
		usage();
		exit(EXIT_FAILURE);
	}

	struct cmd_args args;
	args = parse_command_line(argc, argv);

	fasta_reader fr(args.ref_fp);
	map<string, record> records = fr.read();

	sam_reader sr(args.sam_fp);
	vector<struct alignment> alignments = sr.read();

	sam_ratio ratio(args);
	ratio.generate_samples(records, alignments);
	
	return 0;
}
