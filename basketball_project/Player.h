#pragma once
#include <iostream>

using std::cin;
using std::cout;

enum Position { PG = 1, SG, SF, F, C };

class Player
{
private:
	char name[20];
	char lastName[30];
	int points;
	Position position;
public:
	Player();
	Player(char* n, char* l, int p, Position pos);

	void setName();
	void setLastName();
	void setPoints(int a);
	void setPosition();

	void setDef(const char* n, const char* l, int p, int pos);

	char* getName();
	char* getLastName();
	int getPoints();
	Position getPosition();

	friend std::istream& operator>>(std::istream& stream, Player& p);
	friend std::ostream& operator<<(std::ostream& stream, Player& p);

	~Player() {};
};

