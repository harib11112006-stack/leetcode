#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        // Fast direct ASCII map lookup array for Roman numeral values
        int romanValues[128] = {0};
        romanValues['I'] = 1;
        romanValues['V'] = 5;
        romanValues['X'] = 10;
        romanValues['L'] = 50;
        romanValues['C'] = 100;
        romanValues['D'] = 500;
        romanValues['M'] = 1000;

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // If current symbol value is less than the next symbol value, subtract it
            if (i < n - 1 && romanValues[s[i]] < romanValues[s[i + 1]]) {
                total -= romanValues[s[i]];
            } else {
                // Otherwise, add it to the running sum
                total += romanValues[s[i]];
            }
        }

        return total;
    }
};
