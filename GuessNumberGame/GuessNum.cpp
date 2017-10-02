//Try to pick the same number as the computer!

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

bool Play(int);
void Stats(int, int);
int Options();


int main()
{
	char startup_option;
	bool result;				// result true = win, false = loss
	int max_number = 10;
	int games_won = 0;
	int games_played = 0;

	cout << "       Guess A Number Game" << endl << endl;

	do 
	{
		cout << "   --------------------------" << endl << endl;
		cout << "\t'P' = play" << endl;
		cout << "\t'S' = view stats" << endl;
		cout << "\t'O' = options" << endl;
		cout << "\t'Q' = quit" << endl << endl;

		cin >> startup_option;
		cout << endl;

		switch (startup_option)
		{
		case 'p':
		case 'P':
			result = Play(max_number);
			games_played++;
			if (result == true)
			{
				games_won++;
			}
			break;
		case 's':
		case 'S':
			Stats(games_won, games_played);
			break;
		case 'o':
		case 'O':
			max_number = Options();
			break;
		}
	} while (startup_option != 'q' && startup_option != 'Q');


	system("pause");
	return 0;
}

bool Play(int max)
{
	int user_choice;
	int computer_choice;

	bool same;

	cout << "Pick a number between 1 and " << max << ":  ";
	cin >> user_choice;

	srand(time(0));
	computer_choice = rand() % max + 1;		//computer's random number between one and chosen number (default 10)

	cout << endl << "Your Number: " << user_choice << endl;
	cout << "Computer's Number: " << computer_choice << endl << endl;

	if (user_choice == computer_choice)
	{
		same = true;
		cout << "You win! :)" << endl << endl;
	}
	else
	{
		same = false;
		cout << "You lose. :/" << endl << endl;
	}

	return same;


}

void Stats(int wins, int games)
{
	double percent;

	percent = ((double)wins / (double)games) * 100;

	cout << endl;

	cout << "Games Won:  " << wins << endl;
	cout << "Games Played:  " << games << endl;
	cout << "Win Percentage:  " <<  setprecision(2) << fixed << percent << "%" << endl;

	cout << endl;
}

int Options()
{
	int max;

	cout << "RANGE: Guess numbers between 1 and ___?  ";
	cin >> max;
	cout << endl;

	return max;
}