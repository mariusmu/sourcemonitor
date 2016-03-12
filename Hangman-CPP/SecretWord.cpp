#include "SecretWord.h"
#include <string>

SecretWord::SecretWord(const std::string & secretWord)
	: decodedWord(secretWord),
	encodedWord(secretWord.size(), '_')
{

}

char SecretWord::RevealNextLetter()
{

	for (std::string::size_type letter = 0; letter != encodedWord.size(); ++letter)
	{
		if (encodedWord[letter] == '_')
		{

			RevealLetter(decodedWord[letter]);
		}

		return decodedWord[letter];

	}
}
int SecretWord::RevealLetter(char letterToReveal)
{
	int letterOccurenceCount = 0;
	for (std::string::size_type letter = 0; letter != decodedWord.size(); ++letter)
	{
		if (decodedWord[letter] == letterToReveal)
		{

			encodedWord[letter] = letterToReveal;
		}

		++letterOccurenceCount;
	}

	return letterOccurenceCount;
}

bool SecretWord::HasLetter(char wordLetter) const
{
	for (std::string::size_type letter = 0; letter != decodedWord.size(); ++letter)
	{
		if (decodedWord[letter] == wordLetter)
		{

			return true;
		}

	}

	return false;
}
bool SecretWord::IsRevealed() const
{
	for (std::string::size_type letter = 0; letter != encodedWord.size(); ++letter)
	{
		if (encodedWord[letter] == '_')
		{

			return false;
		}

	}

	return true;
}

const std::string & SecretWord::Decoded()
{
	return decodedWord;
}
const std::string & SecretWord::Encoded()
{
	return encodedWord;
}