#include <map>
#include <iostream>
#include <string>
#include <vector>

#include "fasta_reader.hpp"
#include "sam_reader.hpp"

using namespace std;

struct cmd_args {
	std::string fasta_fp;
	std::string sam_fp;
	std::string out_fp;
	int threshold;
	int min;
	int max;
	int skip;
	int s_per_level;
};

void usage() {
        fprintf(stderr, "\n");
        fprintf(stderr, "Program: Coverage Sampler \n");
        fprintf(stderr, "Contact: Chris Dean <cdean11@rams.colostate.edu\n\n");
        fprintf(stderr, "Usage: csa [options]\n\n");
        fprintf(stderr, "Options:\n\n");
        fprintf(stderr, "    -amr_fp    amr database path\n");
        fprintf(stderr, "    -sam_fp    sam file path\n");
        fprintf(stderr, "    -min       starting level\n");
        fprintf(stderr, "    -max       ending level\n");
        fprintf(stderr, "    -skip      amount of levels to skip\n");
        fprintf(stderr, "    -t         gene fraction threshold\n");
        fprintf(stderr, "    -samples   amount of samples per level\n");
        fprintf(stderr, "    -out_fp    output file path\n\n");
}

struct cmd_args 
parse_command_line(const int argc, const char *argv[]) {
	struct cmd_args arg;
	std::vector<std::string> args(argv, argv + argc);

        for(int i = 1; i < argc; i++) {
                if(args[i].compare("-amr_fp") == 0)
                        arg.fasta_fp = args[++i];
                else if(args[i].compare("-sam_fp") == 0)
                        arg.sam_fp = args[++i];
                else if(args[i].compare("-out_fp") == 0)
                        arg.out_fp = args[++i];
                else if(args[i].compare("-t") == 0)
                        arg.threshold = atoi(args[++i].c_str());
                else if(args[i].compare("-min") == 0)
                        arg.min = atoi(args[++i].c_str());
                else if(args[i].compare("-max") == 0)
                        arg.max = atoi(args[++i].c_str());
                else if(args[i].compare("-skip") == 0)
                        arg.skip = atoi(args[++i].c_str());
                else if(args[i].compare("-samples") == 0)
                        arg.s_per_level = atoi(args[++i].c_str());
                else {
                        usage();
                        exit(EXIT_FAILURE);
                }
        }
	return arg;
}

int main(const int argc, const char *argv[]) {
	if(argc != 17) {
		usage();
		exit(EXIT_FAILURE);
	}
	fasta_reader fr(argv[1]);
	map<string, struct record> records = fr.read();
	sam_reader sr(argv[2]);
	vector<alignment> alignments = sr.read();
	//std::cout << alignments.size() << std::endl;

	/*for(auto it = alignments.begin(); it != alignments.end(); ++it) {
		for(auto it2 = it->cigar.begin(); it2 != it->cigar.end(); ++it2) {
			cout << it2->first << " " << it2->second << endl;
		}
	}*/

	return 0;
}
