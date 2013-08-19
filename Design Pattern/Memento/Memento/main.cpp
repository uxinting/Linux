#include "memento.h"
#include <iostream>

using namespace std;

int main() {
	Player player;
	player.InitState();

	PlayerCaretaker taker;
	taker.SetPlayerMemento(player.Save());

	player.Fight();
	player.StateDisplay();

	player.Recovery(taker.GetPlayerMemento());
	player.StateDisplay();

	system("pause");
	return 0;
}