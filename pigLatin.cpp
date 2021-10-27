// Copyright (c) 2021 D.B. Calitis All rights reserved
//
// Created by: Daria Bernice Calitis
// Created on: Oct 2021
// This program determines the smallest number

#include <iostream>
#include <string>
#include <cstring>
#include <vector>


std::string pigLatin(std::string sentence) {
    // This function converts normal text to Pig Latin
    // keeping strtok, the variable-length array and strcpy for simplicity
    int sentenceLength = sentence.length();
    char sentenceChars[sentenceLength + 1];
    std::vector<std::string> newWords;
    std::vector<std::string> words;
    std::string newWord;
    std::string newSentence;

    strcpy(sentenceChars, sentence.c_str());

    // get the first token
    char *token = strtok(sentenceChars, " ");

    // walk through other tokens
    while (token != NULL) {
        std::string word = std::string(token);
        words.push_back(word);
        token = strtok(NULL,  " ");
    }

    for (int counter = 0; counter < words.size(); counter++) {
        newWord = (words[counter].erase(0, 1) + words[counter].substr(0, 1)
        + "ay");
        newWords.push_back(newWord);
    }

    newSentence = "";
    for (std::string word : newWords) {
        newSentence += word + " ";
    }

    return newSentence;
}


int main() {
    // This function is the main function
    std::string user_input;

    std::cout << "Pig Latin Converter" << std::endl;

    // input
    std::cout << "Enter a sentence: ";
    getline(std::cin, user_input);

    std::cout << "\n" << pigLatin(user_input) << std::endl;

    std::cout << "\nDone." << std::endl;
}
