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
	return getDesktopSize().w;
}

size_t getDesktopHeight(){
	return getDesktopSize().h;
}

std::vector<std::string> explode(const std::string& in, char separator){
	std::vector<std::string> out;
	std::string part{""};

	for(auto c : in){
		if(c == separator){
			if(part != ""){
				out.push_back(part);
				part = "";
			}
		} else {
			part += c;
		}
	}

	if(part != ""){
		out.push_back(part);
	}

	return out;
}

std::vector<std::string> explode(const std::string& in, const std::string& c){
	std::vector<std::string> out;
	auto inside_in = in;
	size_t pos{0};

	while((pos = inside_in.find(c)) != std::string::npos){
		out.push_back(inside_in.substr(0, pos));
		inside_in = inside_in.substr(pos+c.size(), inside_in.size());
	}

	if(inside_in.size()){
		out.push_back(inside_in.substr(0, inside_in.size()));
	}

	return out;
}

std::vector<std::string> explode(const std::string& in, std::vector<std::string> cars){
	std::vector<std::string> out;
	std::string mask = "&*-/_=";
	auto inside_in = in;

	for(auto car : cars){
		inside_in = replace(inside_in, car, mask);
	}
	out = explode(inside_in, mask);

	return out;
}

/* Get the lines of a given input stream */
std::vector<std::string> getlines(std::ifstream& input){
	std::vector<std::string> out;

	if(!input){
		return out;
	}

	for(std::string line; std::getline(input, line); ){
		out.push_back(line);
	}

	input.close();

	return out;
}

std::string replace(const std::string& str, const std::string& from, const std::string& to, const replaceParams& params){
	std::regex str_regex;
	auto inside_from = from;
	auto inside_to = to;

	try {
		if(!params.regex){
			std::vector<std::pair<std::string, std::string>> masks = {
				{"\\\\", "\\\\"}, {"\\(", "\\("}, {"\\)", "\\)"}, {"\\[", "\\["}, {"\\]", "\\]"}, {"\\{", "\\{"}, {"\\}", "\\}"},
				{"\\.", "\\."}, {"\\*", "\\*"}, {"\\-", "\\-"}, {"\\|", "\\|"}, {"\\?", "\\?"}, {"\\+", "\\+"}, {"\\^", "\\^"},
				{"\\$", "\\$"}};

			for(auto mask : masks){
				inside_from = replace(inside_from, mask.first, mask.second, {true, false, false});
			}
		}

		if(params.word){
			inside_from = "([^a-zA-Z0-9_-])" + inside_from + "(?![a-zA-Z0-9_-])";
			inside_to = "$1" + inside_to;
		}

		if(params.insensitive){ str_regex.assign(from, std::regex_constants::icase); }
		else{ str_regex.assign(inside_from); }
	} catch(std::regex_error& e){
		std::cout << "Regex Error" << std::endl << "An error occured during the replacement in \n'" << str << "'\n where '" << inside_from << "' has to be replaced by '" << inside_to << "'\n" << e.what() << std::endl;
	}

	return std::regex_replace(str, str_regex, inside_to);
}

/* CSS */
std::string cssReader(std::string path){
	std::ifstream reader;
	reader.open(path.c_str());

	return implode(getlines(reader), "\n");
}
