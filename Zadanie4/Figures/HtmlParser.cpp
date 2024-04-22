#include "HtmlParser.h"
#include "C:\Users\Kacper\Desktop\Zadanie4\PROI24L_203_Kacper_Gorski\Zadanie4\rapidxml\rapidxml.hpp"
#include "C:\Users\Kacper\Desktop\Zadanie4\PROI24L_203_Kacper_Gorski\Zadanie4\rapidxml\rapidxml_utils.hpp"
#include <fstream>

HtmlParser::HtmlParser() : fileHandle("") { }

HtmlParser::HtmlParser(const handle& fileHandle) : fileHandle(fileHandle) { }

void HtmlParser::saveToSVG(const Collection& collection) const
{
    std::ofstream output;
    output.open(fileHandle);

    if (!output.is_open()) { return; }

    output << collection;    
    output.close();
}

HtmlParser::handle HtmlParser::getFileName() {
    return fileHandle;
}

void HtmlParser::setFileName(const HtmlParser::handle& newFilename) {
    fileHandle = newFilename;
}