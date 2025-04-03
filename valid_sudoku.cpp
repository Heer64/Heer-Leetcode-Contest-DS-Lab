class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> rowSet;
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    if (rowSet.count(c)) {
                        return false;
                    }
                    rowSet.insert(c);
                }
            }
        }
        for (int j = 0; j < 9; ++j) {
            unordered_set<char> colSet;
            for (int i = 0; i < 9; ++i) {
                char c = board[i][j];
                if (c != '.') {
                    if (colSet.count(c)) {
                        return false;
                    }
                    colSet.insert(c);
                }
            }
        }
        for (int box = 0; box < 9; ++box) {
            unordered_set<char> boxSet;
            int startRow = (box / 3) * 3;
            int startCol = (box % 3) * 3;
            for (int i = startRow; i < startRow + 3; ++i) {
                for (int j = startCol; j < startCol + 3; ++j) {
                    char c = board[i][j];
                    if (c != '.') {
                        if (boxSet.count(c)) {
                            return false;
                        }
                        boxSet.insert(c);
                    }
                }
            }
        }
        
        return true;
    }
};
