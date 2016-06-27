#include "utility.h"
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>

namespace utility {
	bool is_good_alignment(const std::string &alignment) {
		std::string field;
		std::istringstream ss(alignment);
		std::vector<std::string> parts;
		while(ss >> field) {
			parts.push_back(field);
		}

		if(!(is_good_rname(parts[2])))
			return false;
		if(!(is_good_cigar(parts[5]))) 
			return false;
		if(!(is_good_seq(parts[9])))
			return false;
		if(!(is_good_flag(atoi(parts[1].c_str()))))
			return false;
		if(!(is_good_pos(atoi(parts[3].c_str()))))
			return false;
		
		return true;
	}

	bool is_good_rname(const std::string &rname) {
		return rname.compare("*") != 0;
	}

	bool is_good_cigar(const std::string &cigar) {
		return cigar.compare("*") != 0;
	}

	bool is_good_seq(const std::string &seq) {
		return seq.compare("*") != 0;
	}

	bool is_good_flag(const int flag) {
		return (flag & 4) == 0;
	}
	
	bool is_good_pos(const int pos) {
		return pos != 0;
	}
}
