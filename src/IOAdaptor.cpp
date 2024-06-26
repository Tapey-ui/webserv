#include "IOAdaptor.hpp"
#include "colors.h"
#include <sstream>
#include <string>

IOAdaptor::IOAdaptor(void) : receivedRaw("")
{
}

IOAdaptor::IOAdaptor(const IOAdaptor &src)
{
	*this = src;
}

IOAdaptor &IOAdaptor::operator=(const IOAdaptor &rhs)
{
	this->receivedRaw = rhs.receivedRaw;
	return *this;
}

IOAdaptor::~IOAdaptor(void)
{
}

void IOAdaptor::receiveMessage(std::string raw)
{
	receivedRaw = raw;
}

std::string IOAdaptor::getMessageToSend(WebServer &ws, std::string port)
{
	(void)ws;
	(void)port;
	std::stringstream ss;
	ss << BGREEN << "Received message:\n"
	   << RESET << receivedRaw << BBLUE << "\nSending back: Hello, world!\n"
	   << RESET;
	return ss.str();
}

std::string IOAdaptor::getRaw() const
{
	return receivedRaw;
}

std::ostream &operator<<(std::ostream &os, const IOAdaptor &adaptor)
{
	os << BBLUE << "Message: " << RESET << std::endl
	   << adaptor.getRaw() << std::endl
	   << BBLUE << "End" << RESET << std::endl
	   << "----------------------------------------" << std::endl;
	return os;
}
