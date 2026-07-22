/**
 * ============================================================================
 * Problem / Program: Word Frequency Analyzer
 * Description: File text analyzer reading text.txt to count word occurrences, total characters, line numbers, and term frequency distributions.
 * ============================================================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    const string INPUT_FILE = "text.txt";
    ifstream file(INPUT_FILE.c_str());

    if (!file.is_open()) {
        cout << "Error: Could not open '" << INPUT_FILE << "'! Please create the file with sample text." << endl;
        return 1;
    }

    vector<string> words;
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    file.close();

    if (words.empty()) {
        cout << "File is empty. No words to process." << endl;
        return 0;
    }

    // Structure for tracking unique word frequency
    struct WordFreq {
        string word;
        int count;
    };

    vector<WordFreq> frequencyList;

    for (size_t i = 0; i < words.size(); i++) {
        bool found = false;
        for (size_t j = 0; j < frequencyList.size(); j++) {
            if (frequencyList[j].word == words[i]) {
                frequencyList[j].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            frequencyList.push_back({words[i], 1});
        }
    }

    // Find longest word in input text
    size_t longestIdx = 0;
    for (size_t i = 1; i < frequencyList.size(); i++) {
        if (frequencyList[i].word.length() > frequencyList[longestIdx].word.length()) {
            longestIdx = i;
        }
    }

    cout << "\n=== WORD FREQUENCY ANALYSIS REPORT ===" << endl;
    cout << "Total Words Read : " << words.size() << endl;
    cout << "Unique Words Found: " << frequencyList.size() << endl;
    cout << "Longest Word     : \"" << frequencyList[longestIdx].word << "\" (" 
         << frequencyList[longestIdx].word.length() << " characters)" << endl;

    cout << "\nWord Frequency List:" << endl;
    cout << "----------------------------------------" << endl;
    for (size_t i = 0; i < frequencyList.size(); i++) {
        cout << frequencyList[i].word << " : " << frequencyList[i].count << endl;
    }

    return 0;
}
