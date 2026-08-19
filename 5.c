#include <vector>
#include <string>

class Solution {
private:
    // Fixed phone keypad mapping array
    const std::vector<std::string> keypad = {
        "",     "",     "abc",  "def", 
        "ghi",  "jkl",  "mno",  "pqrs", 
        "tuv",  "wxyz"
    };

    void backtrack(const std::string& digits, int index, std::string& current, std::vector<std::string>& result) {
        // Base case: if the current combination length matches digits length, save it
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the string of letters that the current digit maps to
        int digit = digits[index] - '0';
        const std::string& letters = keypad[digit];

        // Loop through all candidate characters for this digit position
        for (char c : letters) {
            current.push_back(c);                 // Choose: append character
            backtrack(digits, index + 1, current, result); // Explore next digit layer
            current.pop_back();                  // Unchoose: backtrack step
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) return result;

        std::string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};
