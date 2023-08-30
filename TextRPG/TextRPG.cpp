// programa para rolar dados em formato de rpg de mesa como por exemplo 1d20+5 ou 3d6 etc e dar o resultado

#include <iostream>

using namespace std;

int Random(int sides)
{
	/* initialize random seed: */
	static int n = 0;
	srand(time(NULL) + n);
	n++;

	return rand() % sides + 1;
}

int Roll()
{
	char ch;
	cin.get(ch);                       

	char num[10] = { 0 };            
	int i = 0;
	while (ch != 'd')
	{
		num[i] = ch;
		cin.get(ch);
		i++;
	}

	cin.get(ch);

	char faces[10] = { 0 };          
	int j = 0;
	while (strchr("\n+-*/", ch) == 0)
	{
		faces[j] = ch;
		cin.get(ch);
		j++;
	}

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
	
	int h = 0;
	while (strchr("\n+-*/", ch) == 0)
	{
		modifier[h] = ch;
		cin.get(ch);
		h++;
	}

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
	cout << "Use o \"X\" da janela do console para fechar o programa: \n";
	cout << "Escreva a rolagem de dado. Por exemplo 3d6 ou então 1d20+7: \n";
	while (true)
	{
		cout << "Resultado: " << Roll();
		cout << endl;
	}

	return 0;
}

