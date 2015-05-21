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



//˼·�ܼ򵥣���ÿ�����������һ�飬ÿ���ƶ��Ĺ����м�¼
//�ѱ��߹��ĵ㣬���ݵ�ʱ��Ҫ�Ļ�״̬.  ע�������������˱߽�ͻ���
//�����ߵ����յ� ���ǰ�word������ �򷵻�true

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