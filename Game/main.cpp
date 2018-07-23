#pragma once
#include "Game.h"
#include <iostream>

int main() {

	try {

		// construct the game, loading happens here
		Game game;

		// main game loop (input, update, draw, repeat)
		game.run();
	}

	// catch all statement
	catch (...) {
		std::cout << "Unknown Error!" << std::endl;

		// pause the program here
		char x;
		std::cin >> x;
		std::cout << x << std::endl;
	}

	return 0;
}