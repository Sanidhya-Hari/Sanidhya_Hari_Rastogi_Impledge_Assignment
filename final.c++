#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;

// TrieNode structure represents a node in the Trie data structure.
struct TrieNode {
    TrieNode* childNodes[26]; // Array to store child nodes for each character
    bool isEnd; // Indicates whether the node represents the end of a word
};

// Function to create a new TrieNode and initialize its fields.
TrieNode* createTrieNode() {
    TrieNode* node = new TrieNode;
    node->isEnd = false;
    for (int i = 0; i < 26; ++i) {
        node->childNodes[i] = nullptr;
    }
    return node;
}

// Function to insert a word into the Trie.
void insert(TrieNode* rootNode, const string& word) {
    TrieNode* node = rootNode;
    for (char letter : word) {
        int index = letter - 'a';
        if (!node->childNodes[index]) {
            node->childNodes[index] = createTrieNode();
        }
        node = node->childNodes[index];
    }
    node->isEnd = true;
}

// Function to search for a word in the Trie.
bool search(TrieNode* rootNode, const string& word) {
    TrieNode* node = rootNode;
    for (char letter : word) {
        int index = letter - 'a';
        if (!node->childNodes[index]) {
            return false;
        }
        node = node->childNodes[index];
    }
    return node != nullptr && node->isEnd;
}

// Function to read the contents of a file and store each line in a vector.
void readFileContent(const string& fileName, vector<string>& wordsVector) {
    ifstream inFile(fileName);
    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            wordsVector.push_back(line);
        }
    }
    inFile.close();
}

// Recursive function to check if a word can be formed by concatenating other words.
bool canFormCompoundWord(const string& word, TrieNode* rootNode, int length) {
    int wordLength = word.size();
    if (wordLength == 0 && length != 1) {
        return true;
    }
    for (int i = 1; i <= wordLength; ++i) {
        if (search(rootNode, word.substr(0, i)) && canFormCompoundWord(word.substr(i, wordLength - i), rootNode, length + 1)) {
            return true;
        }
    }
    return false;
}

// Function to find the longest word in a vector and remove it.
string findLongestWord(vector<string>& wordsVector) {
    auto maxLengthWordIterator = max_element(wordsVector.begin(), wordsVector.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
    string longestWord = *maxLengthWordIterator;
    wordsVector.erase(maxLengthWordIterator);
    return longestWord;
}

// Function to find and print compound words.
void findAndPrintCompoundWords(vector<string>& wordsVector) {
    TrieNode* trieRoot = createTrieNode();
    for (const string& word : wordsVector) {
        insert(trieRoot, word);
    }

    int k = 2;
    while (k) {
        string currentWord = findLongestWord(wordsVector);
        if (canFormCompoundWord(currentWord, trieRoot, 0)) {
            cout << (k == 2 ? "Longest Compound Word: " : "Second Largest Compound Word: ") << currentWord << endl;
            --k;
        }
    }
    delete trieRoot;
}

// Function to print the time taken to process the file in milliseconds.
void printTimeTaken(chrono::high_resolution_clock::time_point startTime, chrono::high_resolution_clock::time_point endTime) {
    double timeTaken = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
    timeTaken *= 1e-6; // Convert to milliseconds
    cout << "Time taken to process the file: " << fixed << timeTaken << setprecision(6) << " milliseconds" << endl;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    cout << "Results for Input_01" << endl;
    vector<string> wordsList1;
    readFileContent("input_01.txt", wordsList1);
    findAndPrintCompoundWords(wordsList1);
    auto end = chrono::high_resolution_clock::now();
    printTimeTaken(start, end);

    auto start2 = chrono::high_resolution_clock::now();
    cout << "Results for Input_02" << endl;
    vector<string> wordsList2;
    readFileContent("input_02.txt", wordsList2);
    findAndPrintCompoundWords(wordsList2);
    auto end2 = chrono::high_resolution_clock::now();
    printTimeTaken(start2, end2);

    return 0;
}
