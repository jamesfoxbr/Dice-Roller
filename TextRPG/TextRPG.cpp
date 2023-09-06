// This code is a RPG tabletop dice roller. The user inputer a valid rpg roll format and the software will roll the results.
// Example of valid rolls formates:
// 1d6, 2d6, 1d8, 1d10, 1d12, 1d20, 3d6+4, 1d8-1, 10d6*3, 5d10/2, etc..

// changed here

#include <iostream>
#include <random>

using namespace std;

class Dice
{
public:
	char ch;
	char faces[10] = { '0' };                           // number of faces in each dice. For example a commmon dices have 6 faces
	char symbol[1];                                     // the operator symbol used.
	char modifier[10] = { '0' };
	char num[10] = { 0 };
	int sides;
	int total = 0;                                      // store total result of all dices and the modifier
	int individualResult[100] = { 0 };                  // array to store individual dice results


	int Random(int sides)                               // generate pseudo random numbers
	{
		std::random_device rd;                          // a seed source for the random number engine
		std::mt19937 gen(rd());                         // mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> distrib(1, sides);

		return distrib(gen);
	}

	void numberOfDices()
	{
		// gets all numbers bedore de "d" from the user string input 
		int i = 0;
		while (ch != 'd' and strchr("\n123456789", ch) != 0)
		{
			num[i] = ch;
			cin.get(ch);
			i++;
		}
	}

	void numberOfFaces()
	{
		int j = 0;
		while (strchr("\n+-*/", ch) == 0)                   // gets number of faces after de "d" but before the modifier symbols.  
		{
			faces[j] = ch;
			cin.get(ch);
			j++;
		}
	}

	void placeSymbol()
	{
		if (ch == '\n')                                     // gets what is the modifier symbol. Example in 1d20+5 gets the +
		{
			symbol[0] = '+';
			modifier[0] = '0';
			faces[0] = '6';
		}
		else
		{
			symbol[0] = ch;
			cin.get(ch);
		}
	}

	void checkSymbol()
	{
		switch (symbol[0])                                  // check modifier symbol used 
		{
		case '+': total += atoi(modifier); break;
		case '-': total -= atoi(modifier); break;
		case '*': total *= atoi(modifier); break;
		case '/': total /= atoi(modifier); break;
		}
	}

	void diceModifier()
	{
		int h = 0;                                          //gets the modifier number after the symbol. Example in 1d20+5 gets the 5
		while (strchr("\n+-*/", ch) == 0)
		{
			modifier[h] = ch;
			cin.get(ch);
			h++;
		}
	}

	void diceCalculations()
	{

		for (int i = 0; i < atoi(num); i++)                 // print each individual dice result
		{
			int r = Random(atoi(faces));
			total += r;
			individualResult[i] = r;
		}
	}

	void printResults()
	{
		cout << "(";
		int s = 0;
		while (individualResult[s] != 0)
		{
			cout << individualResult[s];
			s++;

			if (individualResult[s] != 0)
				cout << ", ";
		}

		cout << ")";

		if (atoi(modifier) > 0)
			cout << symbol[0] << modifier;

		cout << " Total Result = " << total;
	}

	void roll()
	{
		cin.get(ch);
		numberOfDices();
		cin.get(ch);
		numberOfFaces();
		placeSymbol();
		checkSymbol();
		diceModifier();
		diceCalculations();
		printResults();
	}

};


int main()
{
	cout << "Use \"X\" on top right of the window to exit the program: \n";
	cout << "Write some dice rool. Example 3d6 or 1d20+7: \n";
	while (true)
	{
		Dice dice;

		dice.roll();
		cout << endl;
		cout << endl;
	}

	return 0;
}

