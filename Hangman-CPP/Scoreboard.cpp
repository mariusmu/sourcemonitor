#include "Scoreboard.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Scoreboard *Scoreboard::scoreboard = 0;

Scoreboard & Scoreboard::InitScoreboard(int maximumEntries)
{
	if (!scoreboard)
		scoreboard = new Scoreboard(maximumEntries);

	return *scoreboard;
}

Scoreboard::Scoreboard(int maximumEntries)
	: maxEntries(maximumEntries)
{


}


void Scoreboard::Print()
{

	for (int playerPosition = 0; playerPosition != boardEntries.size(); ++playerPosition)
	{
		std::string formatedPlayerName;

		if (boardEntries[playerPosition].first.size() > 20)
		{

			formatedPlayerName = std::string(boardEntries[playerPosition].first.begin(), boardEntries[playerPosition].first.begin() + 17) + "...";

		}
		else if (boardEntries[playerPosition].first.size() < 20)
		{
			formatedPlayerName = boardEntries[playerPosition].first + std::string(20 - boardEntries[playerPosition].first.size(), ' ');
		}


		std::cout << playerPosition
			<< ". "
			<< formatedPlayerName
			<< " --> "
			<< boardEntries[playerPosition].second
			<< " mistake"
			<< (boardEntries[playerPosition].second > 1 ? "s" : "")
			<< std::endl;

	}
}
void Scoreboard::SignPlayerIn(int mistakesCount)
{

	std::string playerName;


	if (boardEntries.size() < maxEntries)
	{

		AskForPlayerName(playerName);
		boardEntries.push_back(std::make_pair(playerName, mistakesCount));
		SortBoard();

		return;
	}

	if (!PlayerReachedTopScores(mistakesCount))
		return;
	{

		AskForPlayerName(playerName);

		(--boardEntries.end())->first = playerName;
		(--boardEntries.end())->second = mistakesCount;

		SortBoard();

	}

}


bool Scoreboard::PlayerReachedTopScores(int mistakesCount)
{
	if (boardEntries.empty())
	{

		return true;

	}
	return mistakesCount <= (--boardEntries.end())->second;
}
void Scoreboard::AskForPlayerName(std::string & playerName)
{

	std::cout << "Please enter your name for the top scoreboard: ";
	std::getline(std::cin, playerName);
}
void Scoreboard::SortBoard()
{
	std::sort(boardEntries.begin(), boardEntries.end(), Scoreboard::SortPredicate);
}

bool Scoreboard::SortPredicate(const boardEntrie & left, const boardEntrie & right)
{
	return left.second < right.second;
}
