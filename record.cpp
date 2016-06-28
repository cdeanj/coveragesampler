#include "record.hpp"

record::record(std::string gene, int n) : _gene(gene), _base_hits(n, 0), _gene_hits(0) {}

double record::coverage() {
	return static_cast<double>(get_base_hits())/static_cast<double>(_gene.length())*100;
}
