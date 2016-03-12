#include "Scoreboard.h"
#include "HangmanGame.h"
#include "SecretWord.h"
#include <iostream>
#include <string>
#include <ctime>


// ej, C++ mi e lubimia ezik za pisane, egati kolko e yakoooooooooooo, daze bachka pod linux ama se kompilira trudno na gcc
int main()
{

    HangmanGame & game = HangmanGame::InitHangmanGame();

    srand(time(0));

    game.StartGame();

   


    return 0;
}