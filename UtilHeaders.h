#include <time.h>           // time
#include <cstdlib>          //srand
#include <iostream>         //cout / cin

class Utils
{
    public:

    Utils() {  srand(time(NULL));}

    // Returns a random number between the min and max inclusively.
    int GetWinProbablity(int min, int max)
    {
        int chance = rand() % max + min;
        return chance;
    }

    bool AmITheWinner(int myChange, int theirChance)
    {
        return myChange >= theirChance;
    }

    bool IsBetAllowed(int amount, int bet)
    {
        bool isAllowed =  bet<=amount && bet > 0;

        if (!isAllowed)
        {
            std::cout << "Bet amount not accepted, please re-enter a suitable bet." << std::endl;
        }

        return isAllowed;
    }

};