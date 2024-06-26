
#pragma once
#include "ABlock.hpp"
#include <string>

class LocationBlock;

class ServerBlock : public ABlock
{
public:
	ServerBlock();
	ServerBlock(const ServerBlock &other);
	ServerBlock &operator=(const ServerBlock &other);
	~ServerBlock();

	void addPortsListeningOn(std::string port);
	void addServerName(std::string serverName);

	void addLocationBlock(std::string path, LocationBlock locationBlock);
	std::pair<std::string, LocationBlock> getLocationBlockPair(std::string basePath) const;

private:
	std::map<std::string, LocationBlock> _locationBlocks;
};

std::ostream &operator<<(std::ostream &os, const ServerBlock &serverBlock);

void print_vector(std::ostream &os, const std::vector<std::string> &vector);
