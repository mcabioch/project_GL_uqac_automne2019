#include <QApplication>

#include "ConnectWindow.h"

int main(int argc, char** argv) {
	mcd::arguments.addProg(argc, argv);

	QApplication app(argc, argv);
	mcd::logger.init("res/log.conf");

	Api api;
	if(!api.connection("192.168.0.169")){
		mcd::logs(mcd::Logger::Fatal, "Impossible to connect to the apis, check your network connection.");
	}

	MainWindow w(api);
	w.hide();

	ConnectWindow cw(w, api);
	cw.show();

	SigninWindow sw(&cw, api);
	sw.hide();

	cw.link(&sw);

#if AUTH_DEBUG
	cw.test("chef", "welcome1");
#endif

	return app.exec();
}
