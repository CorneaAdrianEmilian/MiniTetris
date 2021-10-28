#pragma once
#include <iostream>
#include<vector>
#include<string>
#include "objIndexes.h"
//class to manage the creation and manipulation of the "map" and "object"
class MapAndObject
{
	std::vector<std::string>object;
	std::vector<std::string>map;
	std::vector<objIndexes*> rules;
	//variable to count the number of solutions
	int rez;
	std::vector<std::string>::iterator oneRezRow;
	int oneRezColumn;
public:
	MapAndObject();
	~MapAndObject();
	void createObj(int& row, int& columns);
	void createMap(int& row, int& columns);
	//method to find a set of rules that the object follows to be created
	void objRls( int& columns);
	void spaceFinder(int& map_column);
	inline int getRez() { return rez;};
	void printSolution();
};

