#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <vector>
#include <utility>
#include <string>


class Scoreboard
{
public:

	static Scoreboard & InitScoreboard( int maximumEntries );

	void Print();
	void SignPlayerIn( int mistakesCount );


private:

	Scoreboard( int maximumEntries );
	Scoreboard( const Scoreboard & );
	Scoreboard & operator=( const Scoreboard & );

	static Scoreboard * scoreboard;

	typedef std::pair< std::string, unsigned > boardEntrie;
	std::vector< boardEntrie > boardEntries;

	bool PlayerReachedTopScores( int mistakesCount );
	void AskForPlayerName( std::string & playerName );

	void SortBoard();
//	bool operator() ( const boardEntrie & left, const boardEntrie & right );
	static bool SortPredicate( const boardEntrie & left, const boardEntrie & right );



		
	

	const int maxEntries;


};



#endif