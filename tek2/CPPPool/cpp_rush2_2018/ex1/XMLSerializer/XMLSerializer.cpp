/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** XMLSerializer.cpp
*/

#include "XMLSerializer.hpp"

XMLSerializer::XMLSerializer(Object *present) : _offset(0)
{
    static int index = 1;

    std::string fileName = "gift" + std::to_string(index) + ".xml";
    std::ofstream presentFile;
    presentFile.open(fileName);
    if (presentFile.is_open()) {
        index++;
        writePaperTag(presentFile, present);
        presentFile.close();
    } else {
        std::cerr << "Error: failed to create file" << std::endl;
    }
}

void XMLSerializer::writeParam(std::ofstream &fileStream,
    const std::string &name, const std::string &value)
{
    fileStream << " " << name << "=\"" << value << "\"";
}

void XMLSerializer::writeParam(std::ofstream &fileStream,
    const std::string &name, bool value)
{
    fileStream << " " << name << "=\"" << std::boolalpha << value << "\"";
}

void XMLSerializer::writeOpen(std::ofstream &fileStream,
    const std::string &name)
{
    fileStream << std::string((unsigned long)_offset * 4, ' ') << "<" << name;
}

void XMLSerializer::writeClose(std::ofstream &fileStream,
    const std::string &name)
{
    fileStream << std::string((unsigned long)_offset * 4, ' ') << "</" << name
        << ">" << std::endl;
}

void XMLSerializer::writeChild(std::ofstream &fileStream,
    const std::string &child)
{
    fileStream << child << std::endl;
}

void XMLSerializer::writeToyTag(std::ofstream &fileStream, const Object *toy)
{
    if (!toy)
        return;
    writeOpen(fileStream, "toy");
    writeParam(fileStream, "title", toy->getTitle());
    std::string type = XMLSerializer::typeName[toy->getType()];
    writeParam(fileStream, "type", type);
    fileStream << ">" << std::endl;
    writeClose(fileStream, "toy");
}

void XMLSerializer::writePaperTag(std::ofstream &fileStream,
    const Object *paper)
{
    if (!paper)
        return;
    writeOpen(fileStream, "paper");
    writeParam(fileStream, "open", paper->isOpen());
    fileStream << ">" << std::endl;
    _offset++;
    writeBoxTag(fileStream, paper->getObject());
    _offset--;
    writeClose(fileStream, "paper");
}

void XMLSerializer::writeBoxTag(std::ofstream &fileStream, const Object *box)
{
    if (!box)
        return;
    writeOpen(fileStream, "box");
    writeParam(fileStream, "open", box->isOpen());
    fileStream << ">" << std::endl;
    _offset++;
    writeToyTag(fileStream, box->getObject());
    _offset--;
    writeClose(fileStream, "box");
}
