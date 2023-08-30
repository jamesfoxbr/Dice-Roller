// This code is a RPG tabletop dice roller. The user inputer a valid rpg roll format and the software will roll the results.
// Example of valid rolls formates:
// 1d6, 2d6, 1d8, 1d10, 1d12, 1d20, 3d6+4, 1d8-1, 10d6*3, 5d10/2, etc..

#include <iostream>
#include <random>

using namespace std;

// generate pseudo random numbers
int Random(int sides)
{
	mt19937 mt(time(nullptr));

	std::uniform_int_distribution<> dice{ 1, sides };

	return dice(mt);
}

// get the user string input and transforms into usabe dice data. 
// the user inpute need to be a valide rpg tabletop dice format like 1d10 or 1d8+3 etc
int Roll()
{
	char ch;
	cin.get(ch);                       

	// gets all numbers bedore de "d" from the user string input
	// example in 2d20+5 gets the 2
	char num[10] = { 0 };            
	int i = 0;
	while (ch != 'd')
	{
		num[i] = ch;
		cin.get(ch);
		i++;
	}

	cin.get(ch);

	// gets all numbers after de "d" from the user string input but before the modifier symbols.
	// example in 1d20+5 gets the 20
	char faces[10] = { 0 };          
	int j = 0;
	while (strchr("\n+-*/", ch) == 0)
	{
		faces[j] = ch;
		cin.get(ch);
		j++;
	}

	// gets what is the modifier symbol
	// example in 1d20+5 gets the +
	char symbol[1];
	char modifier[10] = { 0 };

	if (ch == '\n')
	{
		symbol[0] = '+';
		modifier[0] = '0';
	}
	else 
	{
		symbol[0] = ch;
		cin.get(ch);
	}
	
	//gets the modifier number after the symbol
	// example in 1d20+5 gets the 5
	int h = 0;
	while (strchr("\n+-*/", ch) == 0)
	{
		modifier[h] = ch;
		cin.get(ch);
		h++;
	}

	// checks what symbol was used to make the right operation.
	int total = 0;
	switch (symbol[0])
	{
		case '+':
			for (int i = 0; i < atoi(num); i++)
			{
				total += Random(atoi(faces));
			}
			total += atoi(modifier);
			break;
		case '-':
			for (int i = 0; i < atoi(num); i++)
			{
				total += Random(atoi(faces));
			}
			total -= atoi(modifier);
			break;
		case '*':
			for (int i = 0; i < atoi(num); i++)
			{
				total += Random(atoi(faces));
			}
			total *= atoi(modifier);
			break;
		case '/':
			for (int i = 0; i < atoi(num); i++)
			{
				total += Random(atoi(faces));
			}
			total /= atoi(modifier);
			break;
	}

	return total;
}

int main()
{
	cout << "Use \"X\" on top right of the window to exit the program: \n";
	cout << "Write some dice rool. Example 3d6 or 1d20+7: \n";
	while (true)
	{
		cout << "Resul: " << Roll();
		cout << endl;
	}

	return 0;
}

