#include "Trie.h"
#include <ctime>
#include <random>
#include <chrono>
#include <unistd.h>

using namespace std;

const string FILENAME = "file.db";

void stressTest() {
    Trie* trie = new Trie();
    string line;
    ifstream keysFile("keys.db");
    vector<string> keys;

    trie->build(FILENAME);

    for(int i = 0; i < 100; i++) {
        auto index = rand() % 3386;
        while(index--) getline(keysFile,line);
        keysFile.seekg(0,ios::beg);
        keys.push_back(line);
    }
    cout<<"\n\n\n";
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < 100; i++) {
        auto test = trie->search(keys[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto executionTime = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Execution time: " << executionTime.count() << " us.\n";
    cout << "Read count: " << SEARCH_COUNTER/100 << "\n";
    delete trie;
}

int main(){

    srand(time(nullptr));

    Trie* trie = new Trie();

    trie->build(FILENAME);

    stressTest();

    cout << trie->prefix("Licens") << "\n";

    return 0;
}