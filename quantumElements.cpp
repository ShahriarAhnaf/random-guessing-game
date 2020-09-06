// quantumElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

static random_device rd; 
static mt19937 rng(rd());

int RandElement()
{
    static std::uniform_int_distribution<int> elements(0, 19); // random dice
    return elements(rng); // use rng as a generator
}

//the game developer way?

int main()
{
   
    int compElement = 0;
    int tries = 0;
    string elements[20] = { "hydrogen", "helium", "lithium", "berylium", "boron", "carbon", "nitrogen", "oxygen", "flourine", "neon",
                    "sodium", "magnesium", "aluminium", "silicon", "phosphorus", "sulfur", "chlorine", "argon" };
    string guess = "";
    
    //using srand
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
//making the random number
    string compGuess = elements[RandElement()]; // to make the rand int compatible with the array.
    


    cout <<setw(40)<<"first 20 elements guesser\n";
    cout << "\n The computer will guess from these elements : \n";
    
    for (int i = 0; i < 19; i++)
    {
        if (i % 2 != 0)
        {
            cout << elements[i] << " \n";
        }
        else
        {
            cout << elements[i]<< "\t" ;
        }
    }


    cout << "\n Guess the same element as the computer! : ";
    cout << compGuess;
    while (guess != compGuess)
    {
        if (tries > 0)
        {
            cout << tries << " try. keep trying! :";
        }
        cin >> guess;
        tries++;
        
    }
   cout << "\n YOU WON! YOU CORRECTLY CAUGHT THE COMPUTER GUESSING :" << compGuess;


}