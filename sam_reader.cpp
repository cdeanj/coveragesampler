#include "sam_reader.h"
#include "utility.h"

#include <string>
#include <vector>
#include <fstream>

sam_reader::sam_reader(std::string fp) : _fp(fp) {}

std::vector<alignment> sam_reader::read() {
	std::ifstream ifs(_fp);
	if(!ifs) {
		exit(EXIT_FAILURE);
	}
	std::string alignment;
	std::vector<struct alignment> alignments;
	while(std::getline(ifs, alignment)) {
		if(alignment[0] != '@') {
			if(is_valid_alignment(alignment)) {
			}			
		}
	}
	return alignments;
}
