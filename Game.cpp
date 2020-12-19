Game::Game g(Player p[], int numPlayers) {
	string name;
	double total;
	cout << "Enter player names: ";
	for (int i = 0; i < numPlayers; i++) {
		cin >> name;
		p[i].setPlayerName(name);
	}
}

void Game::setHiLow() {

	cout << "Enter the low: ";
	cin >> gameLow;
	cout << "Enter the high: ";
	cin >> gameHi;
}

double Game::getHi() {
	return gameHi;
}

double Game::getLow() {
	return gameLow;
}

void Game::displayTotals(Player p[], int pNum) {

	Player *temp = p;
	cout << "=====================================================================\n"
		 << "                     Current Player Totals                           \n"
		 << "=====================================================================\n";
	for (int i = 0; i < pNum; i++) {
		cout << "|  " << temp.getPlayerName() << "$" << temp.getPlayerTotal() << "|\n";
		temp = temp->nextPlayer;
	}
}

double Game::getPot() {
	return gamePot;
}

void Game::setPot(double pot) {
	gamePot = gamePot + pot;
}