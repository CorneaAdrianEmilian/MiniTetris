#include "MapAndObject.h"

MapAndObject::MapAndObject()
{
	rez = 0;
	oneRezColumn = 0;
}

MapAndObject::~MapAndObject()
{
	rules.clear();
}

const void MapAndObject::createObj(int& row, int& columns)
{
	for (int i = 0; i < row; i++) {
		std::string obj_create;
		std::cin >> obj_create;
		while (obj_create.size() != columns) {
			std::cout << "Incorect numbers of characters. Expected:" << columns << " characters\nTry again:\n";
			std::cin >> obj_create;
		}
		object.emplace_back(obj_create);
	}
}

const void MapAndObject::createMap(int& row, int& columns)
{
	for (int i = 0; i < row; i++) {
		std::string map_create;
		std::cin >> map_create;
		while (map_create.size() != columns) {
			std::cout << "Incorect numbers of characters. Expected:" << columns << " characters\nTry again:\n";
			std::cin >> map_create;
		}
		map.emplace_back(map_create);
	}
}
void MapAndObject::objRls( int& columns)
{
	std::vector<std::string>::iterator it;
	//we find the "rules" based on the first element of the object
	int firstR, firstC,nextR,nextC = 0, i = 0;
	bool first_index = true;
	for (it = object.begin(); it != object.end(); it++) {
		for (int j = 0; j < columns; j++)
		{
			//we add the indexes,row and column, of the first element with the others
			//based on what we get we find out if the rest of the elements are behind ahead or below the first one
			if ((*it).at(j) == '*') {
				if (first_index) {
					first_index = false;
					firstR = i; firstC = j;
					continue;
				}
				if (firstR == i)
					nextR = 0;
				else 
					nextR = abs(firstR - i);
				if (firstC == j)
					nextC = 0;
				else if (j - firstC < 0)
					nextC = j - firstC;
				else
					nextC = j-firstC;
				objIndexes* indx = new objIndexes(nextR, nextC);
				rules.emplace_back(indx);
			}
		}
		i++;
	}
}

void MapAndObject::spaceFinder(int& map_column)
{
	std::vector<std::string>::iterator it;
	std::vector<objIndexes*>::iterator ite = rules.begin();
	bool match = false;
	for (it = map.begin(); it != map.end(); it++) 
	{
		for(int i=0;i<map_column;i++)
		{
			if((*it).at(i)=='.')
			{
				//based on the first free space found in the map we search if the other elements indexes are available
				match = false;
				for(ite=rules.begin();ite!=rules.end();ite++)
				{
					if (it + (*ite)->getFirst() < map.begin())
						break;
					else if (i + (*ite)->getSecond() < 0)
						break;
					else if (it + (*ite)->getFirst() >= map.end())
						break;
					else if (i + (*ite)->getSecond() >= map_column)
						break;
					else
					{
						if ((*(it + (*ite)->getFirst())).at(i + (*ite)->getSecond()) != '.')
							break;
					}
					//at the end of iteration it is decided if the first element found free space for the entire object
					if (ite == rules.end() - 1) {
						match = true;
						//save indexes of the first element for later use
						oneRezRow = it;
						oneRezColumn = i;
					}
				}
				if(match)
					rez++;
			}
		}
	}
}

void MapAndObject::printSolution()
{//override the map to "place" the object in the map
//using the same logic of rules and the indexes we saved
	if(rez==1)
	{
		std::vector<objIndexes*>::iterator it;
		(*oneRezRow).at(oneRezColumn) = '*';
		for (it=rules.begin(); it != rules.end(); it++)
		{
			(*(oneRezRow + (*it)->getFirst())).at(oneRezColumn + (*it)->getSecond()) = '*';
		}
		for(int i=0;i<map.size();i++)
		{
			std::cout << map.at(i)<<std::endl;
		}
	}
}


