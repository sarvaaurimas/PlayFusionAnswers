#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

string int_to_str(int num)
//Simple function that takes in an integer and returns it as a string
{
	stringstream ss;

	ss << num;

	return ss.str();
}



void roundsScheduler(vector <int> &players)
/*
Function takes in a vector of N players as integers and writes the pairings of every match into separate .txt files.
For example 5 players match generator would take in a vector {1, 2, 3, 4, 5} - it works with both odd and even numbers of players
*/
{
	ofstream file;
	if (players.size() % 2 == 1)
	{
		players.insert(players.begin(), 0); //If the number of players is odd add a dummy player 0 in the beginning
	}
	int numOfPlayers = players.size();

	for (int a = 0; a < numOfPlayers - 1; a++) //Calculates pairings for the first half of the rounds and writes them into .txt files
	{
		file.open("Round" + int_to_str(a + 1) + ".txt");
		if (players.at(0) == 0)
		{
			file << "Player " + int_to_str(players.at(players.size() - 1)) + " doesn't play this round \n"; //If the N is odd - one player doesn't play each round
			for (int i = 1; i < numOfPlayers / 2; i++) //Calculate the pairings for each round if N is odd
			{
				file << "Match " + int_to_str(i) + ": ( " + int_to_str(players.at(i)) + ", " + int_to_str(players.at(players.size() - 1 - i)) + " ) \n";
			}
		}
		else
		{
			for (int i = 0; i < numOfPlayers / 2; i++) //Calculate the pairings for each round if N is even
			{
				file << "Match " + int_to_str(i + 1) + ": ( " + int_to_str(players.at(i)) + ", " + int_to_str(players.at(players.size() - 1 - i)) + " ) \n";
			}
		}
		file.close();
		players.insert(players.end(), players.at(1)); //These two lines move the second entry of players vector to the back as we're keeping first one fixed
		players.erase(players.begin() + 1);
	}

	for (int a = numOfPlayers - 1; a < (numOfPlayers - 1) * 2; a++)
	/* 
	Calculates pairings for the second half of the rounds and writes them into .txt files
	Same principle as for the first half only positions of players are inverted to starting against the same player twice
		*/
	{
		file.open("Round" + int_to_str(a + 1) + ".txt");
		if (players.at(0) == 0)
		{
			file << "Player " + int_to_str(players.at(players.size() - 1)) + " doesn't play this round \n";  
			for (int i = 1; i < numOfPlayers / 2; i++) 
			{
				file << "Match " + int_to_str(i) + ": ( " + int_to_str(players.at(players.size() - 1 - i)) + ", " + int_to_str(players.at(i)) + " ) \n";
			}
		}
		else
		{
			for (int i = 0; i < numOfPlayers / 2; i++) 
			{
				file << "Match " + int_to_str(i + 1) + ": ( " + int_to_str(players.at(players.size() - 1 - i)) + ", " + int_to_str(players.at(i)) + " ) \n";
			}
		}
		file.close();
		players.insert(players.end(), players.at(1));
		players.erase(players.begin() + 1);
	}
}