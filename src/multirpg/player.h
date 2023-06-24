#pragma once

#include <vector>
#include <string>

namespace multirpg {

class player {
public:
	static player& instance();

	void run(std::vector<std::string> args);
protected:
	player() = default;
};

}

