#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

using namespace std;

class XmlFile
{
private:
    const string FILE_NAME;
public:
    XmlFile(string fileName = "") :FILE_NAME(fileName) {};
    string getFileName() const
    {
        return FILE_NAME;
    }
};

#endif
