#include "Motorcycle.h"

Motorcycle::Motorcycle() {
	HandlebarType = "";
	HasSidecar = false;
}
Motorcycle::~Motorcycle() {
	HandlebarType = "";
	HasSidecar = false;
}

string Motorcycle::getHandlebarType() {
	return this->HandlebarType;
}
bool Motorcycle::getHasSidecar() {
	return this->HasSidecar;
}
string Motorcycle::getHasSidecarS() {
	if (HasSidecar) return "true";
	else return "false";
}

void Motorcycle::setHandlebarType(string type) {
	this->HandlebarType = type;
}
void Motorcycle::setHasSidecar(bool flag) {
	this->HasSidecar = flag;
}
void Motorcycle::setHasSidecarS(string flag) {
	if (flag == "true") this->HasSidecar = true;
	else this->HasSidecar = false;
}

string Motorcycle::toString() {
	return
		this->owner + "\n" +
		this->reg_number + "\n" +
		this->type + "\n" +
		this->brand + "\n" +
		to_string(this->volume) + "\n" +
		to_string(this->power) + "\n" +
		this->last_to + "\n" +
		to_string(this->mileage) + "\n" +
		HandlebarType + "\n" +
		this->getHasSidecarS() + "\n";
}