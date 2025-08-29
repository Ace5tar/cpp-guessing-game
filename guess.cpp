// https://www.geeksforgeeks.org/cpp/rand-and-srand-in-ccpp/

#include <iostream>

using namespace std;

int main() {
	// Whether or not the player is still playing
	bool playing = true;
	// What the correct number is
	int correctGuess = 0;
	// What the player has just guessed
	int currentGuess = 0;
	// Number of guesses
	int guessNum = 0;
	// The answer given when prompted whether or not to keep playing
	char stillPlayingAnswer = 'y';

	while(playing) {
		// Set the random seed based off of time	
		srand(time(NULL));
		// Generate a random number between 1 - 100
		correctGuess = (rand() % 100) + 1;
		// Set number of guesses to zero
		guessNum = 0;	

		cout << "I have my number, start guessing!" << endl;

		// Do while loop so that this runs at least once
		do {
			// Ask for guess
			cin >> currentGuess;
			// If guess is too high, say "Too high!"
			if (currentGuess > correctGuess){
			       cout << "Too high!" << endl;
			}
			// Otherwise, if guess is too low, say "Too low!"
			else if (currentGuess < correctGuess){
				cout << "Too low!" << endl;
			}	
			// Increase number of guesses
			++guessNum;	

			// Do this loop while the current guess is not the correct guess
		} while(!(currentGuess == correctGuess));
		cout << "That is correct! The number was " << correctGuess << endl;
		cout << "You guess the correct number in " << guessNum << " guesses!" << endl;
		cout << "Do you want to try again? (y/n)" << endl;
		// Ask if they want to keep playing
		cin >> stillPlayingAnswer;
		// If no, set playing to false
		if (stillPlayingAnswer == 'n') {playing = false;}	
	
	}
	return 0;
}
