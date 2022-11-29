#include "house.h"



int main() {
	srand(time(NULL));

	House h1;

	h1.buildHouse(h1);

	h1.showHouse();

	h1.sumUp();

	h1.makeWindow();

	return 0;
}