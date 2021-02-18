/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** XMLDeserializer.cpp
*/

#include "XMLDeserializer.hpp"
#include "../../ex1/XMLSerializer/XMLSerializer.hpp"
#include "../../ex1/Object/Toy/LittlePony.hpp"
#include "../../ex1/Object/Toy/Teddy.hpp"
#include "../../ex1/Object/Wrap/Box.hpp"
#include "../../ex1/Object/Wrap/Paper.hpp"

bool XMLDeserializer::isValidTag(const std::string &line,
    const std::string &tagName)
{
    std::regex tagRegex = std::regex(
        "^[ ]*<" + tagName + " *([a-z]+=\"[a-zA-Z0-9 ]*\" *)*>$");
    return std::regex_match(line, tagRegex);
}

const std::string XMLDeserializer::readParam(const std::string &line,
    const std::string &paramName)
{
    std::regex paramNameRegex = std::regex(
        "^[ ]*<.*" + paramName + "=\"([a-zA-Z0-9 ]*)\".*>$");
    std::smatch match;
    if (std::regex_search(line.begin(), line.end(), match, paramNameRegex)) {
        std::string *str = new std::string(match[1]);
        return *str;
    } else
        return "";
}

Object *XMLDeserializer::readPaperTag(std::ifstream &fileStream)
{
    std::string line;
    getline(fileStream, line);
    if (!isValidTag(line, "paper"))
        return nullptr;
    auto paper = new Paper(readBoxTag(fileStream));
    return paper;
}

Object *XMLDeserializer::readBoxTag(std::ifstream &fileStream)
{
    std::string line;
    getline(fileStream, line);
    if (!isValidTag(line, "box")) {
        std::cerr << "Error: invalid XML" << std::endl;
        std::cerr << ">>\t" << line << std::endl;
        return nullptr;
    }
    auto box = new Box(readToyTag(fileStream));
    return box;
}

Object *XMLDeserializer::readToyTag(std::ifstream &fileStream)
{
    std::string line;
    getline(fileStream, line);
    if (!isValidTag(line, "toy"))
        return nullptr;
    auto title = readParam(line, "title");
    auto type = readParam(line, "type");
    if (type == "pony")
        return new LittlePony(title);
    else
        return new Teddy(title);
}

Object *XMLDeserializer::openGift(const std::string &fileName)
{
    std::ifstream fileStream(fileName);
    if (fileStream.is_open()) {
        return readPaperTag(fileStream);
    } else {
        std::cerr << "Error: " << fileName << ": no such file found."
            << std::endl;
        return nullptr;
    }
}