#include <iostream>
#include <time.h>
using namespace std;

class Wall {
public:

	Wall() {
		wallPrice = 0;
		color = "0";
	}

	void setWallAmount(int am) {
		wallAmount = am;
	}

	void CreateWalls() {
		cout << "Enter wall price: ";
		cin >> wallPrice;
		cout << "Enter wall color: ";
		cin >> color;
		cout << "Enter time for making one wall (in minutes): ";
		cin >> wallTime;
	}
	
	int totalWallPrice() {
		return  wallPrice * wallAmount;
	}

	int totalWallTime() {
		return  wallTime * wallAmount;
	}


protected:
	int wallAmount;
	int wallTime;
	double wallPrice;
	string color;
	int* arr = new int[wallAmount];
};

class Window {
public:
	Window() {
		windowPrice = 0;
		length = 0;
		width = 0;
	}

	void CreateWindows() {
		cout << "Enter window price: ";
		cin >> windowPrice;
		cout << "Enter window length: ";
		cin >> length;
		cout << "Enter window width: ";
		cin >> width;
		cout << "Enter time for making one window (in minutes): ";
		cin >> windowTime;
	}

	double totalWindowPrice() {
		return windowAmount * windowPrice ;
	}

	int totalWindowTime() {
		return  windowTime * windowAmount;
	}


	void setWindowAmount(int am) {
		windowAmount = am;
	}

	int getWindowAmount() {
		return windowAmount;
	}

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
	Door() {
		doorPrice = 0;
		doorhandle = 0;
	}

	void createDoor() {
		cout << "Enter door price: ";
		cin >> doorPrice;
		cout << "Does it have a doorhandle? (0 - no / 1 - yes) -> ";
		cin >> doorhandle;
		cout << "Enter time for making a door (in minutes): ";
		cin >> doorTime;
	}

protected:
	double doorPrice;
	bool doorhandle;
	int doorTime;
};

class Roof {
public:
	Roof() {
		roofPrice = 0;
		material = "0";
	}

	void createRoof() {
		cout << "Enter roof price: ";
		cin >> roofPrice;
		cout << "Enter roof material: ";
		cin >> material;
		cout << "Enter time for making a roof (in minutes): ";
		cin >>roofTime;
	}

protected:
	int roofTime;
	double roofPrice;
	string material;
};

class House : public Wall, public Window, public Door, public Roof {
public:
	House(){}

	void buildHouse(House tmp) {
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

	void showHouse() {
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

	void sumUp() {
		cout << "\nTotal price for the house: " << totalWindowPrice() + totalWallPrice() + doorPrice + roofPrice << endl;
		cout << "Total time for building: " << (totalWindowTime() + totalWallTime() + doorTime + roofTime) / 60 << " hours " 
			<< (totalWindowTime() + totalWallTime() + doorTime + roofTime) % 60 << " minutes" << endl;
	}

	void makeWindow() {
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

private:
};


int main() {
	srand(time(NULL));

	House h1;

	h1.buildHouse(h1);

	//h1.showHouse();

	//h1.sumUp();

	h1.makeWindow();

	return 0;
}