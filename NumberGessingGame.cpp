#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <string>
#include <ctime>     // For time()
#include <algorithm> // For transform()

using namespace std;

class NumberGuessingGame
{
    string userName;
    int randomNumber;
    int userGuess;
    int attempts;

public:
    void Message()
    {
        cout << "...Welcome to the Number Guessing Game..." << endl;
        cout<<"Dear user! please enter name:";
        cin>>userName;
        cout <<userName<<" i have selected a random number for you previously, between 1-100." << endl;
        cout << "Can you guess the number (Yes/No)?" << endl;
        string consent;
        cin >> consent;
        // Convert input to lowercase for case-insensitive comparison
        transform(consent.begin(), consent.end(), consent.begin(), ::tolower);
        if (consent == "yes")
        {
            cout << "That's great! Let's start the game." << endl;
            StartGame();
        }
        else
        {
            cout << "Thank you for playing! Goodbye!" << endl;
        }
    }

private:
    void StartGame()
    {
        bool playAgain = true; 
        while(playAgain)
        {
            // Initialize random number and attempts
            attempts = 0;
            srand(time(0)); // Seed the random number generator
            randomNumber = rand()%100 + 1; // Random number between 1 and 100
            cout << "Enter your guess:" << endl;
            // Game loop
            while (true)
            {
                cin >> userGuess;
                attempts++;
                if (userGuess < randomNumber)
                {
                    cout << "Your guess is too low! Please, try again." << endl;
                }
                else if (userGuess > randomNumber)
                {
                    cout << "Your guess is too high! Please, try again." << endl;
                }
                else
                {
                    cout << "Congratulations! You guessed the number!" << endl;
                    cout << "You took " << attempts << " attempts to guess the number correctly." << endl;
                    cout << "The number was " << randomNumber << "." << endl;
                    break;
                }
            }
            // Ask if the user wants to play again
            cout << "Do you want to play again? (Yes/No)" << endl;
            string consent;
            cin >> consent;
            // Convert input to lowercase for case-insensitive comparison
            transform(consent.begin(), consent.end(), consent.begin(), ::tolower);
            if (consent != "yes")// Repeat the game if the user enters "yes"
            {
                cout << "Thank you for playing! Goodbye!" << endl;
                playAgain= false; // Exit the game loop
                break;
            }
          //  playAgain= false; // Exit the game loop
        } 
    }
};

int main()
{
    NumberGuessingGame game;
    game.Message();
    return 0;
}