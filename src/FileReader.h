//
// Created by Wu_Yuanhun on 2019/10/26.
//

#ifndef CONFIGREADER_FILEREADER_H
#define CONFIGREADER_FILEREADER_H


#include <fstream>

class FileReader : public std::fstream
{
public:
    FileReader(const char* filename,
                std::ios_base::openmode);

    std::string readline();
};


#endif //CONFIGREADER_FILEREADER_H
