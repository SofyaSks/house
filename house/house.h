#include <iostream>
#include <time.h>
using namespace std;

class Wall {
public:

	Wall();

	void setWallAmount(int am);

	void CreateWalls();

	int totalWallPrice();

	int totalWallTime();


protected:
	int wallAmount;
	int wallTime;
	double wallPrice;
	string color;
	int* arr = new int[wallAmount];
};

class Window {
public:
	Window();

	void CreateWindows();

	double totalWindowPrice();

	int totalWindowTime();


	void setWindowAmount(int am);

	int getWindowAmount();

	virtual void makeWindow() = 0;


protected:
	int windowAmount;
	double windowPrice;
	int length;
	int width;
	int windowTime;
};

class Door {
public:
	Door();

	void createDoor();

protected:
	double doorPrice;
	bool doorhandle;
	int doorTime;
};

class Roof {
public:
	Roof();

	void createRoof();

protected:
	int roofTime;
	double roofPrice;
	string material;
};

class House : public Wall, public Window, public Door, public Roof {
public:
	House();

	void buildHouse(House tmp);

	void showHouse();

	void sumUp();

	void makeWindow();

};