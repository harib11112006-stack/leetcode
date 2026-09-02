#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);
    
    // Dynamically allocate or use VLA since constraints are small (<= 20)
    bool dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    
    // Base case
    dp[0][0] = true;
    
    // Handle patterns matching an empty string
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            else if (p[j - 1] == '*') {
                // Check 0 matches of preceding character
                dp[i][j] = dp[0 + j - 2 >= 0 ? dp[i][j - 2] : false]; 
                dp[i][j] = dp[i][j - 2];
                
                // Check 1 or more matches of preceding character
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }
    
    return dp[m][n];
}
