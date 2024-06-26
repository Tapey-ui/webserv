
#include "webserv.h"

CustomException::CustomException(std::string errorMsg) : _errorMsg(errorMsg)
{
}

CustomException::~CustomException() throw()
{
}

const char *CustomException::what() const throw()
{
	return _errorMsg.c_str();
}
