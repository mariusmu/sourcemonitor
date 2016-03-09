#ifndef SECRET_WORD_H
#define SECRET_WORD_H

#include <string>

class SecretWord
{
public:

	SecretWord( const std::string & secretWord );

	char RevealNextLetter();
	int RevealLetter( char letterToReveal );

	bool HasLetter( char wordLetter ) const;
	bool IsRevealed() const;

	const std::string & Decoded();
	const std::string & Encoded();

private:

	std::string decodedWord;
	std::string encodedWord;

};


#endif