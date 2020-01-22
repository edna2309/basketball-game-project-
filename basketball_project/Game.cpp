#include "Game.h"
#include <ctime>
#include <stdlib.h>
int Game::pointsHome = 0;
int Game::pointsAway = 0;

void Game::setDate()
{
	cout << "*****************************************\n";
	cout << "      Date of the game: ";
	cin.getline(this->date, 15);
	cout << "\n";
}

void Game::setHome()
{
	cout << "*****************************************\n";
	cout << "\t   Set the HOME club \n\n";
	cin >> this->home;
	cout << "*****************************************\n";
}

void Game::setAway()
{
	cout << "*****************************************\n";
	cout << "\t   Set the GUEST club \n\n";
	cin >> this->away;
	cout << "*****************************************\n";
}

char* Game::getDate()
{
	return this->date;
}

Club& Game::getHome()
{
	return this->home;
}

Club& Game::getAway()
{
	return this->away;
}

void Game::operator++()
{
	srand(time(NULL));
	int x = rand() % 4;

	if (x == 0)
	{

		cout << "\t" << this->getHome().getClubName() << " " << Game::pointsHome
			<< " : " << Game::pointsAway << " " << this->getAway().getClubName() << "\n";
		cout << "\tLost ball " << this->getHome().getClubName() << "!\n";

	}
	else
	{
		Game::pointsHome += x;
		cout << "\t" << this->getHome().getClubName() << " " << Game::pointsHome
			<< " : " << Game::pointsAway << " " << this->getAway().getClubName() << "\n";
		int y = rand() % 5;
		this->getHome().getPlayers()[y].setPoints(x);
		cout << "\t" << this->getHome().getClubName() << " || " << this->getHome().getPlayers()[y].getName() << " "
			<< this->getHome().getPlayers()[y].getLastName() << ": " << x << "p\n";

	}
}

void Game::operator++(int)
{
	srand(time(NULL));
	int x = rand() % 4;
	if (x == 0)
	{

		cout << "\t" << this->getHome().getClubName() << " " << Game::pointsHome
			<< " : " << Game::pointsAway << " " << this->getAway().getClubName() << "\n";
		cout << "\tLost ball " << this->getAway().getClubName() << "!\n";

	}
	else
	{
		Game::pointsAway += x;
		cout << "\t" << this->getHome().getClubName() << " " << Game::pointsHome
			<< " : " << Game::pointsAway << " " << this->getAway().getClubName() << "\n";
		int y = rand() % 5;
		this->getAway().getPlayers()[y].setPoints(x);
		cout << "\t" << this->getAway().getClubName() << " || " << this->getAway().getPlayers()[y].getName() << " "
			<< this->getAway().getPlayers()[y].getLastName() << ": " << x << "p\n";
	}
}

void Game::operator!()
{
	int max = INT_MIN;
	int index, team;
	for (int i = 0; i < 5; i++)
	{
		if (this->getHome().getPlayers()[i].getPoints() > max)
		{
			max = this->getHome().getPlayers()[i].getPoints();
			index = i;
			team = 0;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (this->getAway().getPlayers()[i].getPoints() > max)
		{
			max = this->getAway().getPlayers()[i].getPoints();
			index = i;
			team = 1;
		}
	}
	if (team == 0)
	{
		cout << "\tThe MVP of the game \n";
		cout << "-----------------------------------------\n";
		cout << "\t" << this->getHome().getPlayers()[index];
	}
	else if (team == 1)
	{
		cout << "\tThe MVP of the game \n";
		cout << "-----------------------------------------\n";
		cout << "\t" << this->getAway().getPlayers()[index];
	}
	cout << "*****************************************\n";
}

std::istream& operator>>(std::istream& stream, Game& g)
{
	g.setDate();
	g.setHome();
	system("pause");
	system("cls");
	cout << "\tWould you like to insert the guest club (YES - 1 || NO - 0)? ";
	int x;
	do
	{
		cout << "\n\n\t\t\tYour choice: ";
		cin >> x;
		if (x == 1)
		{
			g.setAway();
		}
		else if (x == 0)
		{
			g.getAway().setDefault();
		}
		if (x < 0 || x>1)
		{
			cout << "\t\t[ERROR] Repeat entry.\n";
		}
		cout << "\n";
	} while (x < 0 || x>1);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Game& g)
{
	stream << "*****************************************\n";
	stream << "\t" << g.getHome().getClubName() << " " << Game::pointsHome
		<< " : " << Game::pointsAway << " " << g.getAway().getClubName() << "\n";
	stream << "\n--------------" << g.getHome().getClubName() << "--------------\n";
	for (int i = 0; i < 5; i++)
	{
		stream << "\t" << g.getHome().getPlayers()[i] << "\n";
	}
	stream << "\n--------------" << g.getAway().getClubName() << "--------------\n";
	for (int i = 0; i < 5; i++)
	{
		stream << "\t" << g.getAway().getPlayers()[i] << "\n";
	}
	stream << "*****************************************\n";
	return stream;
}
