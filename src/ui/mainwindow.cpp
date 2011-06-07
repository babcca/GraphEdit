#include "mainwindow.h"
#include <iostream>
MainW::MainW() {
	mm.importer.add(new RawImporter());
	fileMenu = menuBar()->addMenu("File");
	importMenu = fileMenu->addMenu("Import");
	GenerateImporterMenu(importMenu);
}

void MainW::GenerateImporterMenu(QMenu * importerMenu) {
	importer_type::iterator it = mm.importer.begin();
	QAction * importer = 0;
	while (it != mm.importer.end()) {
		importer = new QAction(tr(it->second->menuName.c_str()), this);
		importer->setData(it->second->name.c_str());
		connect(importer, SIGNAL(triggered()), this, SLOT(ImportFile()));
		importerMenu->addAction(importer);
		// mam si udrzovat seznam pointru pro dealokaci nebo si to dela samo?
		++it;
	}
}
void MainW::ImportFile() {
	QAction * action = qobject_cast<QAction *>(sender());
	QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), "", "");
	if (filename != "") {
		std::string a = action->data().toString().toStdString();
		std::cout << a << " " << filename.toStdString() << std::endl;
		importer_type::const_iterator importer = mm.importer[a];
		if (importer != mm.importer.end()) {
			//importer->second->load_from_file(filename.toStdString(), mainGraph);
		}
	}
}

void MainW::ExportFile() {
}
