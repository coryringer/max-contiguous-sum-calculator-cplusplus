// main.cpp
#include <sstream>
#include <string>
#include <vector>
#include "Sequence.h"
#include "PostScript.h"

int main()
{
  const int X_COORD    = 40;            // x-coord of string to PostScript file
  const int PS_NEWLINE = 25;            // make new line down PostScript file
	int y = 750;                          // y-coord of string to PS file
  Sequence mySeq;                       // create mySeq
  PostScript file;
	std::string psFilename = "output.ps"; // PostScript filename
  std::ostringstream buffer;
  std::vector<std::string> heading = {"Program: Max Contiguous Sum Calculator",
  															      "Author: Cory Ringer",
  															      "Date: October 2017",
  															      "Output: PostScript file (.ps)",
  															      "Purpose: The purpose of this program is " 
  															      "to create an array a[] filled with random numbers ",
 		                        		      "and to determine the largest sum from a " 
	 														        "contiguous subsequence of a[].",
 		                    				      ""};
	// Populate mySeq.
  mySeq.makeArr();

	// Open PostScript file for writing.
  file.open(psFilename); 

  // Print to PostScript file.
  file.start();
  file.font("Courier", 10);

	// Print contents of 'heading' to PostScript file.
  for (auto & element : heading) { 
  	file.text(element, X_COORD, y);
  	y -= PS_NEWLINE; // skip to next line down
  }

	// Print mySeq to file.
  mySeq.print(file, X_COORD, PS_NEWLINE, &y); 
  y -= PS_NEWLINE;
  buffer << "From this array a[], " 
  		   	<< mySeq.getMaxSubsum() 
  		   	<< " is the largest contiguous sum.";
  file.text(buffer.str(), X_COORD, y);
  file.show();

	// Close PostScript file.
	file.close();
	
  return 0;
}
