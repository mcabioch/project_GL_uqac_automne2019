#include "GeneralTab.hpp"

GeneralTab::GeneralTab(){
	
}

GeneralTab::~GeneralTab(){
	
}

GeneralTab::GeneralTab(const GeneralTab& other){
	*this = other;
}

GeneralTab& GeneralTab::operator=(const GeneralTab& other) noexcept {
	if(this == &other){ return *this; }

	

	return *this;
}

GeneralTab::GeneralTab(const GeneralTab&& other){
	*this = std::move(other);
}

GeneralTab& GeneralTab::operator=(const GeneralTab&& other) noexcept {
	if(this == &other){ return *this; }

	

	return *this;
}

