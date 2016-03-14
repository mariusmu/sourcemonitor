//If the HangmanGame has not been defined before
#ifndef HANGMAN_GAME_H

//Then define the hangmanGame
#define HANGMAN_GAME_H

//Include the vector definition
#include <vector>

#include <map>

//Include the string definition
#include <string>

//Include the SecretWord definitions
#include "SecretWord.h"

//Include the scoreboard definition
#include "Scoreboard.h"

//Include cstdlib to use the converter methods
#include <cstdlib>

//Include cctype for checking types
#include <cctype>

//Inlcude the input outputstream for input from keyboard and output to the user
#include <iostream>

/**
	A simple hangman game
	1. Generate a secret word
	2. Ask the user for a charater
	3. Check if the secret word contain the charater if true, reveal the characters, if not reveal nothing
	4. If the whole secret word is revealed and the user has not cheated, add the user to the scorebord

	It is possible to cheat, but you cannot add your score to the storyboard in such case
**/
class HangmanGame
{
public:

	//The static HangmanGame object
	static HangmanGame & InitHangmanGame();

	//Method to start the game loop
	void StartGame();

private:

	//Constructor with no arguments
	HangmanGame();
	/*
		Constructor HangmanGame as argument
		@param HangmanGame 
	*/
	HangmanGame( const HangmanGame & );
	
	//Method overloading
	HangmanGame & operator = ( const HangmanGame & );

	//Pointer to the hangmangame
	static HangmanGame *hangmanGame;

	//Make an enum with different commands
	/*
		letterGuess	:	this is a letter guess
		quit		:	the program should exit
		restart		:	the program should restart
		top			:	show the storeboard
		help		:	show one of the hidden characters
		invalid		:	an invalid command has been enteret

	*/
	enum InputCommand { letterGuess, quit, restart, top, help, invalid };
	std::map< std::string, InputCommand > commands;

	void InitMap();
	//Start playing the game.
	void PlayAGame();

	/*
		Get help by revealing a character in the word
		@param	mistakesCount	the number of mistakes made (before)
	*/
	void Help(int mistakesCount);

	/*
		Finish the game, and print out a greeting
		@param	mistakesCount	the number of mistakes made
		@param	cheated	whether the user has cheated or not
	*/
	void GameFinish(int mistakesCount, bool cheated);

	/*
		Check if a user has entered one of the correct letters
		Reveal the correct letter, and if word completed, then end the game
		@param	secretWord	the secret word object
		@param	guessedLetter	the letter the user entered
		@param	mistakesCount	the number of mistakes made
		@param	playerCheated	whether the player cheated or not
		@return	1	if a new game should start
		@return	0	if the game should continue
	*/
	int Reveal(SecretWord & secretWord, char guessedLetter, int & mistakesCount, bool playerCheated);

	/*
		Initialize the word container with secret words
	*/
	void InitWordsContainer();

	/*
		Reset the secret word
	*/
	void ResetSecretWord();


	/*
		Print a welcome message (greeting) to the user
		Before the game starts
	*/
	void PrintWelcomeMessage();

	/*
		Print the secret word
	*/
	void PrintSecretWord();

	/*
		Get one character from the user input.
		To be used within the game as a command or guessed character
		@param	guessedLetter	the letter the user guessed
		@return InputCommand	enum
	*/
	InputCommand GetInput( char & guessedLetter ) const;


	//The scoreboard
	Scoreboard & board;
	
	//The secret word
	SecretWord secretWord;
	
	//The secret word container
	std::vector< std::string > wordsContainer;
};

#endif