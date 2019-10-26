//
// Created by Wu_Yuanhun on 2019/10/26.
//

#include "ConfigReader.h"

ConfigReader::ConfigReader(const char *filename)
{
    m_isLoad = false;
    loadFile(filename);
}

ConfigReader::ConfigReader(std::string filename)
{
    ConfigReader(filename.c_str());
}

ConfigReader::~ConfigReader() {}

char*
ConfigReader::GetConfig(const char *name)
{
    if(!m_isLoad)
        return nullptr;

    auto it = m_config_map.find(name);
    if(it != m_config_map.end())
        return (char*) it->second.c_str();
}

char*
ConfigReader::operator[](const char *name)
{
    return GetConfig(name);
}

bool
ConfigReader::SetConfig(const char* name, const char* value)
{
    if(!m_isLoad)
        return false;
    m_config_map[std::string(name)] = value;
    return true;
}

bool
ConfigReader::writeConfig(const char *filename)
{
    if(!m_isLoad)
        return false;
    if(filename == nullptr)
        filename = m_config_filename;

    std::fstream fp;
    fp.open(filename, std::ios::in);
    for (auto it = m_config_map.begin(); it != m_config_map.end(); it++)
    {
        fp <<  it->first
        << "="
        << it->second
        << "\n";
    }
    fp.close();

    return true;
}

void
ConfigReader::loadFile(const char * filename)
{
    FileReader fp(filename, std::ios_base::in|std::ios_base::out);
    while(!fp.eof())
    {
        praseLine(fp.readline());
    }
    m_isLoad = true;
}

void
ConfigReader::praseLine(std::string line)
{
    if(line.size() < 2 || line[0] == '#')
        return ;
    std::string name;
    std::string value;
    for(int i = 0;i < line.size(); i++)
    {
        if(line[i] == '=')
        {
            name = line.substr(0,i);
            value = line.substr(i+1, line.size());
            break;
        }
    }
    if(!name.empty())
        m_config_map[name] = value;
}