#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int g_MAX_WORDS = 1000;

string g_words[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
int g_word_count = 0;

void readWords(string filename) {
    ifstream fin(filename);
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    string junk;
    getline(fin, junk);

    string word;
    string pos;
    string definition;

    while (fin >> word >> pos) {
        getline(fin, definition);

        g_words[g_word_count] = word;
        g_pos[g_word_count] = pos.substr(0, pos.length());
        g_definitions[g_word_count] = definition.substr(1);

        g_word_count++;
        if (g_word_count >= g_MAX_WORDS) {
            cerr << "Exceeded maximum number of words" << endl;
            break;
        }
    }

    fin.close();
}

// int main() {
//     readWords("dict.txt");

//     for (int i = 0; i < g_word_count; i++) {
//         cout << g_words[i] << " " << g_pos[i] << g_definitions[i] << endl;
//     }

//     return 0;
// }
