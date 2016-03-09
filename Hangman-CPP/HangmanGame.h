#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H

#include <vector>
#include <string>

#include "SecretWord.h"
#include "Scoreboard.h"


class HangmanGame
{
public:

	static HangmanGame & InitHangmanGame();


	void StartGame();

private:

	HangmanGame();
	HangmanGame( const HangmanGame & );
	HangmanGame & operator=( const HangmanGame & );

	static HangmanGame *hangmanGame;


	enum InputCommand { letterGuess, quit, restart, top, help, invalid };


	void PlayAGame();


	void InitWordsContainer();
	void ResetSecretWord();


	void PrintWelcomeMessage();
	void PrintSecretWord();

	InputCommand GetInput( char & guessedLetter ) const;






	
	

	Scoreboard & board;
	SecretWord secretWord;
	std::vector< std::string > wordsContainer;
};





#endif