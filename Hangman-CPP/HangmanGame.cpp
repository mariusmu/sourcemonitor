//Include the definitions
#include "HangmanGame.h"


//Set the hangmangGame pointer to be 0
HangmanGame *HangmanGame::hangmanGame = 0;

/*
	Initialize the HangmanGame
	@return	a pointer to the HangmanObject
*/
HangmanGame & HangmanGame::InitHangmanGame()
{
	//if the hangmanGame pointer is null
	if (!hangmanGame)
		//make a new hangManGame
		hangmanGame = new HangmanGame();

	//then return the pointer to the hangmanGame
	return *hangmanGame;
}

/*
	Constructor
	Initialize the ScoreBoard, the secret word and the wordsContainer
*/
HangmanGame::HangmanGame()
	: board(Scoreboard::InitScoreboard(5)),
	secretWord(".")
{
	//Initialize the wordContainer (vector)
	InitWordsContainer();

}

/*
	Initialize the wordscontainer with a suitable number of secret words
	Will use a vector to store the words
*/
void HangmanGame::InitWordsContainer()
{
	//push the secret word "computer" to the container
	wordsContainer.push_back("computer");
	
	//push the secret word "programmer" to the container
	wordsContainer.push_back("programmer");
	
	//push the secret word "software" to the container
	wordsContainer.push_back("software");
	
	//push the secret word "debugger" to the container
	wordsContainer.push_back("debugger");
	
	//push the secret word "compiler" to the container
	wordsContainer.push_back("compiler");
	
	//push the secret word "developer" to the container
	wordsContainer.push_back("developer");
	
	//push the secret word "algorithm" to the container
	wordsContainer.push_back("algorithm");
	
	//push the secret word "array" to the container
	wordsContainer.push_back("array");
	
	//push the secret word "method" to the container
	wordsContainer.push_back("method");
	
	//push the secret word "variable" to the container
	wordsContainer.push_back("variable");
}

/*
	A public method to start the game
*/
void HangmanGame::StartGame()
{
	//make an endless loop (so the game can continue if ended)
	while (true)
		//Start the game
		PlayAGame();
}

/*
	Get help by revealing a character in the word
	@param	mistakesCount	the number of mistakes made (before)
*/
void HangmanGame::Help(int mistakesCount) {
	//Print a secret letter to help the user
	std::cout << "OK, I reveal for you the next letter \'"
		<< secretWord.RevealNextLetter()
		<< "\'\n";

	//call for the method to print the secret word
	PrintSecretWord();

	//If the secret word is revealed, then end the game
	if (secretWord.IsRevealed())
	{
		GameFinish(mistakesCount, true);
	}
}
/*
	Finish the game, and print out a greeting
	@param	mistakesCount	the number of mistakes made
	@param	cheated	whether the user has cheated or not
*/
void HangmanGame::GameFinish(int mistakesCount, bool cheated) {
	
	//If the user has cheated, then he will not be on the scoreboard, and a message should be printed
	if (cheated) {
		std::cout << "You won with "
			<< mistakesCount
			<< " mistakes but you have cheated.\n"
			<< "You are not allowed to enter into the scoreboard.\n";
		return;
	}

	//If the user did not cheat, than print the greeting and sign the user in to the scoreboard
	else {
		//Print a greeting
		std::cout << "You won with "
			<< mistakesCount
			<< " mistakes.\n";
		
		//Sign the user in to the scoreboard
		board.SignPlayerIn(mistakesCount);
	}
}


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
int HangmanGame::Reveal(SecretWord & secretWord, char guessedLetter, int & mistakesCount, bool playerCheated) {
	
	//If the secret word contain the letter, then proceed
	if (secretWord.HasLetter(guessedLetter))
	{
		//Reveal the letter, and count how many occurencies found
		int letterOccurenceCount = secretWord.RevealLetter(guessedLetter);

		//If the secret word was revealed, end the game
		if (secretWord.IsRevealed())
		{
			//Call the game ending method
			GameFinish(mistakesCount, playerCheated);
			return 1;
		}

		//If the secret word has not been completely revealed, then procceed
		else
		{
			//Print a the letters revealed in the round
			std::cout << "Good job! You revealed "
				<< letterOccurenceCount
				<< " letter"
				//If the number of occurencies is above 1, then end the word with an additional s
				<< (letterOccurenceCount > 1 ? "s" : "")
				<< ".\n";

			//Then print the word as is
			PrintSecretWord();
		}

	}

	//If the word doesn't include the guessed letter
	else
	{
		//Increase the mistakes count
		++mistakesCount;
		
		//Print an information message
		std::cout << "Sorry! There are no unrevealed letters \'" << guessedLetter << "\'.\n";
		
		//Then print the word as is for now
		PrintSecretWord();
	}
	return 0;
}


