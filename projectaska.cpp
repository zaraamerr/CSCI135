//Name: Zara Amer
//CSCI135
//Date: Feb 27 2023
//Professor Maryash
//Task A Project 1


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;
string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    string word, pos, definition;
    while (fin >> word >> pos >> definition) {
        getline(fin, definition);
        g_words[g_word_count] = word;
        // cout << g_words[g_word_count] << endl;
        // cout << g_words << endl;
        // cout << word << endl;
        g_pos[g_word_count] = pos.substr(0, pos.length());
        // cout << g_pos[g_word_count] << endl;
        g_definitions[g_word_count] = definition.substr(1);
        g_word_count++;

        if (g_word_count >= g_MAX_WORDS) {
            cerr << "Error: Exceeded maximum number of words" << endl;
            exit(1);
        }
    }

    fin.close();
}

// int main() {
//     readWords("dict.txt");

//     for (int i = 0; i < g_word_count; i++) {
//         cout << g_words[i] << " " << g_pos[i] << ": " << g_definitions[i] << endl;
//     }

//     return 0;
// }
