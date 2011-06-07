#ifndef RAW_H__
#define RAW_H__
#include "interfaces.h"

struct RawExporter : public Interfaces::IExporter {
	RawExporter() : IExporter("RawExporter", "Import plain text graph", "Graph Files (*.pgrp)") {}
	virtual bool save_to_file(std::string & filename, const Graph::Graph & graph) const;
};

struct RawImporter : public Interfaces::IImporter {
	RawImporter() : IImporter("RawImporter", "Import plain text graph", "Graph Files (*.pgrp)") {
	}
	virtual bool load_from_file(std::string & filename, Graph::Graph & graph) const;
};
#endif
