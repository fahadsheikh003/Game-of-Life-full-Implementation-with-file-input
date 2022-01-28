//Fahad Waheed

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

void Print(char grid[][30])
{
	cout << endl;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			cout << grid[i][j] << "  ";
		}
		cout << endl;
	}
}

void randomgrid(char grid[][30])
{
	srand(time(NULL));

	int x;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			x = rand() % 100;
			if (x < 60)
			{
				grid[i][j] = '*';
			}
			else
				grid[i][j] = ' ';
		}
	}

	cout << "Initially Grid: \n";
	Print(grid);
}

void fileinput(char grid[][30])
{
	fstream myfile;
	string filename;
file:
	cout << "Enter name of file you want to open: ";
	getline(cin, filename);

	myfile.open(filename);

	if (!myfile.good())
	{
		cout << "\nSorry! file not found.\n";
		goto file;
	}

	string line;
	getline(myfile, line);
	
	int activecells = atoi(line.c_str());
	int x, y, pos;
	string xs, ys;

	for (int i = 0; i < activecells; i++)
	{
		getline(myfile, line);
		if (myfile.bad())
		{
			break;
		}
		pos = line.find(' ');
		xs = line.substr(0, pos);
		ys = line.substr(pos + 1);

		x = atoi(xs.c_str());
		y = atoi(ys.c_str());

		grid[x][y] = '*';
	}

	myfile.close();

	cout << "Initially Grid: \n";
	Print(grid);
}

void initialize(char grid[][30])
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			grid[i][j] = ' ';
		}
	}
}

void GameofLife(char grid[][30])
{
	int choice;
	do
	{
		cout << "Enter 1 if you want to closely observe changes..\n"
			<< "Enter 2 if you want to quickly run the program..\n"
			<< "Enter your choice: ";
		cin >> choice;
		cin.ignore();
	} while (choice < 1 || choice>2);

	char newgrid[30][30];
	initialize(newgrid);

	int count = 0;
	int generation = 0;

	while (true)
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if (i == 0 && j == 0)
				{
					if (grid[i][j + 1] == '*')
						count++;
					if (grid[i + 1][j] == '*')
						count++;
					if (grid[i + 1][j + 1] == '*')
						count++;
				}

				else if (i == 0 && j == 29)
				{
					if (grid[i][j - 1] == '*')
						count++;
					if (grid[i + 1][j] == '*')
						count++;
					if (grid[i + 1][j - 1] == '*')
						count++;
				}
				
				else if (i == 29 && j == 0)
				{
					if (grid[i][j + 1] == '*')
						count++;
					if (grid[i - 1][j] == '*')
						count++;
					if (grid[i - 1][j + 1] == '*')
						count++;
				}

				else if (i == 29 && j == 29)
				{
					if (grid[i][j - 1] == '*')
						count++;
					if (grid[i - 1][j] == '*')
						count++;
					if (grid[i - 1][j - 1] == '*')
						count++;
				}

				else if (i == 0)
				{
					if (grid[i][j - 1] == '*')
						count++;
					if (grid[i][j + 1] == '*')
						count++;
					if (grid[i + 1][j - 1] == '*')
						count++;
					if (grid[i + 1][j] == '*')
						count++;
					if (grid[i + 1][j + 1] == '*')
						count++;
				}

				else if (i == 29)
				{
					if (grid[i][j - 1] == '*')
						count++;
					if (grid[i][j + 1] == '*')
						count++;
					if (grid[i - 1][j - 1] == '*')
						count++;
					if (grid[i - 1][j] == '*')
						count++;
					if (grid[i - 1][j + 1] == '*')
						count++;
				}

				else if (j == 0)
				{
					if (grid[i + 1][j] == '*')
						count++;
					if (grid[i - 1][j] == '*')
						count++;
					if (grid[i - 1][j + 1] == '*')
						count++;
					if (grid[i][j + 1] == '*')
						count++;
					if (grid[i + 1][j + 1] == '*')
						count++;
				}

				else if (j == 29)
				{
					if (grid[i + 1][j] == '*')
						count++;
					if (grid[i - 1][j] == '*')
						count++;
					if (grid[i - 1][j - 1] == '*')
						count++;
					if (grid[i][j - 1] == '*')
						count++;
					if (grid[i + 1][j - 1] == '*')
						count++;
				}

				else
				{
					if (grid[i - 1][j - 1] == '*')
						count++;
					if (grid[i - 1][j] == '*')
						count++;
					if (grid[i - 1][j + 1] == '*')
						count++;
					if (grid[i][j - 1] == '*')
						count++;
					if (grid[i][j + 1] == '*')
						count++;
					if (grid[i + 1][j - 1] == '*')
						count++;
					if (grid[i + 1][j] == '*')
						count++;
					if (grid[i + 1][j + 1] == '*')
						count++;
				}
				
				if (grid[i][j] == '*' && count <= 1)//underpopulation
					newgrid[i][j] = ' ';
				else if (grid[i][j] == '*' && count <= 3)//just right
					newgrid[i][j] = '*';
				else if (grid[i][j] == '*' && count > 3)//overpopulation
					newgrid[i][j] = ' ';
				else if (grid[i][j] == ' ' && count == 3)//reproduction
					newgrid[i][j] = '*';

				count = 0;
			}
		}

		cout << "\n\nGeneration: " << ++generation << endl << endl;
		Print(newgrid);

		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				grid[i][j] = newgrid[i][j];
			}
		}

		if (choice == 1)
		{
			cout << "\nPress Enter to Continue..\n";
			cin.get();
		}
		
	}
}

int main()
{
	char grid[30][30];

	int choice;
	do
	{
		cout << "Enter 1 if you want to take input from file..\n"
			<< "Enter 2 if you want to randomly initialize grid..\n"
			<< "Enter your choice: ";
		cin >> choice;
		cin.ignore();
	} while (choice < 1 || choice>2);

	switch (choice)
	{
	case 1:
	{
		initialize(grid);
		fileinput(grid);
		break;
	}
	case 2:
	{
		randomgrid(grid);
	}
	}

	GameofLife(grid);
}