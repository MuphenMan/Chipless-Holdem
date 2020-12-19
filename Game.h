#ifndef GAME_H
#define GAME_H

class Game {
	public:
		Game	g(Player p[], int numPlayers);				//will have to change Player array into a Player address for linked list
		void	setHiLow();						//set High and low of game
		double	getHi();						//accessor of games high 
		double	getLow();						//accessor of games low
		void	displayTotals(Player p[], int numPlayers);		//simple function to display player totals
		double	getPot();						//accessor function for the table pot
		double	setPot(double pot);					//mutator for table pot

	private:
		double gamePot;
		double gameHi;
		double gameLow;

};

#endif // !GAME_H

