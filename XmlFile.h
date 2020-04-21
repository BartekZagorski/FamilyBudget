#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

using namespace std;

class XmlFile
{
public:
    const string FILE_NAME;
public:
    XmlFile(string fileName) :FILE_NAME(fileName) {};
};

#endif
