#ifndef PLAYER_H
#define PLAYER_H

class Player {
	public:
		Player	p();															//sets up players
		void	setRoles(int &pNum, Player p[], double high, double low);		
		void	addPlayer(string pName, double pTotal, int& numPlayers);
		void	playerTurn(Player p[], int pNum);
		double	getPlayerTotal();
		void	setPlayerTotal(double total)
		string	getPlayerName();
		void	setPlayerName(string name);
		bool	getPlayerInRound();
		void	setPlayerInRound(bool inRound);
		void	playerBet(double amount);

	private:
		string pName;		 //set player's name
		double pTotal;		 //track player's money total
		double pRoundBet	 //track the player's total bet in a round
		bool isBigBlind;	 //track if player is big blind
		bool isSmallBlind;	 //track if player is small blind
		bool isDealer;		 //track if player is dealer
		bool inRound;		 //will track if the player is still playing in the round
		Player *nextPlayer;
		Player *lastPlayer;
		Player *head;
		Game g;
};

#endif // !PLAYER_H

