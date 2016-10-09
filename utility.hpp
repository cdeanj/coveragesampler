#include <string>
#include <vector>

#include "alignment.hpp"

namespace utility {
	bool is_valid_alignment(std::string &alignment);
	bool is_good_rname(const std::string &rname);
	bool is_good_cigar(const std::string &cigar);
	bool is_good_seq(const std::string &seq);
	bool is_good_flag(const int flag);
	bool is_good_pos(const int pos);

	int rando(const int i);

	void init_alignment(struct alignment *a, const std::string &al);
	std::vector<std::pair<int,char> > get_cigar_ops(const std::string &cigar);
}
