#include "QtFunctions.hpp"

QtWindow getDesktopSize(){
	QScreen *screen = QGuiApplication::primaryScreen();
	QRect geometry = screen->geometry();
	QtWindow out;

	out.h = geometry.height();
	out.w = geometry.width();

	return out;
}

size_t getDesktopWidth(){
	return static_cast<size_t>(getDesktopSize().w);
}

size_t getDesktopHeight(){
	return static_cast<size_t>(getDesktopSize().h);
}

/* CSS */
std::string cssReader(std::string path){
	std::ifstream reader;
	reader.open(path.c_str());

	return mcd::implode(mcd::getlines(reader), "\n");
}
/******/

void clearLayout(QLayout* layout){
	if(layout){
		while(layout->count()){
			auto item = layout->takeAt(0);
			layout->removeItem(item);
		}
	}
}
