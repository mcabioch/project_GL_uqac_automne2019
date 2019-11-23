#include <QApplication>

#include "ConnectWindow.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	mcd::logger.init("res/log.conf");

	MainWindow w;
	w.hide();

	ConnectWindow cw(w);
	cw.show();

	return app.exec();
}
