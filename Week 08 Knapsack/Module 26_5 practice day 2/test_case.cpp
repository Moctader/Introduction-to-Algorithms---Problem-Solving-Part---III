#include <iostream>
#include <vector>

const int MOD = 1000000007;



int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<char>> grid(H, std::vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> grid[i][j];
        }
    }
    std::vector<std::vector<int>> dp(H + 1, std::vector<int>(W + 1, 0));
    dp[1][1] = 1;

    // Calculate number of paths for each square
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i - 1][j - 1] != '#') {
                // If the square is not a wall
                if (i > 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                }
                if (j > 1) {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
                }
            }
        }
    }

    std::cout<< dp[H][W];

    return 0;
}
