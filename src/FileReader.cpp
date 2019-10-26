//
// Created by Wu_Yuanhun on 2019/10/26.
//

#include "FileReader.h"

FileReader::FileReader(const char* filename,
                         std::ios_base::openmode mode = ios_base::in|ios_base::out )
        : std::fstream(filename, mode)
{
}

std::string
FileReader::readline()
{
    std::string r = "";
    char tmp = '\0';

    while(true)
    {
        this->get(tmp);

        if(tmp == '\n' || this->eof())
            return r;
        else
            r.append(&tmp);
    }
    return r;
}