#include "record.hpp"

record::record(std::string gene, int n) : _gene(gene), _base_hits(n, 0), _gene_hits(0) {}
