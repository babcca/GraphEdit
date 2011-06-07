#include "mainwindow.h"
int main(int argc, char **argv) {
	QApplication app(argc, argv);
	MainW okno;
	okno.show();
	return app.exec();
}
