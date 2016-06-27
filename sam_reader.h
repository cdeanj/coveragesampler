#ifndef SAM_READER_H
#define SAM_READER_H

#include <string>
#include <vector>

struct alignment {
	int flag;
	int pos;
	std::string rname;
	std::string cigar;
	std::string seq;
};

class sam_reader {
public:
	sam_reader(std::string fp);
	std::vector<struct alignment> read();
private:
	std::string _fp;
};

#endif // SAM_READER_H
