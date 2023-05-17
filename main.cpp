#include <iostream>
#include <cstdlib>
#include <ctime>

int MIN_NUMBER = 1;
int MAX_NUMBER = 100;
int MAX_ATTEMPTS = 5;

void playGame() {
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    int attempts = 0;
    int guess;

    std::cout << "Welcome to the Number Guesser Game!" << std::endl;
    std::cout << "I have selected a number between " << MIN_NUMBER << " and " << MAX_NUMBER << ". Can you guess it?" << std::endl;

    while (attempts < MAX_ATTEMPTS) {
        std::cout << "Attempt " << (attempts + 1) << " - Enter your guess: ";
        std::cin >> guess;

        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number!" << std::endl;
            break;
        } else if (guess < secretNumber) {
            std::cout << "Too low. Try again." << std::endl;
        } else {
            std::cout << "Too high. Try again." << std::endl;
        }

        attempts++;
    }

    if (attempts == MAX_ATTEMPTS) {
        std::cout << "Sorry, you've run out of attempts!" << std::endl;
        std::cout << "The secret number was: " << secretNumber << std::endl;
    }
}

void showSettings() {
    std::cout << "Current Settings" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Minimum Number: " << MIN_NUMBER << std::endl;
    std::cout << "Maximum Number: " << MAX_NUMBER << std::endl;
    std::cout << "Maximum Attempts: " << MAX_ATTEMPTS << std::endl;
    std::cout << std::endl;
}

void updateSettings() {
    int newMinNumber, newMaxNumber, newMaxAttempts;

    std::cout << "Update Settings" << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "Enter the new Minimum Number: ";
    std::cin >> newMinNumber;
    std::cout << "Enter the new Maximum Number: ";
    std::cin >> newMaxNumber;
    std::cout << "Enter the new Maximum Attempts: ";
    std::cin >> newMaxAttempts;

    // Only update the settings if the input is valid
    if (newMinNumber < newMaxNumber && newMaxAttempts > 0) {
        MIN_NUMBER = newMinNumber;
        MAX_NUMBER = newMaxNumber;
        MAX_ATTEMPTS = newMaxAttempts;
        std::cout << "Settings updated successfully!" << std::endl;
    } else {
        std::cout << "Invalid input. Settings remain unchanged." << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    int choice;

    do {
        std::cout << "Number Guesser Game by WulfGG" << std::endl;
        std::cout << "--- Main Menu ---" << std::endl;
        std::cout << "1. Play" << std::endl;
        std::cout << "2. Settings" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                showSettings();
                updateSettings();
                break;
            case 3:
                std::cout << "Thank you for playing the Number Guesser Game!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 3);

    return 0;
}