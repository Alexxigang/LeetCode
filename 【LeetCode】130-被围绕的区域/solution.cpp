class Solution {
/*
先找到边缘的'o'，把这些干扰的换成'$'（利用dfs把与这些边缘相连的'o'都换掉）,然后重新遍历，遇到'o'则换成'X',遇到'$'换成'O'
*/
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((i==0||i==board.size()-1||j==0||j==board[0].size()-1)&&board[i][j]=='O'){
                    solvedfs(board,i,j);
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='$')board[i][j]='O';
                
            }
            
    }
    }
private:
    void solvedfs(vector<vector<char>> &board,int i,int j){
       if(board[i][j]=='O'){
      
        board[i][j]='$';
        int m=board.size(),n=board[0].size();
        if(i>0&&board[i-1][j]=='O'){
            solvedfs(board,i-1,j);
        }
        if(i<m-1&&board[i+1][j]=='O'){
            solvedfs(board,i+1,j);
        }
        if(j>0&&board[i][j-1]=='O'){
            solvedfs(board,i,j-1);
        }
        if(j<n-1&&board[i][j+1]=='O'){
            solvedfs(board,i,j+1);
        }
                
       }
    }
};
