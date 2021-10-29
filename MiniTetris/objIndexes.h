#pragma once
//class to store the indexes of the elements
class objIndexes
{
	int first;
	int second;
public:
	objIndexes(int a, int b);
	const inline int getFirst() { return first; };
	const inline int getSecond() { return second; };
	inline void setFirst(int a) { first = a; };
	inline void setSecond(int a) { second= a; };
};

