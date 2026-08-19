#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

#define HASH_SIZE 2017

// C-style hash map node structure for fast lookups
typedef struct Node {
    char* word;
    int count;
    struct Node* next;
} Node;

// Unique hash function name to avoid standard namespace conflicts
unsigned int get_custom_hash_c(const char* str) {
    unsigned int h = 5381;
    while (*str) {
        h = ((h << 5) + h) + *str++;
    }
    return h % HASH_SIZE;
}

// Helper to insert or increment a word count in the hash map
void insertWord(Node** table, const char* word) {
    unsigned int idx = get_custom_hash_c(word);
    Node* curr = table[idx];
    while (curr) {
        if (strcmp(curr->word, word) == 0) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->word = strdup(word);
    newNode->count = 1;
    newNode->next = table[idx];
    table[idx] = newNode;
}

// Helper to look up a word's expected frequency
int getWordCount(Node** table, const char* word) {
    unsigned int idx = get_custom_hash_c(word);
    Node* curr = table[idx];
    while (curr) {
        if (strcmp(curr->word, word) == 0) {
            return curr->count;
        }
        curr = curr->next;
    }
    return 0;
}

// Helper to free the hash table memory safely
void freeTable(Node** table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = table[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp->word);
            free(temp);
        }
        table[i] = NULL;
    }
}

// The exact class structure required by the LeetCode C++ compiler
class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        int sLen = s.length();
        int wordsSize = words.size();
        int wordLen = words[0].length(); // Evaluates length of the first string token
        int totalWordsLen = wordsSize * wordLen;

        if (sLen < totalWordsLen) return result;

        // Build reference map for structural words validation frequency
        Node* wordCountTable[HASH_SIZE] = {NULL};
        for (int i = 0; i < wordsSize; i++) {
            insertWord(wordCountTable, words[i].c_str());
        }

        // Sliding window loops over word boundary offsets
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            
            Node* windowTable[HASH_SIZE] = {NULL};
            char* currentWord = (char*)malloc(sizeof(char) * (wordLen + 1));

            for (int j = i; j <= sLen - wordLen; j += wordLen) {
                strncpy(currentWord, s.c_str() + j, wordLen);
                currentWord[wordLen] = '\0';

                int expectedCount = getWordCount(wordCountTable, currentWord);

                if (expectedCount > 0) {
                    insertWord(windowTable, currentWord);
                    count++;

                    // Shrink window if word occurrence frequencies overflow requirements
                    while (getWordCount(windowTable, currentWord) > expectedCount) {
                        char* leftWord = (char*)malloc(sizeof(char) * (wordLen + 1));
                        strncpy(leftWord, s.c_str() + left, wordLen);
                        leftWord[wordLen] = '\0';
                        
                        unsigned int idx = get_custom_hash_c(leftWord);
                        Node* curr = windowTable[idx];
                        while (curr) {
                            if (strcmp(curr->word, leftWord) == 0) {
                                curr->count--;
                                break;
                            }
                            curr = curr->next;
                        }
                        
                        count--;
                        left += wordLen;
                        free(leftWord);
                    }

                    if (count == wordsSize) {
                        result.push_back(left);
                    }
                } else {
                    freeTable(windowTable);
                    count = 0;
                    left = j + wordLen;
                }
            }
            free(currentWord);
            freeTable(windowTable);
        }

        freeTable(wordCountTable);
        return result;
    }
};

