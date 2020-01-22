#pragma once
#include <iostream>
#include "Club.h"
using std::cin;
using std::cout;

class Game
{
private:
	char date[15];
	Club home;
	Club away;

public:
	static int pointsHome;
	static int pointsAway;
	Game() {};

	void setDate();
	void setHome();
	void setAway();

	char* getDate();
	Club& getHome();
	Club& getAway();

	friend std::istream& operator>>(std::istream& stream, Game& g);
	friend std::ostream& operator<<(std::ostream& stream, Game& g);

	void operator++();
	void operator++(int);
	void operator!();

	~Game() {};
};

