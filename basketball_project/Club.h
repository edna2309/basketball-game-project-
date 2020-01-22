#pragma once
#include <vector>
#include "Player.h"

using std::cin;
using std::cout;
using std::vector;

class Club
{
private:
	char clubName[25];
	vector<Player> players;
public:
	Club() {};

	void setClubName();
	void setPlayer();

	char* getClubName();
	vector<Player>& getPlayers();

	friend std::istream& operator>>(std::istream& stream, Club& c);
	friend std::ostream& operator<<(std::ostream& stream, Club& club);

	void setDefault();

	~Club() {};
};

