#include <iostream>
#include <string>

#include "UtilHeaders.h"

int main()
{
    int amountOfMoney = 100;
    bool isPlaying = true;

    std::cout << "LeGreg vs Vestopphim" << std::endl;
    while(isPlaying)
    {
            int bet;
            Utils m_utility = Utils();
            
            std::cout << "Place your bet on LeGreg...." << std::endl;
            bool isBetAllowed = false;
            do
            {
                std::cin >> bet;
                isBetAllowed = m_utility.IsBetAllowed(amountOfMoney, bet);
            }
            while(!isBetAllowed);
           

            int redCarProb =  m_utility.GetWinProbablity(1, 100);
            int blueCarProb = m_utility.GetWinProbablity(1,100);

            std::cout << "[DEBUG] LeGreg chances : "  << redCarProb << " | Verstopphim chances : " << blueCarProb << std::endl;

            bool isWinner = m_utility.AmITheWinner(redCarProb, blueCarProb);
            std::string message = isWinner ? "LeGreg won!" : "Verstopphim couldn't be stopped.";

            if (isWinner)
            {
                amountOfMoney += bet;
            }
            else 
            {
                amountOfMoney -= bet;
            }


            std::cout << message << std::endl;
            std::cout << "Current amount : " << amountOfMoney << std::endl;

            isPlaying = amountOfMoney <= 0 ? false : true;

            char input;


            if (isPlaying && (input != 'y' || input != 'n'))
            {
            
                std::cout << "Would you like to bet again?";
                std::cin >> input;
            }

            if (input == 'n')
            {
                isPlaying = false;
            }
    }
   
    
    return 0;
}










