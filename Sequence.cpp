// Sequence.cpp
#include <array>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
#include "Sequence.h"
#include "PostScript.h"

// Print the contents of an array.
void Sequence::print(PostScript & out, int x, int newLine, int *y)
{
  std::ostringstream buffer;
  std::string bufferNum = "";

  buffer << "Array a[" << ARRAY_SIZE << "]= ";
  out.text(buffer.str(), x, *y);
  *y -= newLine; // prepare *y for next line down

	// Print contents of array to PostScript file.
  for (int i = 0; i < ARRAY_SIZE; i++) {
    std::ostringstream bufferNumTemp;

		// Split array contents up by columns of BREAK and print.
    if ((i % (ARRAY_SIZE / NUM_ROWS)) == 0 && i > 0) {
      out.text(bufferNum, x, *y); // output numbers
      *y -= newLine;              // create newline after every breakpoint
      bufferNum = "";
    }

    bufferNumTemp << arr[i] << " ";

		// Append bufferNum with bufferNumTemp.
    bufferNum += bufferNumTemp.str(); 
  }

	// Output whatever is left of bufferNum.
  out.text(bufferNum, x, *y);
  *y -= newLine;
} 

// Populate an array with pseudo-random numbers.
std::array<int, ARRAY_SIZE> Sequence:: makeArr()
{
  time_t t;
    
  srand(time(&t));
  for (auto &element : arr)                              // populate array with integers
    element = ((rand() % (NUM_RANGE * 2)) - NUM_RANGE);  // less than or equal to NUM_RANGE
  return arr;
}

// Determine the largest contiguous sum in an array.
int Sequence::getMaxSubsum() 
{
  int thisSum = 0;
    
  maxSubsum = 0;
  for (auto &element : arr) {
    thisSum += element;
  if (thisSum > maxSubsum) 
    maxSubsum = thisSum;
  else if (thisSum < 0) 
    thisSum = 0;
  }
  return maxSubsum;
}
