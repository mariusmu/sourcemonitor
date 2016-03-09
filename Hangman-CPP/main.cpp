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

    //	game.StartGame();

    /*
    SecretWord w( "andrey");

    while ( !w.IsRevealed() )
    {
    std::cout << "enter : ";
    char l;
    std::cin >> l;

    if ( w.HasLetter(l) )
    w.RevealLetter( l );
    else
    std::cout << "no\n";

    std::cout << w.Encoded() << std::endl;


    }

    */

    //	we never get here

    /*
    while ( true )
    {
    std::cout << "mistakes : ";
    int m;
    std::string mm;

    std::getline( std::cin, mm );



    board.SignPlayerIn( atoi( mm.c_str() ) );
    board.Print();
    //		std::cout.width( 10 );

    }
    */


    return 0;
}