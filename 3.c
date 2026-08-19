#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        // Pairs of values and corresponding Roman numeral symbols in descending order
        const std::vector<std::pair<int, std::string>> romanMapping = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        std::string result = "";
        
        // Loop through the mapping matrix structure
        for (const auto& mapping : romanMapping) {
            // While the current number is greater than or equal to the Roman numeral value
            while (num >= mapping.first) {
                result += mapping.second; // Append the symbol token
                num -= mapping.first;     // Deduct the value from the remaining total
            }
        }
        
        return result;
    }
};
