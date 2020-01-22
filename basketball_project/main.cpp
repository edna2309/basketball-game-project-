#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Windows.h"
#include "Game.h"
using std::cout;
using std::cin;

int main() 
{
	Game g;
	cin >> g;
	int x, firstOffense;
	srand(time(NULL));
	x = rand() % 2;
	firstOffense = x;
	system("pause");
	system("cls");
	cout << "*****************************************\n";
	cout << "\t     FIRST QUARTER \n";
	for (int i = 0; i < 20; i++)
	{
		cout << "-----------------------------------------\n";
		if (x == 0)
		{
			++g;
			x++;
			Sleep(1000);
		}
		else
		{
			g++;
			x--;
			Sleep(1000);
		}
	}
	cout << g;
	system("pause");
	system("cls");

	x = (firstOffense + 1) % 2;
	cout << "\t     SECOND QUARTER \n";
	for (int i = 0; i < 20; i++)
	{
		cout << "-----------------------------------------\n";
		if (x == 0)
		{
			++g;
			x++;
			Sleep(1000);
		}
		else
		{
			g++;
			x--;
			Sleep(1000);
		}
	}
	cout << g;
	system("pause");
	system("cls");

	x = (firstOffense + 1) % 2;
	cout << "\t     THIRD QUARTER \n";
	for (int i = 0; i < 20; i++)
	{
		cout << "-----------------------------------------\n";
		if (x == 0)
		{
			++g;
			x++;
			Sleep(1000);
		}
		else
		{
			g++;
			x--;
			Sleep(1000);
		}
	}
	cout << g;
	system("pause");
	system("cls");
	x = firstOffense;
	cout << "\t   FINAL QUARTER \n";
	for (int i = 0; i < 20; i++) {
		cout << "-----------------------------------------\n";
		if (x == 0) {
			++g;
			x++;
			Sleep(1000);
		}
		else {
			g++;
			x--;
			Sleep(1000);
		}
	}
	system("pause");
	system("cls");
	if (g.pointsHome > g.pointsAway)
	{
		cout << "\tThe winner is " << g.getHome().getClubName() << "!\n";
	}
	else
	{
		cout << "\tThe winner is " << g.getAway().getClubName() << "!\n";
	}
	cout << g;
	!g;
	system("pause");
	return 0;
}