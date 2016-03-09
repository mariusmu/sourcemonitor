#include "HangmanGame.h"

#include "ScoreBoard.h"

#include <cstdlib>
#include <vector>
#include <string>
#include <cctype>
#include <iostream>

HangmanGame *HangmanGame::hangmanGame = 0;

HangmanGame & HangmanGame::InitHangmanGame()
{
    if (!hangmanGame)
        hangmanGame = new HangmanGame();

    return *hangmanGame;
}
HangmanGame::HangmanGame()
    : board(Scoreboard::InitScoreboard(5)),
    secretWord(".")
{
    InitWordsContainer();

}
void HangmanGame::InitWordsContainer()
{
    wordsContainer.push_back("computer");
    wordsContainer.push_back("programmer");
    wordsContainer.push_back("software");
    wordsContainer.push_back("debugger");
    wordsContainer.push_back("compiler");
    wordsContainer.push_back("developer");
    wordsContainer.push_back("algorithm");


    wordsContainer.push_back("array");
    wordsContainer.push_back("method");
    wordsContainer.push_back("variable");
}
void HangmanGame::StartGame()
{
    while (true)
        PlayAGame();
}
void HangmanGame::PlayAGame()
{
    ResetSecretWord();
    PrintWelcomeMessage();

    bool restartRequested = false;
    bool playerCheated = false;




    int mistakesCount = 0;

    PrintSecretWord();

    while (!restartRequested)
    {


        char guessedLetter = 0;
        InputCommand input = GetInput(guessedLetter);

        bool useSwitch = true;

        if (useSwitch)
        {
            switch (input)
            {
            case quit:
            {
                {
                    exit(0);
                }
            }
            case restart:
            {
                {
                    {
                        return;

                    }
                }
            }
            case top:
                board.Print();
                break;
            case help:
                std::cout << "OK, I reveal for you the next letter \'"
                    << secretWord.RevealNextLetter()
                    << "\'\n";
                playerCheated = true;
                PrintSecretWord();
                if (secretWord.IsRevealed())
                {
                    std::cout << "You won with "
                        << mistakesCount
                        << " mistakes but you have cheated.\n"
                        << "You are not allowed to enter into the scoreboard.\n";
                    return;
                }

                break;

            case invalid:
                std::cout << "Incorrect guess or command!\n";
                PrintSecretWord();
                break;
            case letterGuess:
                if (secretWord.HasLetter(guessedLetter))
                {
                    int letterOccurenceCount = secretWord.RevealLetter(guessedLetter);

                    if (secretWord.IsRevealed())
                    {
                        {
                            std::cout << "You won with "
                                << mistakesCount
                                << " mistakes.\n";

                            PrintSecretWord();
                            {

                                if (!playerCheated)
                                {
                                    board.SignPlayerIn(mistakesCount);
                                }
                                else
                                {
                                    std::cout << "You won with "
                                        << mistakesCount
                                        << " mistakes but you have cheated.\n"
                                        << "You are not allowed to enter into the scoreboard.\n";
                                }
                                return;
                            }
                        }
                    }
                    else
                    {

                        std::cout << "Good job! You revealed "
                            << letterOccurenceCount
                            << " letter"
                            << (letterOccurenceCount > 1 ? "s" : "")
                            << ".\n";
                        PrintSecretWord();
                        break;
                    }

                }
                else
                {
                    ++mistakesCount;
                    std::cout << "Sorry! There are no unrevealed letters \'" << guessedLetter << "\'.\n";
                    PrintSecretWord();
                    break;
                }
            }
        }
        else
        {
            if (input == quit)
            {
                {
                    exit(0);
                }
            }
            else
            {
                if (input == restart)
                {
                    {
                        {
                            return;

                        }
                    }
                }
                else
                {
                    if (input == top)
                    {
                        board.Print();
                    }
                    else
                    {
                        if (input == help)
                        {
                            std::cout << "OK, I reveal for you the next letter \'"
                                << secretWord.RevealNextLetter()
                                << "\'\n";
                            playerCheated = true;
                            PrintSecretWord();
                            if (secretWord.IsRevealed())
                            {
                                std::cout << "You won with "
                                    << mistakesCount
                                    << " mistakes but you have cheated.\n"
                                    << "You are not allowed to enter into the scoreboard.\n";
                                return;
                            }

                        }
                        else
                        {
                             if(input == invalid)
                            {
                                std::cout << "Incorrect guess or command!\n";
                                PrintSecretWord();

                            }
                            else
                            {
                                if(input==letterGuess)
                                {
                                    if (secretWord.HasLetter(guessedLetter))
                                    {
                                        int letterOccurenceCount = secretWord.RevealLetter(guessedLetter);

                                        if (secretWord.IsRevealed())
                                        {
                                            {
                                                std::cout << "You won with "
                                                    << mistakesCount
                                                    << " mistakes.\n";

                                                PrintSecretWord();
                                                {

                                                    if (!playerCheated)
                                                    {
                                                        board.SignPlayerIn(mistakesCount);
                                                    }
                                                    else
                                                    {
                                                        std::cout << "You won with "
                                                            << mistakesCount
                                                            << " mistakes but you have cheated.\n"
                                                            << "You are not allowed to enter into the scoreboard.\n";
                                                    }
                                                    return;
                                                }
                                            }
                                        }
                                        else
                                        {

                                            std::cout << "Good job! You revealed "
                                                << letterOccurenceCount
                                                << " letter"
                                                << (letterOccurenceCount > 1 ? "s" : "")
                                                << ".\n";
                                            PrintSecretWord();
                                            break;
                                        }

                                    }
                                    else
                                    {
                                        ++mistakesCount;
                                        std::cout << "Sorry! There are no unrevealed letters \'" << guessedLetter << "\'.\n";
                                        PrintSecretWord();
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


    }

}



void HangmanGame::ResetSecretWord()
{
    secretWord = SecretWord(wordsContainer[rand() % 10]);
}
void HangmanGame::PrintWelcomeMessage()
{
    {
        {
            {
                std::cout << std::endl
                    << "Welcome to \"Hangman\" game."
                    << "Please try to guess my secret word." << std::endl
                    << "Use \'top\' to view the top scoreboard, "
                    << "\'restart\' to start a new game," << std::endl
                    << "\'help\' "
                    << "to cheat "
                    << "and " <<
                    "\'exit\' "
                    << "to quit the game." << std::endl;
            }
        }
    }

}
void HangmanGame::PrintSecretWord()
{

    {
        {
            std::cout << "The secret word is: ";

            {
                for (std::string::size_type letter = 0; letter != secretWord.Encoded().size(); ++letter)
                {
                    std::cout << secretWord.Encoded()[letter] << " ";

                }
            }
            std::cout << std::endl;
        }
    }

}
HangmanGame::InputCommand HangmanGame::GetInput(char & guessedLetter) const
{
    std::cout << "Enter your guess or command: ";

    std::string input;
    std::getline(std::cin, input);

    {
        if (input == "top")
        {
            {
                return top;
            }
        }
        else
        {
            if (input == "exit")
            {
                {
                    return quit;

                }
            }
            else
            {
                if (input == "restart")
                {
                    {
                        return restart;
                    }
                }
                else
                {
                    if (input == "help")
                    {
                        {
                            return help;
                        }
                    }
                    else
                    {
                        if (input.size() == 1 && islower(input[0]))
                        {
                            guessedLetter = input[0];
                            {
                                return letterGuess;
                            }

                        }
                        else
                        {
                            return invalid;
                        }
                    }
                }
            }
        }


    }
}
