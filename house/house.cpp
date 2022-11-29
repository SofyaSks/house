#include "house.h"

Wall::Wall() {
	wallPrice = 0;
	color = "0";
}

void Wall::setWallAmount(int am) {
	wallAmount = am;
}

void Wall::CreateWalls() {
	cout << "Enter wall price: ";
	cin >> wallPrice;
	cout << "Enter wall color: ";
	cin >> color;
	cout << "Enter time for making one wall (in minutes): ";
	cin >> wallTime;
}

int Wall::totalWallPrice() {
	return  wallPrice * wallAmount;
}

int Wall::totalWallTime() {
	return  wallTime * wallAmount;
}

Window::Window() {
	windowPrice = 0;
	length = 0;
	width = 0;
}

void Window::CreateWindows() {
	cout << "Enter window price: ";
	cin >> windowPrice;
	cout << "Enter window length: ";
	cin >> length;
	cout << "Enter window width: ";
	cin >> width;
	cout << "Enter time for making one window (in minutes): ";
	cin >> windowTime;
}

double Window::totalWindowPrice() {
	return windowAmount * windowPrice;
}

int Window::totalWindowTime() {
	return  windowTime * windowAmount;
}


void Window::setWindowAmount(int am) {
	windowAmount = am;
}

int Window::getWindowAmount() {
	return windowAmount;
}

Door::Door() {
	doorPrice = 0;
	doorhandle = 0;
}

void Door::createDoor() {
	cout << "Enter door price: ";
	cin >> doorPrice;
	cout << "Does it have a doorhandle? (0 - no / 1 - yes) -> ";
	cin >> doorhandle;
	cout << "Enter time for making a door (in minutes): ";
	cin >> doorTime;
}

Roof::Roof() {
	roofPrice = 0;
	material = "0";
}

void Roof::createRoof() {
	cout << "Enter roof price: ";
	cin >> roofPrice;
	cout << "Enter roof material: ";
	cin >> material;
	cout << "Enter time for making a roof (in minutes): ";
	cin >> roofTime;
}

House::House() {}

void House::buildHouse(House tmp) {
	int w, win;
	cout << "Enter windows amount: ";
	cin >> win;
	setWindowAmount(win);
	CreateWindows();
	cout << "Enter walls amount: ";
	cin >> w;
	setWallAmount(w);
	CreateWalls();
	createDoor();
	createRoof();

}

void House::showHouse() {
	cout << "\nWall amount: " << wallAmount << endl;
	cout << "Wall color: " << color << endl;
	cout << "Window amount: " << windowAmount << " size: " << length << "*" << width << endl;
	if (doorhandle == 1) {
		cout << "Door have a doorhandle" << endl;
	}
	else
		cout << "Door doesnt have a doorhandle" << endl;
	cout << "Roof material: " << material << endl;
}

void House::sumUp() {
	cout << "\nTotal price for the house: " << totalWindowPrice() + totalWallPrice() + doorPrice + roofPrice << endl;
	cout << "Total time for building: " << (totalWindowTime() + totalWallTime() + doorTime + roofTime) / 60 << " hours "
		<< (totalWindowTime() + totalWallTime() + doorTime + roofTime) % 60 << " minutes" << endl;
}

void House::makeWindow() {
	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= width; j++) {
			if (j > 1 && j < width && i > 1 && i < length) {
				cout << " ";
			}
			else
				cout << "*";
		}
		cout << endl;
	}

}