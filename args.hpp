#ifndef ARGS_H
#define ARGS_H

#include <string>
#include <vector>
#include <stdlib.h>

struct cmd_args {
	std::string ref_fp;
	std::string sam_fp;
	std::string out_fp;
	int threshold;
	int min;
	int max;
	int skip;
	int s_per_level;
};

static void usage() {
        fprintf(stderr, "\n");
        fprintf(stderr, "Program: Coverage Sampler \n");
        fprintf(stderr, "Contact: Chris Dean <cdean11@rams.colostate.edu\n\n");
        fprintf(stderr, "Usage: csa [options]\n\n");
        fprintf(stderr, "Options:\n\n");
        fprintf(stderr, "    -ref_fp    STR/FILE		fasta file path\n");
        fprintf(stderr, "    -sam_fp    STR/FILE		sam file path\n");
        fprintf(stderr, "    -min       INT		starting sample level\n");
        fprintf(stderr, "    -max       INT		ending sample level\n");
        fprintf(stderr, "    -skip      INT		amount of sample levels to skip\n");
        fprintf(stderr, "    -t         INT		gene fraction threshold\n");
        fprintf(stderr, "    -samples   INT		iterations per sample level\n");
        fprintf(stderr, "    -out_fp    STR/FILE		output file path\n\n");
}

struct cmd_args 
inline parse_command_line(const int argc, const char *argv[]) {
	struct cmd_args arg;
	std::vector<std::string> args(argv, argv + argc);

        for(int i = 1; i < argc; i++) {
                if(args[i].compare("-ref_fp") == 0)
                        arg.ref_fp = args[++i];
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

#endif // ARGS_H
