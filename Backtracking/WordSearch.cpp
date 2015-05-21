Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.



//思路很简单，从每个点出发都试一遍，每次移动的过程中记录
//已被走过的点，回溯的时候要改回状态.  注意若是索引出了边界就回溯
//若是走到了终点 就是把word遍历完 则返回true

 bool isInboard(int i, int j,vector<vector<char>>& board)
    {
        if(i < 0|| i >= board.size() || j < 0 || j >= board[i].size())
            return false;
        return true;
    }
    
    
    bool DFS(int si, int sj, int n,vector<vector<char>>& board,string word,vector<vector<bool>> &b_board)
    {
        if(n == word.size())return true;
        if(isInboard(si, sj,board))
        {
            if(!b_board[si][sj] && board[si][sj] == word[n])
            {
                b_board[si][sj] = true;
                bool ret = false;
                if(DFS(si+1, sj, n+1,board,word,b_board))
                    ret = true;
                else if(DFS(si-1, sj, n+1,board,word,b_board))
                    ret = true;
                else if(DFS(si, sj+1, n+1,board,word,b_board))
                    ret = true;
                else if(DFS(si, sj-1, n+1,board,word,b_board))
                    ret = true;
                b_board[si][sj] = false;
                return ret;
            }
        }
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) 
	{
        
        if(board.size() == 0 || board[0].size() == 0 )return false;
        vector<vector<bool>> b_board(board.size(),vector<bool>(board[0].size(),false));
        for(int i = 0; i < board.size(); i ++)
            for(int j = 0; j < board[i].size(); j ++)
                if(DFS(i, j, 0,board,word,b_board))return true;
        return false;
    }