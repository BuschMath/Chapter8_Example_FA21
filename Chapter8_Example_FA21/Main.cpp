//#define NDEBUG
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cassert>

using namespace std;

void StartStatement();
void GameParmInput();
void RunGuesses(int rand_num_, int guesses_);
void RunAgain();

bool again;

int main()
{
	cout << "Welcome to the number guessing program!\n\n";
	cout << "For this program you will try to guess the number that I (the computer) come up with.\n";

	do
	{
		StartStatement();
		GameParmInput();
		RunAgain();
	} while (again);

	return 0;
}

void StartStatement()
{
	cout << "You will need to tell me which numbers you want to guess between and how many guesses you would like.\n";
}

void GameParmInput()
{
	int lower_bound;
	int upper_bound;
	int guesses;

	cout << "What is the lower bound of possible random numbers? ";
	cin >> lower_bound;

	cout << "\nWhat is the upper bound of possible random numbers? ";
	cin >> upper_bound;

	cout << "\nHow many guesses would you like? ";
	cin >> guesses;

	srand(time(NULL));
	int rand_num = rand() % upper_bound + lower_bound;

	assert(cin);

	RunGuesses(rand_num, guesses);
}

void RunGuesses(int rand_num_, int guesses_)
{
	for (int i = 0; i < guesses_; i++)
	{
		int guess;
		cout << "Guess number " << i + 1 << ". What is your guess? ";
		cin >> guess;

		if (guess == rand_num_)
		{
			cout << "\n\nCongrats! You guessed the number.\n\n";
			i = guesses_;
		}
		else
		{
			cout << "\nWrong!\n";

			if (i == guesses_ - 1)
			{
				cout << "The number is: " << rand_num_ << endl;
			}
		}
	}
}

void RunAgain()
{
	int again_input;
	cout << "Would you like to play again? Enter 1 for yes and 2 for no: ";
	cin >> again_input;

	switch (again_input)
	{
	case 1:	again = true;
		break;

	case 2:	again = false;
		break;

	default: cout << "Input error! Exiting program.\n\n";
		again = false;
		break;
	}
}