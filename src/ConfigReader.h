//
// Created by Wu_Yuanhun on 2019/10/26.
//

#ifndef CONFIGREADER_CONFIGREADER_H
#define CONFIGREADER_CONFIGREADER_H

#include <string>
#include <map>

#include "FileReader.h"

class ConfigReader {
public:
    ConfigReader(const char* filename);
    explicit ConfigReader(std::string filename);
    ~ConfigReader();

    char* GetConfig(const char* name);
    char* operator[](const char* name);

    bool SetConfig(const char* name, const char* value);

    bool writeConfig(const char* filename = nullptr);

private:

    void loadFile(const char * filename);

    void praseLine(std::string line);

    bool m_isLoad;
    std::map<std::string, std::string> m_config_map;
    char* m_config_filename;
};


#endif //CONFIGREADER_C{}O{}NFIGREADER_H
