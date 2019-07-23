#include "Parser.h"

/**********************************************************************
						CTOR from STR
***********************************************************************/

Parser::Parser(const std::string& _configFileName)
:m_configFile(_configFileName.c_str())
{
}

/**********************************************************************
						privateFunc - getDataFromStr
***********************************************************************/

void Parser::getDataFromStr(const std::string& _line, const std::string& _delimiters, std::string& _str)const
{
	size_t pos = _line.find_first_of(_delimiters);
	_str = _line.substr(pos + 2); //"=" + " "
}

/**********************************************************************
						privateFunc - ParserConfigData
***********************************************************************/

void Parser::ConfigData(std::vector<EventKey>& _eventKeyVec, std::string& _data)
{
	std::string type;
	std::string floor;
	std::string room;
	
	std::size_t found = 0;
	std::size_t pos = _data.find_first_of("=");

	while(pos != std::string::npos)
	{
		found = _data.find_first_of(",", pos);
		type = _data.substr(pos + 1, found - pos - 1);
		
		pos = _data.find_first_of("=", found);
		found = _data.find_first_of(",", pos);
		floor = _data.substr(pos + 1, found - pos - 1);
		
		pos = _data.find_first_of("=", found);
		found = _data.find_first_of("|", pos);
		room = _data.substr(pos + 1, found - pos - 1);
		
		pos = _data.find_first_of("=", found);
		
		_eventKeyVec.push_back(EventKey(type, floor, room));
	}
	
}

/**********************************************************************
						privateFunc - ParseLine
***********************************************************************/

const Parser::TypeLine Parser::ParseLine(const std::string& _line, std::string& _str)const
{
	Parser::TypeLine ans = id;
	
	switch(_line[0])
	{
		case '[':
			_str = _line;
			ans = id;
			break;
		case 'r':
			getDataFromStr(_line, "=", _str);
			ans = room;
			break;
		case 'f':
			getDataFromStr(_line, "=", _str);
			ans = floor;
			break;
		case 't':
			getDataFromStr(_line, "=", _str);
			ans = type;
			break;
		case 'c':
			getDataFromStr(_line, "=", _str);
			ans = configData;
			break;
		case 'l':
			getDataFromStr(_line, "=", _str);
			ans = log;
			break;
	}
	return ans;
}

/**********************************************************************
						ParserLines
***********************************************************************/

bool Parser::ParserLines(AgentData& _agentData)
{
	std::string line;
	Parser::TypeLine typeLine;
	std::string str;
	
	getline(m_configFile, line);
	if(m_configFile.eof())
	{
		return 0;
	}
	
	while (!line.empty())
	{	
		typeLine = ParseLine(line, str);
		{
			switch(typeLine)
			{
				case id:
					_agentData.m_id = str;
					break;
				case room:
					_agentData.m_room = str;
					break;
				case floor:
					_agentData.m_floor = str;
					break;
				case type:
					_agentData.m_type = str;
					break;
				case configData:
					ConfigData(_agentData.m_configData, str);
					break;
				case log:
					_agentData.m_log = str;
					break;
			}
		}
		getline(m_configFile, line);
	}
	return 1;
}
