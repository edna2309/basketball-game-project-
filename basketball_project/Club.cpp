#include "Club.h"

void Club::setClubName()
{
	cout << "Club name: ";
	cin.getline(this->clubName, 25);
}

void Club::setPlayer()
{
	Player p;
	cin >> p;
	this->players.push_back(p);
}

char* Club::getClubName()
{
	return this->clubName;
}

vector<Player>& Club::getPlayers()
{
	return this->players;
}

void Club::setDefault()
{
	strcpy_s(this->clubName, "Tigers");
	Player temp;
	temp.setDef("Loren", "Quack", 0, 1);
	this->players.push_back(temp);
	temp.setDef("Farris", "Walker", 0, 2);
	this->players.push_back(temp);
	temp.setDef("Nick", "Back", 0, 3);
	this->players.push_back(temp);
	temp.setDef("April", "Class", 0, 4);
	this->players.push_back(temp);
	temp.setDef("Rose", "Knight", 0, 5);
	this->players.push_back(temp);
}

std::istream& operator>>(std::istream& stream, Club& c)
{
	c.setClubName();
	for (int i = 0; i < 5; i++)
	{
		cout << "\n--------------Set player " << i + 1 << "--------------\n";
		c.setPlayer();
	}
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Club& c)
{
	stream << "\n\tClub name: " << c.getClubName() << "\n";
	for (int i = 0; i < 5; i++)
	{
		stream << "\tPlayer " << i + 1 << " " << c.getPlayers()[i] << "\n";
	}
	return stream;
}


