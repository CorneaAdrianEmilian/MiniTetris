// MiniTetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MapAndObject.h"
#include<memory>
int main()
{ 
	std::unique_ptr<MapAndObject> tetris = std::make_unique<MapAndObject>();
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cout << "Insert the rows and columns of the object";
	std::cin >> a >> b;
	std::cout << "Create the object using * as part of it and other character for space";
	std::cout << "Please insert characters within the limits you decided: Rows " << a << " Columns " << b <<std::endl;
	tetris->createObj(a, b);
	std::cout << "Insert the rows and columns of the Map";
	std::cin >> c >> d;
	tetris->createMap(c, d);
	std::cout << "Create the Map using . as a free to use space and # as used area";
	std::cout << "Please insert characters within the limits you decided: Rows " << c << " Columns " << d << std::endl;
	tetris->objRls(b);
	tetris->spaceFinder(d);
	std::cout << tetris->getRez();
	if (tetris->getRez() == 1)
		tetris->printSolution();
	
}

