#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <iostream>
#include <fstream>

#include "AgentData.h"
#include "common.h"

class Parser:private Ucopyable
{	
	typedef enum TypeLine{id = 0, room, floor, type, configData, log}TypeLine;
public:
	Parser(const std::string& _configFileName);
	
	bool ParserLines(AgentData& _agentData);
private:
	const Parser::TypeLine ParseLine(const std::string& _line, std::string& _str)const;
	void getDataFromStr(const std::string& _line, const std::string& _delimiters, std::string& _str)const;
	void ConfigData(std::vector<EventKey>& _eventKeyVec, std::string& _data);
private:
	std::ifstream m_configFile;
};

#endif //__PARSER_H__
