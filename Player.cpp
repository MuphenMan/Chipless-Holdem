#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include "Player.h"

using namespace std;

//============ Player Constructor =====================================
//	sets the head pointer to nullptr and sets up linked list of players
//		no inputs or outputs
//=====================================================================
Player::Player p() {				
	head = nullptr;
}// end of Player class default constructor

//=========== addPlayer Function =====================================
//	adds players to the front of the linked list
//		INPUTS:		string names
//					double starting total
//					address of number of players
//		OUTPUTS:	returns nothing
//====================================================================
void Player::addPlayer(string plName, double plTotal, int &numPlayers) {
	
	Player *p = new Player;
	if (head == nullptr) {
		lastPlayer = p;
	}
	p->pName = plName;
	p->pTotal = plTotal;
	if (*numPlayers == 1) {
		lastPlayer->nextPlayer = p;
	}
	p->nextPlayer = head;
	head = p;

}// end of addPlayer function

//=========== setRoles Function ======================================
//	sets up a random dealer and big/small blinds
//		takes in a linked list and inputted hi, low and numPlayers
//		returns nothing
//====================================================================
void setRoles(Player *p, double hi, double low, int numPlayers) {

	int tempInt;
	//set up random num generator to determine first dealer
	srand(time(NULL));
	tempInt = rand % numPlayers + 1;
	//set up dealer, big blind, and small blind
	for (int i = 0; i <= tempInt; i++) {
		p = p->nextPlayer;
	}
	p.setSmallBlind(1);
	p->nextPlayer.setBigBlind(1);
	(p->nextPlayer)->nextPlayer.setDealer(1);
}// end of setRoles Function

//======= playerBet Function ===================================================
//	takes in amount a player bet and: subtracts form player total, adds amount 
//	to game pot
//==============================================================================
void playerBet(double amount, Game g) {
	this->playerTotal = (this->playerTotal) - amount;
	g.setPot(g.getPot() + amount);							//check this 
}


void playerTurn(Player *p, int pNum, int maxPlayers, double& highestBet, char playerChoice, int& roundPhase) {

	bool isValid = 0;
	double newBetAmount;

	if (p.inRound() == 0)						//check to see if player is in round
		break;

	if (pNum == maxPlayers) {					//
		pNum = 0;
		highestBet = 0;
		
		if (roundPhase == 3) {
			cout << "Are all players still in the game? (y/n):";
			cin >> playerChoice;
			if (toupper(playerChoice) == "Y") { 
				for (int i = 0; i < maxPlayers; i++) {
					if (p->getPlayerTotal() == 0)
						p.setPlayerTotal()
			}
			else if (toupper(playerChoice) == "N") {
				cout << "Currently these players do not have any more chips: ";
				for (int i = 0; i < maxPlayers; i++) {
					if (p->getPlayerTotal() == 0)
						cout << p->getPlayerName() << endl;
					else
						p = p->nextPlayer;
				}
			}
				
			roundPhase = 0;
		}
		else
			roundPhase++;
	}

	else if (p.getPlayerTotal() == 0) {
		cout << "Player is out of chips...\n";
		pNum++;
	}
	cout << p->pName << "'s turn:\n 1. Call\n2. Raise\n3. Fold\n4. Check\n5. View Totals\n6. End Session";
	cin >> pOption;
	while (isValid == 0) {
		switch pOption:
			case 1:
				p.setPlayerTotal(p.getPlayerTotal() - highestBet);
				break;
			case 2:
				while (isValid == 0) {
					cout << "Enter new bet amount: $";
					cin >> newBetAmmount;
					if ((newBetAmount / 2) < highestBet && newBetAmount < p.getPlayerTotal())
						cout << "Invalid entry: minimum bet must be at least double the highest current bet.";
					else if (newBetAmount > p.getPlayerTotal()) {
						cout << "Not enough currency, would you like to all in? (y/n):";
						cin >> playerChoice;
						if (toupper(playerChoice) == 'Y') {
							highestBet = p.getPlayerBet() + p.getPlayerTotal();
							isValid = 1;
						}
						else if (toupper(playerChoice) == 'N')
							break;
						else
							cout << "Invalid Input"
					}
				}
				break;
			case 3:
				p.setInRound(1);
				break;
			case 4:
				if (p.getPlayerBet() == highestBet)
					break;
			case 5:
			case 6:
				playerTurn()
			case 7:
				exit();

	}
}