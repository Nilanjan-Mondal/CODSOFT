
// NUMBER GUESING GAME

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

    int num, guess, tries = 0;
    srand(time(0));         // random number generator
    num = rand() % 100 + 1; // random number between 1 and 100

    cout << "\nGuess My Number Game\n\n";

    while (guess != num){
        cout << "Enter a guess between 1 and 100 : ";
        cin >> guess;
        tries++;

        if (guess > num)
            cout << "Too high!\n\n";
        else if (guess < num)
            cout << "Too low!\n\n";
        else
            cout << "\nCorrect! You got it in " << tries << " guesses!\n\n";
    } 

    return 0;
}