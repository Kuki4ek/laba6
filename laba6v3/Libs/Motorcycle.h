#pragma once
#include "vechicle.h"
#include <string>
using namespace std;
class Motorcycle : public Vehicle {
protected:
	string HandlebarType;
	bool HasSidecar;
public:
	Motorcycle();
	~Motorcycle();
	string getHandlebarType();
	bool getHasSidecar();
	string getHasSidecarS();

	void setHandlebarType(string);
	void setHasSidecar(bool);
	void setHasSidecarS(string);

	string toString();
};