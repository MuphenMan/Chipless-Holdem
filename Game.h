#ifndef GAME_H
#define GAME_H

class Game {
	public:
		Game	g(Player p[], int numPlayers);
		void	setHiLow();
		double	getHi();
		double	getLow();
		void	displayTotals(Player p[], int numPlayers);
		double	getPot();
		double	setPot(double pot);

	private:
		double gamePot;
		double gameHi;
		double gameLow;

};

#endif // !GAME_H

