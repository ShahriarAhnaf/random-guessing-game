// quantumElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
/*
static random_device rd; 
static mt19937 rng(rd());

int RandElement()
{
    static std::uniform_int_distribution<int> elements(0, 19); // random dice
    return elements(rng); // use rng as a generator
}
*/
//the game developer way?

int main()
{
   
    int compElement = 0;
    int tries = 0;
    int compguess = 0;
    bool gameFinished = false;
    int hint = 0;
    string elements[20] = { "hydrogen", "helium", "lithium", "beryllium", "boron", "carbon", "nitrogen", "oxygen", "flourine", "neon",
                    "sodium", "magnesium", "aluminium", "silicon", "phosphorus", "sulfur", "chlorine", "argon" };
    string guess = "";
    
    //using srand
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
//making the random number
    compguess = rand() % 19;
    string compGuess = elements[compguess]; // to make the rand int compatible with the array.
    
    if (compguess <= 1)
    {
        hint = 1;
    }
    else if (compguess > 1 && compguess <= 9)
    {
        hint = 2;
    }
    else
    {
        hint = 3;
    }

    cout <<setw(90)<<"FIRST 20 ELEMENTS GUESSER\n \t\t\t Guess the element in 5 tries!";
    cout << "\nThe computer will guess from these elements:\n";
    
    for (int i = 0; i < 19; i++)
    {
        if (i % 2 != 0)
        {
            cout << elements[i] << " \n";
        }
        else
        {
            cout << elements[i] << " \t\t\t";
        }
    }


    cout << "\n Guess the same element as the computer! : ";
    //cout << compGuess; testing purposes to see if computer actually guessing random elements

  //game loop
        while (!gameFinished)
        {
            if (tries > 0)
            {
                if (tries > 2)
                {
                    cout << "hint: its outer shell is the " << hint << " energy level. ";
                }
                cout << tries << " try. keep trying! :";
            } 
            cin >> guess;
            tries++;


            if (guess == compGuess)
            {
                gameFinished = true;
            }
            if (tries >= 5)
            {
                gameFinished = true;
            }
        }

        if (tries >= 5)
        {

            cout << "\n YOU LOST! YOU COULDNT GUESS THE ELEMENT WITHIN FIVE TRIES, \n The computer guessed :" << compGuess;

        }
        else
        {
            cout << "\n YOU WON! YOU CORRECTLY CAUGHT THE COMPUTER GUESSING :" << compGuess;
        }
}