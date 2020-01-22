#include "Player.h"

Player::Player()
{
	strcpy_s(this->name, "No");
	strcpy_s(this->lastName, "Nobody");
	this->points = 0;
	this->position = PG;
}

Player::Player(char* n, char* l, int p, Position pos)
{
	strcpy_s(this->name, n);
	strcpy_s(this->lastName, l);
	this->points = p;
	this->position = pos;
}

void Player::setName()
{
	cout << "First name: ";
	cin.getline(this->name, 20);
}

void Player::setLastName()
{
	cout << "Last name: ";
	cin.getline(this->lastName, 30);
}

void Player::setPoints(int a)
{
	this->points += a;
}

void Player::setPosition()
{
	std::shared_ptr<int> x = std::make_shared <int>();
	do
	{
		cout << "Position (PG=1 | SG=2 | SF=3 | F=4 | C=5): ";
		cin >> *x;
		cin.ignore();
		if (*x < 1 || *x>5)
		{
			cout << "[ERROR] Repeat entry!\n";
		}
		else
		{
			this->position = Position(*x);
		}
	} while (*x < 1 || *x > 5);
}

void Player::setDef(const char* n, const char* l, int p, int pos)
{
	strcpy_s(this->name, n);
	strcpy_s(this->lastName, l);
	this->points = p;
	this->position = Position(pos);

}

char* Player::getName()
{
	return this->name;
}

char* Player::getLastName()
{
	return this->lastName;
}

int Player::getPoints()
{
	return this->points;
}

Position Player::getPosition()
{
	return this->position;
}

std::istream& operator>>(std::istream& stream, Player& p)
{
	p.setName();
	p.setLastName();
	p.setPosition();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Player& p)
{
	stream << "Name: " << p.getName() << " " << p.getLastName();
	stream << "\n\tPosition: ";
	switch (p.getPosition())
	{
	case PG:
		stream << "PG\n";
		break;
	case SG:
		stream << "SG\n";
		break;
	case SF:
		stream << "SF\n";
		break;
	case F:
		stream << "F\n";
		break;
	case C:
		stream << "C\n";
		break;
	}
	stream << "\tPoints: " << p.getPoints() << "\n";
	return stream;
}
