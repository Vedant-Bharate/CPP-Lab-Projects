#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{ 26 };

int number_from_letter(char letter) {
    int offset = letter - (int)'a';
    if (offset < 0 || offset >= ALPHABET_LENGTH) {
        std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
        assert(false);
    }
    return offset;
}

char letter_from_number(int number) {

    if (number < 0 || number >= ALPHABET_LENGTH) {
        std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
        assert(false);
    }

    const char alphabet[] = { 'a',
                              'b',
                              'c',
                              'd',
                              'e',
                              'f',
                              'g',
                              'h',
                              'i',
                              'j',
                              'k',
                              'l',
                              'm',
                              'n',
                              'o',
                              'p',
                              'q',
                              'r',
                              's',
                              't',
                              'u',
                              'v',
                              'w',
                              'x',
                              'y',
                              'z' };
    return alphabet[number];
}

//  This fuction will convert the given character to the encrypted representation.
char decrypt(char plaintext, char direction, int shift) {
    int plaintext_position = number_from_letter(plaintext);
    if (direction == 'l')
    {
        shift *= -1;
    }

    plaintext_position = (plaintext_position + shift) % ALPHABET_LENGTH;
    if (plaintext_position < 0)
    {
        plaintext_position += ALPHABET_LENGTH;
    }
    return letter_from_number(plaintext_position);
}

// This fuction will convert the given character to the encrypted representation
// This function uses the function decrypt() to convert the given character to the encrypted one.
int main() {
    // Initialize the object and opoen a file to read the data.
    std::ifstream inputFile;
    inputFile.open("input.txt");
    char inputFromFile;
    int shift;
    // Reading the input for the shift Direction
    inputFile >> inputFromFile;

    // Initializing the shift direction to the first character read.
    char shiftDirection = inputFromFile;

    // If structure for checking if the first character read is 'l' or 'r'.
    if (shiftDirection == 'r' || shiftDirection == 'l')
    {
        // Checking if the second character read is a number.
        if ((inputFile >> shift))
        {
            while (inputFile >> inputFromFile)
            {
                // Call the function to encrypt the character.
                std::cout << decrypt(inputFromFile, shiftDirection, shift);

            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Oops: Could not read the shift number from the input file.\n";
        }
    }
    //Checks if the first character is a letter (Uppercase or lowercase)
    else if ((shiftDirection >= 65 && shiftDirection < 91) || (shiftDirection >= 97 && shiftDirection < 123))
    {
        std::cout << "Oops: Invalid direction in the input file.\n";
    }

    //This checks if the first character is a number using the character codes of first character.
    else if ((shiftDirection >= 48 && shiftDirection <= 57))
    {
        std::cout << "Oops: Invalid direction in the input file.\n";
    }

    else
    {
        std::cout << "Oops: Could not read the direction from the input file.\n";
    }

}