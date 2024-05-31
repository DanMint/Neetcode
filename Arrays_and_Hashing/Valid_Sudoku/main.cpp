class Solution {
public:
    static bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                if (board[i][j] == '.') {
                    continue;
                }
                char currentVal = board[i][j];

                for (int k = 0; k < board[i].size(); k ++) {
                    if (i == k) {
                        continue;
                    }
                    if (currentVal == board[i][k]) {
                        return false;
                    }
                }

                for (int k = 0; k < board[i].size(); k ++) {
                    if (k == j) {
                        continue;
                    }
                    if (currentVal == board[k][j]) {
                        return false;
                    }
                }

                int squareX = (i / 3) * 3;
                int squareY = (j / 3) * 3;

                for (int k = squareX; k < squareX + 3; k ++) {
                    for (int l = squareY; l < squareY + 3; l ++) {
                        if (i == k && j ==l) {
                            continue;
                        }
                        if (currentVal == board[k][l]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};