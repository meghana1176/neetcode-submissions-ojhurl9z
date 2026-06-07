class Solution {
public:
    vector<vector<bool>> visited;
    int m, n;

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                board[0][i] = 'y';
                visited[0][i] = true;
                dfs(0, i, visited, board);
            }

            if (board[m - 1][i] == 'O') {
                board[m - 1][i] = 'y';
                visited[m - 1][i] = true;
                dfs(m - 1, i, visited, board);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'y';
                visited[i][0] = true;
                dfs(i, 0, visited, board);
            }

            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = 'y';
                visited[i][n - 1] = true;
                dfs(i, n - 1, visited, board);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'y')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }

    void dfs(int i, int j, vector<vector<bool>>& visited,
             vector<vector<char>>& board) {

        if (i + 1 < m && board[i + 1][j] == 'O' && !visited[i + 1][j]) {
            board[i + 1][j] = 'y';
            visited[i + 1][j] = true;
            dfs(i + 1, j, visited, board);
        }

        if (j + 1 < n && board[i][j + 1] == 'O' && !visited[i][j + 1]) {
            board[i][j + 1] = 'y';
            visited[i][j + 1] = true;
            dfs(i, j + 1, visited, board);
        }

        if (i - 1 >= 0 && board[i - 1][j] == 'O' && !visited[i - 1][j]) {
            board[i - 1][j] = 'y';
            visited[i - 1][j] = true;
            dfs(i - 1, j, visited, board);
        }

        if (j - 1 >= 0 && board[i][j - 1] == 'O' && !visited[i][j - 1]) {
            board[i][j - 1] = 'y';
            visited[i][j - 1] = true;
            dfs(i, j - 1, visited, board);
        }
    }
};