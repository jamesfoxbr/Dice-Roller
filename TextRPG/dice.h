#ifndef DICE_H

using namespace std;
#include <cstdlib>
#include <time.h>

class Dice {
protected:
	int sides;

public:
	int Sides()
	{
		return sides;
	}

	int Random()
	{
		/* initialize random seed: */
		static int n = 0;
		srand(time(NULL) + n);
		n++;

		return rand() % sides + 1;
	}

	int Roll(char ch)
	{
		cin.get(ch);                            // store initial string

		char num[10] = { 0 };                   // number of dices rolled
		char faces[10] = { 0 };                 // number of faces each dice have
		char symbol[1];                         // operator symbol ('+', '-', '*', '/')

		int i = 0;
		while (ch != 'd')
		{
			num[i] = ch;
			cin.get(ch);
			i++;
		}

		cin.get(ch);

		int j = 0;
		while (strchr("\n+-*/", ch) == 0)
		{
			faces[j] = ch;
			cin.get(ch);
			j++;
		}

		symbol[0] = ch;
		cin.get(ch);

		char modifier[10] = { 0 };

		int h = 0;
		while (strchr("\n+-*/", ch) == 0)
		{
			modifier[h] = ch;
			cin.get(ch);
			h++;
		}

		atoi(num);
		atoi(faces);
		symbol[0];
		atoi(modifier);

		int total = 0;
		switch (symbol[0])
		{
		case '+':
			for (int i = 0; i < atoi(num); i++)
			{
				total += Random();
			}
			break;
		}

		return total;
	}
		
};

#endif // !DICE_H

