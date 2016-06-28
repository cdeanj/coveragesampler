#include "args.hpp"
#include "sam_ratio.hpp"

#include <assert.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <string>
#include <cmath>

int rando(const int i) {
        return rand() % i;
}

sam_ratio::sam_ratio(struct cmd_args arguments) : args(arguments) {}

void sam_ratio::write_header(std::string &out_fp) {
	std::ofstream ofs(out_fp, std::ofstream::app);
	ofs << "Level\tIteration\tGene Id\tGene Fraction\tHits" << '\n';
	ofs.close();
}

void sam_ratio::write_results(std::map<std::string, record> &records, const int curr_level, const int curr_iter, std::string &out_fp) {
	std::ofstream ofs(out_fp, std::ofstream::app);
	for(auto it = records.begin(); it != records.end(); ++it) {
		ofs << curr_level << "\t" << curr_iter << "\t" << it->first << "\t" << it->second.coverage() << "\t" << it->second.gene_hits() << "\n";
	}
	ofs.close();	
}

void reset(std::map<std::string,record> &records) {
	for(auto key = records.begin(); key != records.end(); ++key) {
		key->second.reset_base_hits();
		key->second.reset_gene_hits();
	}
}

void sam_ratio::analyze_coverage(record &rec, const alignment &al) {
	rec.update_gene_hits();

	int pos_in_read = 0;
	int pos_in_gene = al.pos-1;

	int gene_length = rec.get_gene().length();

	for(int i = 0; i < al.cigar.size(); i++) {
		int occurrence = al.cigar[i].first;
		char operation = al.cigar[i].second;
		int start = pos_in_gene;
		int stop = start + occurrence;

		if(stop > gene_length) {
			stop = gene_length;
		}

		switch(operation) {
                        case 'M':
                                for(int i = start; i < stop; i++) {
                                        rec._base_hits[i] = 1;
                                        pos_in_gene++;
					pos_in_read++;
                                }
                                break;
                        case '=':
                                for(int i = start; i < stop; i++) {
                                        rec._base_hits[i] = 1;
                                        pos_in_gene++;
                                        pos_in_read++;
                                }
                                break;
                        case 'D':
                                pos_in_gene += occurrence;
                                break;
                        case 'N':
                                pos_in_gene += occurrence;
                                break;
                        case 'S':
                                pos_in_read += occurrence;
                                break;
                        case 'I':
                                pos_in_read += occurrence;
                                pos_in_gene += occurrence;
                                break;
                        case 'H':
                                break;
                        case 'P':
                                pos_in_gene += occurrence;
                                pos_in_read += occurrence;
                                break;
                        case 'X':
                                pos_in_gene += occurrence;
                                pos_in_read += occurrence;
                                break;
                        default:
                                break;
                }
	}
}

void sam_ratio::generate_samples(std::map<std::string, record> &records, const std::vector<struct alignment> &alignments) {
	srand(unsigned(time(0)));

	int alignment_count = alignments.size();
	std::vector<int> sequence(alignment_count);
	std::iota(sequence.begin(), sequence.end(), 0);

	assert(alignments.size() > 0);

	write_header(args.out_fp);

	for(int i = args.min; i <= args.max; i += args.skip) {
		for(int j = 0; j < args.s_per_level; j++) {
			random_shuffle(sequence.begin(), sequence.end(), rando);
			int sample_size = round(((static_cast<double>(i)/100)*alignment_count));
			std::vector<int> chosen(sequence.begin(), sequence.begin()+sample_size);
			for(int k = 0; k < chosen.size(); k++) {
				std::string rname = alignments[chosen[k]].rname;
				analyze_coverage(records.find(rname)->second, alignments[chosen[k]]);
			}
			write_results(records, i, j+1, args.out_fp);
			reset(records);
			//std::map<std::string, record> &records, const int curr_level, const int curr_iter, std::string &out_fp
		}
	}
}
