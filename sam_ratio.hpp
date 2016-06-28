#ifndef SAM_RATIO_H
#define SAM_RATIO_H

#include "args.hpp"
#include "record.hpp"
#include "utility.hpp"

#include <map>
#include <vector>
#include <string>

class sam_ratio {
public:
	sam_ratio(struct cmd_args arguments);
	void generate_samples(std::map<std::string, record> &records, const std::vector<struct alignment> &alignments);

private:
	struct cmd_args args;
};

#endif // SAM_RATIO_H
