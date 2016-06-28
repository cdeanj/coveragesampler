#include <fstream>
#include "record.hpp"
#include "fasta_reader.hpp"

fasta_reader::fasta_reader(std::string fp) : _fp(fp) {}

std::map<std::string, record> fasta_reader::read() {
	std::ifstream ifs(_fp);
	if(!ifs) {
		exit(EXIT_FAILURE);
	}
	std::string gene_id, gene;
	std::map<std::string, record> records;
	while(std::getline(ifs, gene_id)) {
		if(gene_id[0] == '>') {
			getline(ifs, gene);
			gene_id = gene_id.substr(1,gene_id.length()-1);
			records.insert(make_pair(gene_id, record(gene, gene.length())));			
		}
	}
	ifs.close();
	return records;
}
