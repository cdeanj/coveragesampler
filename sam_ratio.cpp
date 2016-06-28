#include "args.hpp"
#include "sam_ratio.hpp"

#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>

sam_ratio::sam_ratio(struct cmd_args arguments) : args(arguments) {}

void sam_ratio::generate_samples(std::map<std::string, struct record> &records, const std::vector<struct alignment> &alignments) {
	srand(unsigned(time(0)));

	std::vector<int> sequence(alignments.size());
	std::iota(sequence.begin(), sequence.end(), 0);

	std::cout << alignments.size() << std::endl;	

}
