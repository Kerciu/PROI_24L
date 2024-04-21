#include "HtmlParser.h"
#include "C:\Users\Kacper\Desktop\Zadanie4\PROI24L_203_Kacper_Gorski\Zadanie4\rapidxml\rapidxml.hpp"
#include "C:\Users\Kacper\Desktop\Zadanie4\PROI24L_203_Kacper_Gorski\Zadanie4\rapidxml\rapidxml_utils.hpp"
#include <fstream>

Collection HtmlParser::parseFromFile() const
{
    Collection collection;

    rapidxml::file<> file(fileHandle.c_str()); // Open the file
    rapidxml::xml_document<> doc;
    doc.parse<0>(file.data()); // Parse file contents

    rapidxml::xml_node<>* SvgNode = doc.first_node("svg");

    for (rapidxml::xml_node<>* node = SvgNode->first_node(); node; SvgNode->next_sibling()) {
        std::string nodeName = node->name();


        if (nodeName == "rect") {
            // TODO
        }
        else if (nodeName == "line") {
            // TODO
        }
        else if (nodeName == "circle") {
            // TODO
        }
        else if (nodeName == "text") {
            // TODO
        }
    }

    return collection;
}

void HtmlParser::saveToSVG(const Collection& collection) const
{
}
