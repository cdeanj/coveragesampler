#include <string>

namespace utility {
	bool is_valid_alignment(const std::string &alignment);
	bool is_good_rname(const std::string &rname);
	bool is_good_cigar(const std::string &cigar);
	bool is_good_seq(const std::string &seq);
	bool is_good_flag(const int flag);
	bool is_good_pos(const int pos);
}
