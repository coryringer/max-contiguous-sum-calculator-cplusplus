// PostScript.cpp
#include <string>
#include <fstream>
#include "PostScript.h"

// 'text' prints a string to a PostScript page and prints to file.
void PostScript::text(std::string str, int xCoord, int yCoord)   
{
	psfile << xCoord << " " << yCoord << " " << "moveto"
	       << std::endl << "(" << str << ") show" << std::endl;
}

// 'font' selects the font type and size for a string and prints to file.
void PostScript::font(std::string fontName, int fontSize) 										
{
	psfile << "/" << fontName << std::endl << fontSize
	       << " selectfont" << std::endl;
}
