#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // Map to store sorted string -> list of anagrams
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        
        for (const std::string& s : strs) {
            std::string key = s;
            // Sorting the string normalizes it so all anagrams share the identical key
            std::sort(key.begin(), key.end());
            
            // Append the original string to its matching anagram family vector bucket
            anagramMap[key].push_back(s);
        }
        
        // Collect all grouped vectors from the hash map into the final result matrix
        std::vector<std::vector<std::string>> result;
        result.reserve(anagramMap.size()); // Optimize memory allocation
        
        for (auto& pair : anagramMap) {
            result.push_back(std::move(pair.second));
        }
        
        return result;
    }
};
