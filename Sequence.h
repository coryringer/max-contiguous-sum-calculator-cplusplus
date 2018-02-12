// Sequence.h
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <array>
#include "PostScript.h"

const int ARRAY_SIZE = 100;
const int NUM_RANGE  = 60;
const int NUM_ROWS   = 4;

class Sequence {
private:
	std::array<int, ARRAY_SIZE> arr;
	int maxSubsum;
public:
	void print(PostScript &, int, int, int *);
	std::array<int, ARRAY_SIZE> makeArr();
	
	// Accessors
	int getMaxSubsum();
};

#endif
