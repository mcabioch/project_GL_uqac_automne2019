#include <QApplication>

#include "ConnectWindow.h"

int main(int argc, char** argv) {
	mcd::arguments.addProg(argc, argv);

	QApplication app(argc, argv);
	mcd::logger.init("res/log.conf");

	MainWindow w;
	w.hide();

	ConnectWindow cw(w);
	cw.show();

	SigninWindow sw(&cw);
	sw.hide();

	cw.link(&sw);

	return app.exec();
}
