class Solution {
public:

    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i,int j,vector<vector<char>> &board){
        board[i][j] = '#';
        int n = board.size();
        int m = board[0].size();
        for(auto it: dir){
            int r = i+it.first;
            int c = j+it.second;
            if(r>=0 && r<n && c>=0 && c<m && board[r][c] == 'O'){
                dfs(r,c,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();    // rows
        int c = board[0].size(); // cols
        
        for(int i=0;i<c;i++){
            if(board[0][i] == 'O'){
                dfs(0,i,board);
            }
        }
        for(int i=0;i<c;i++){
            if(board[r-1][i] == 'O'){
                dfs(r-1,i,board);
            }
        }
        for(int i=0;i<r;i++){
            if(board[i][0] == 'O'){
                dfs(i,0,board);
            }
        }
        for(int i=0;i<r;i++){
            if(board[i][c-1] == 'O'){
                dfs(i,c-1,board);
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};
