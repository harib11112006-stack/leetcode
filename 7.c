#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Bitmasks initialized to 0 for tracking digits 1-9
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                
                // Skip empty cell slots
                if (val == '.') continue;
                
                // Map digit '1'-'9' to a 0-indexed bit position (0-8)
                int digitShift = val - '1';
                int mask = 1 << digitShift;
                
                // Identify the corresponding 3x3 sub-box index (0-8)
                int boxIndex = (r / 3) * 3 + (c / 3);
                
                // If the bit is already flipped to 1 in any mask, it is a duplicate
                if ((rows[r] & mask) || (cols[c] & mask) || (boxes[boxIndex] & mask)) {
                    return false;
                }
                
                // Flip the bit to 1 to record seeing this digit
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIndex] |= mask;
            }
        }
        
        return true;
    }
};
