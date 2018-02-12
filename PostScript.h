// PostScript.h
#ifndef POSTSCRIPT_H
#define POSTSCRIPT_H

#include <fstream>
#include <string>

class PostScript {
private:
	std::ofstream psfile; 	
public:
	void text(std::string, int, int);
	void font(std::string, int);

	// inline functions
	void open(std::string fileName) { psfile.open(fileName); }
	void close() { psfile.close(); }
	void start() { psfile << "%%!PS" << std::endl; }   // writes the first line of a PostScript file 	
	void show() { psfile << "showpage" << std::endl; } // writes the last line of a PostScript 
													                           // file that shows the contents of the page
};

#endif
