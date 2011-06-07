#include "raw.h"

using namespace std;

bool RawExporter::save_to_file(std::string & filename, const Graph::Graph & graph) const {
	ofstream file(filename.c_str());
	if (!file.is_open()) return false;
	// for_each edge in raph.edges write edge to file
	file.close();
	return true;
}

bool RawImporter::load_from_file(std::string & filename, Graph::Graph & graph) const {
	fstream file(filename.c_str());
	if (!file.is_open()) return false;
	while (!file.eof()) {
		// load edges from file
	}
	file.close();
	return true;
}
