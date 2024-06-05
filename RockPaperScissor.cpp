#include <iostream>
#include <cstdlib>
#include <ctime>

enum Choice { ROCK, PAPER, SCISSORS };

Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3);
}

Choice getUserChoice() {
    int choice;
    std::cout << "Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ";
    std::cin >> choice;
    return static_cast<Choice>(choice);
}

void displayChoice(Choice choice) {
    switch (choice) {
        case ROCK: std::cout << "Rock"; break;
        case PAPER: std::cout << "Paper"; break;
        case SCISSORS: std::cout << "Scissors"; break;
    }
}

void determineWinner(Choice userChoice, Choice computerChoice) {
    if (userChoice == computerChoice) {
        std::cout << "It's a tie!" << std::endl;
    } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
               (userChoice == PAPER && computerChoice == ROCK) ||
               (userChoice == SCISSORS && computerChoice == PAPER)) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "Computer wins!" << std::endl;
    }
}

int main() {
    std::srand(std::time(0));

    std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;

    Choice userChoice = getUserChoice();
    Choice computerChoice = getComputerChoice();

    std::cout << "You chose: ";
    displayChoice(userChoice);
    std::cout << std::endl;

    std::cout << "Computer chose: ";
    displayChoice(computerChoice);
    std::cout << std::endl;

    determineWinner(userChoice, computerChoice);

    return 0;
}
