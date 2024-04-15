#include <fstream>
#include <iostream>
#include <vector>

bool more_to_read(std::ifstream &file) {
  file >> std::noskipws;
  while (file.peek() == ' ') {
    char discard;
    file >> discard;
  }
  return !(file.eof() || std::iscntrl(file.peek()));
}

int fcc(const std::string &fixme_filename, const std::string &typo_filename,
        const std::string &fixo_filename, std::string &fixed_sentence) {

    // Declaring and reading fixo_filename
    std::ifstream read_fixos_file;
    read_fixos_file.open(fixo_filename);

    // Declaring and reading typo_filename
    std::ifstream read_typos_file;
    read_typos_file.open(typo_filename);
    
    std::vector<std::string> fixos;
    // While loop to go through the fixos
    while (more_to_read(read_fixos_file)) {
        std::string next_word;
        read_fixos_file >> next_word;
        fixos.push_back(next_word); 
    }

    /*
    //Printing fixos for debugging purpose
    std::cout << "FIXOS STARTING: \n" ;
    for (auto str : fixos)
    {
        std::cout << str << "\n";
    }
    */

    std::vector<std::string> typos;
    // While loop to go through the typos
    while (more_to_read(read_typos_file)) {
        std::string next_word;
        read_typos_file >> next_word;
        typos.push_back(next_word);
    }

    /*
    //Printing Typos for debugging purposes
    std::cout << "TYPOS STARTING: \n" ;
    for (auto str : typos)
    {
        std::cout << str << "\n";
    }
    */

    // Check if the number of typos and fixos match
    if (fixos.size() != typos.size()) {
        return -1; // Error: Number of typos and fixos don't match
    }

    // Open the fixme file to read the sentence
    std::ifstream read_fixme_file;
    read_fixme_file.open(fixme_filename);

    std::string sentence;
    std::string word;
    int corrections = 0;

    // Read the sentence from fixme file
    while (read_fixme_file >> word) {
        // Checking if the word is a typo
        bool is_typo = false;
        for (int i = 0; i < typos.size(); ++i) {
            if (word == typos[i]) {
                sentence += fixos[i]; // Replace typo with fixo
                ++corrections;
                is_typo = true;
                break;
            }
        }
        if (!is_typo) {
            sentence += word; // Keep the word as is
        }
        sentence += " "; // Add space between words
    }

    // Removing the extra space and replacing that with a full stop.
    sentence = sentence.substr(0, sentence.size() - 1);
    sentence += ".";

    fixed_sentence = sentence; // Update the fixed sentence
    return corrections; // Return the number of corrections made

  return -1;
}
