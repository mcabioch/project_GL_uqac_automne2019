#include <QApplication>

#include "ConnectWindow.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	mcd::logger.init("res/log.conf");

	ConnectWindow cw;

	cw.show();

	return app.exec();
}
