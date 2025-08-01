// Los Headers
#include <iostream>
#include <random>
#include <limits>

// La Función de Entrada
int main () {
	// Generación de Número Aleatorio
	std::random_device rd;
	std::mt19937 gen(rd()); // mt19937 NO SE TOCA
	std::uniform_int_distribution<> distr(1,10);

	int secretNumber = distr(gen);
	int guess = 0;
	int attempts = 0;
	const int maxAttempts = 5;

	std::cout << "Guess a number between 1 and 10: ";

	while (attempts < maxAttempts) {
		std::cout << "Attempt " << (attempts +1) << ": ";
		std::cin >> guess;

		// Limpiar Input
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please enter a valid number between 1 and 10: ";
			continue;
		}

		// Filtrar Resultado
		if (guess < 1 || guess > 10) {
			std::cout << "Out of Range! Try again: ";
		} else if (guess == secretNumber) {
			std::cout << "You guessed it! The secret number is " << secretNumber << ".\n";
			break;
		} else { 
			std::cout << "Wrong! Try again: ";
		}

		attempts++; // No hace falta antes.
	}

	return 0;
}