/*
	Start playing the game
*/
void HangmanGame::PlayAGame()
{
	//Reset the secret word
	ResetSecretWord();

	//Print the welcome greeting message
	PrintWelcomeMessage();

	//Reset the restart status
	bool restartRequested = false;

	//Set the playerCheated as fale
	bool playerCheated = false;

	//Reset the mistakes count
	int mistakesCount = 0;

	//Print the secret word 
	PrintSecretWord();

	//This loop will terminate when the user request a restart or the secret word is revealed
	while (true)
	{
		//Reset the gussedLetter char (to be set in the GetInput)
		char guessedLetter = 0;

		//Get the input from the user as an InputCommand (enum)
		InputCommand input = GetInput(guessedLetter);

		//Switch based on the input
		switch (input)
		{
			//if quit
			case quit:
			{
				//then exit the program
				exit(0);
			}

			//if restart
			case restart:
			{
				//then restart the program by returning
				return;
			}

			//if top
			case top:
				//then print the scoreboard
				board.Print();

				break;
			
			//if help
			case help:
				//then set the player as cheated
				playerCheated = true;

				//Then reveal a word
				Help(mistakesCount);
				
				break;

			//if invalid
			case invalid:
				
				//Print a message telling the input was invalid
				std::cout << "Incorrect guess or command!\n";
				
				//Print the current status of the secret word
				PrintSecretWord();
				
				break;

			//if this is a letter guess
			case letterGuess:
				//Reveal the word, an pass inn the secret word, the guessed letter, the number of mistakes, and the playerCheat status. 
				
				Reveal(secretWord, guessedLetter, mistakesCount, playerCheated);
				
				//if the secret word is returned then return, otherwise continue
				if (secretWord.IsRevealed) return;
				
				break;
			}
	}
}


/*
	Find a new secret word
	And reset the old one
*/
void HangmanGame::ResetSecretWord()
{
	//Set the current secret word to a new object.
	//Find a random word in the wordscontainer by using rand()
	secretWord = SecretWord(wordsContainer[rand() % 10]);
}

/*
	Print a welcome message (greeting) to the user
	Before the game starts
*/
void HangmanGame::PrintWelcomeMessage()
{
	//Print the welcome message to stdout
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

/*
	Print the secret word
*/
void HangmanGame::PrintSecretWord()
{
	//Print the first part of the secret word output
	std::cout << "The secret word is: ";

	//For each letter in the word
	for (std::string::size_type letter = 0; letter != secretWord.Encoded().size(); ++letter)
	{
		//Print the encoded letter
		std::cout << secretWord.Encoded()[letter] << " ";
	}

	//Print a newline
	std::cout << std::endl;

}

/*
	Get one character from the user input.
	To be used within the game as a command or guessed character
	@param	guessedLetter	the letter the user guessed
*/
HangmanGame::InputCommand HangmanGame::GetInput(char & guessedLetter) const
{
	//Ask the user for a command
	std::cout << "Enter your guess or command: ";

	//Allocate a string object
	std::string input;

	//Get input from the user
	std::getline(std::cin, input);

	//If the input is top
	if (input == "top")
	{
		//then return the top enum
		return top;

	}
	//if the input is exit
	else if (input == "exit")
	{
		//then return the exit enum
		return quit;

	}

	//if the input is restart
	else if (input == "restart")
	{
		return restart;
	}

	//if the user is help
	else if (input == "help")
	{
		return help;

	}
	//If the input size is 1 long, and the first character is lowercase
	else if (input.size() == 1 && islower(input[0])) {

		//Then set the guessed letter to be the first character
		guessedLetter = input[0];

		return letterGuess;
	}

	//if not
	else
	{
		return invalid;
	}
}







