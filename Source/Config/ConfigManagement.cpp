#include "ConfigManagement.h"

//////////////////////////////////////////////////////////////
/// Constructor class
//////////////////////////////////////////////////////////////
ConfigManagement::ConfigManagement()
{
	//	File stream
	std::ifstream cFile;
    
    //	Opened
    fileFound = true;
    
    //  Open
	cFile.open(CONFIG_FILE_NAME);
    
    
	//	Check opened
	if (!cFile)
	{
		std::cout << "Error abriendo el archivo de configuración: " << strerror(errno) << "\n";
		fileFound = false;
	}

    if (fileFound)
    {
        //	Parse file
        std::string fileLine;
        while (std::getline(cFile, fileLine))
        {
            if (!isCommentLine(fileLine))
            {
                ParseLine(fileLine);
            }
        }

        //	Close file
        cFile.close();
    }
}

//////////////////////////////////////////////////////////////
/// Destructor class
//////////////////////////////////////////////////////////////
ConfigManagement::~ConfigManagement()
{

	fileFound = false;
	cMap.clear();

}

//////////////////////////////////////////////////////////////
/// Parse line get by file
//////////////////////////////////////////////////////////////
void ConfigManagement::ParseLine(std::string fileLine)
{
	if (ValidateLine(fileLine))
	{
		//	Find '='
		size_t sPos = fileLine.find('=');

		//	Get key
		std::string sKey   = fileLine.substr(0, sPos);

		//	Get value of key
		std::string sValue = fileLine.substr(sPos + 1);

		//	Insert on map
		if (!ExistKey(sKey))
		{
			cMap.insert(std::pair<std::string, std::string>(sKey, sValue));
		}
	}
}

//////////////////////////////////////////////////////////////
/// Validate config line
//////////////////////////////////////////////////////////////
bool ConfigManagement::ValidateLine(std::string fileLine)
{
	//	Find '='
	std::size_t sPos = fileLine.find('=');
	if (sPos == fileLine.npos)
		return false;

	//	Find space
	for (size_t i = sPos + 1; i < fileLine.length(); ++i)
	{
		if (fileLine[i] == ' ')
		{
			return false;
		}
	}

	return true;
}

//////////////////////////////////////////////////////////////
/// Key exist in map
//////////////////////////////////////////////////////////////
bool ConfigManagement::ExistKey(std::string sKey)
{

	return cMap.find(sKey) != cMap.end();

}

//////////////////////////////////////////////////////////////
/// Key value from map
//////////////////////////////////////////////////////////////
std::string ConfigManagement::GetConfigValue(std::string sKey)
{

	if (fileFound)
	{
		if (ExistKey(sKey))
		{
			return cMap.find(sKey)->second;
		}
	}

	return NULL;
}

//////////////////////////////////////////////////////////////
/// Check if the line is a comment
//////////////////////////////////////////////////////////////
bool ConfigManagement::isCommentLine(std::string sLine)
{

	return (sLine.find(';') != sLine.npos);

}














