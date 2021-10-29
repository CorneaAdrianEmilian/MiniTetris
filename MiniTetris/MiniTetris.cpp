// MiniTetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MapAndObject.h"
#include<memory>
int main()
{ 
	std::unique_ptr<MapAndObject> tetris = std::make_unique<MapAndObject>();
	int obj_rows,obj_columns, map_rows, map_columns = 0;
	std::cout << "Insert the rows and columns of the object\n";
	std::cin >> obj_rows >> obj_columns;
	std::cout << "Create the object using * as part of it and other character for space\n";
	std::cout << "Please insert characters within the limits you decided: Rows " << obj_rows << " Columns " << obj_columns <<std::endl;
	tetris->createObj(obj_rows, obj_columns);
	std::cout << "Insert the rows and columns of the Map\n";
	std::cin >> map_rows >> map_columns;
	std::cout << "Create the Map using . as a free to use space and # as used area\n";
	std::cout << "Please insert characters within the limits you decided: Rows " << map_rows << " Columns " << map_columns << std::endl;
	tetris->createMap(map_rows, map_columns);
	tetris->objRls(obj_columns);
	tetris->spaceFinder(map_columns);
	std::cout << "Numbers of solutions found: " << tetris->getRez() << std::endl;
	if (tetris->getRez() == 1) {
		std::cout << "Object set in place\n";
		tetris->printSolution();
	}
	
}

