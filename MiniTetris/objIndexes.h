#pragma once
//class to store the indexes of the elements
class objIndexes
{
	int first;
	int second;
public:
	objIndexes(int a, int b);
	inline int getFirst() { return first; };
	inline int getSecond() { return second; };
	inline void setFirst(int a) { first = a; };
	inline void setSecond(int a) { second= a; };
};

