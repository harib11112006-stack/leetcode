#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define HASH_SIZE 10007

// Custom node structure for the internal remainder mapping table
typedef struct Node {
    long long remainder;
    int index;
    struct Node* next;
} Node;

// Hash mapping utility
inline int get_custom_hash(long long rem) {
    long long val = rem % HASH_SIZE;
    if (val < 0) val += HASH_SIZE;
    return (int)val;
}

// Insert remainder tracking anchor token
void insert_rem(Node** table, long long rem, int index) {
    int h = get_custom_hash(rem);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->remainder = rem;
    newNode->index = index;
    newNode->next = table[h];
    table[h] = newNode;
}

// Lookup routine to track loops
int find_rem(Node** table, long long rem) {
    int h = get_custom_hash(rem);
    Node* curr = table[h];
    while (curr) {
        if (curr->remainder == rem) {
            return curr->index;
        }
        curr = curr->next;
    }
    return -1;
}

// Memory cleaning lifecycle helper
void free_table(Node** table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = table[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        table[i] = NULL;
    }
}

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        // Pre-allocate buffer tracking logic to run at raw machine speed
        char* res = (char*)malloc(10005 * sizeof(char));
        res[0] = '\0';
        int pos = 0;

        if ((numerator < 0) ^ (denominator < 0)) {
            res[pos++] = '-';
            res[pos] = '\0';
        }

        long long num = std::llabs((long long)numerator);
        long long den = std::llabs((long long)denominator);

        pos += sprintf(res + pos, "%lld", num / den);

        long long rem = num % den;
        if (rem == 0) {
            std::string finalStr(res);
            free(res);
            return finalStr;
        }

        res[pos++] = '.';
        res[pos] = '\0';

        Node* table[HASH_SIZE] = {NULL};

        while (rem != 0) {
            int repeatIndex = find_rem(table, rem);
            
            if (repeatIndex != -1) {
                int len = strlen(res);
                for (int k = len; k >= repeatIndex; k--) {
                    res[k + 1] = res[k];
                }
                res[repeatIndex] = '(';
                pos++;
                
                res[pos++] = ')';
                res[pos] = '\0';
                break;
            }

            insert_rem(table, rem, pos);

            rem *= 10;
            pos += sprintf(res + pos, "%lld", rem / den);
            rem %= den;
        }

        free_table(table);
        std::string finalStr(res);
        free(res);
        return finalStr;
    }
};
