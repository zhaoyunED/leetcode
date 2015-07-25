Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.





//通过trie树来辅助搜索
//若在trie树中找不到对应的节点 直接回溯
class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;

    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
    
public:
	TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

};


class Solution {
public:

    bool isInboard(int i, int j,vector<vector<char>>& board)
    {
            if(i < 0|| i >= board.size() || j < 0 || j >= board[i].size())
                return false;
            return true;
    }

    void DFS(TrieNode *root,int si, int sj,vector<vector<char>>& board,vector<vector<bool>> &b_board,vector<string>& res,string& s)
    {
    	if(isInboard(si,sj,board))
    	{
    		if(!b_board[si][sj] && (nullptr != root->next[board[si][sj]-'a']) )
                {
                    
                    b_board[si][sj] = true;
                    s.push_back(board[si][sj]);
                    
                    if(root->next[board[si][sj]-'a']->is_word)
                    {
                        res.push_back(s);
                        root->next[board[si][sj]-'a']->is_word = false; // set to false to indicate that we found it already
                    }
                    
                    DFS(root->next[board[si][sj]-'a'],si+1, sj, board,b_board,res,s);
                    DFS(root->next[board[si][sj]-'a'],si-1, sj, board,b_board,res,s);
                    DFS(root->next[board[si][sj]-'a'],si, sj+1, board,b_board,res,s);
                    DFS(root->next[board[si][sj]-'a'],si, sj-1, board,b_board,res,s);

                    s.pop_back();
                    b_board[si][sj] = false; //important
                    
                }
    	}
    }



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
           vector<string> res;
           if(board.size()==0 || board[0].size()==0 || words.size() ==0)
                return res;
           int row = board.size();
           int col = board[0].size();
           int wordCount = words.size();

           Trie *trie = new Trie();
           for(int i=0 ;i<wordCount; i++)
                trie->insert(words[i]);
           vector<vector<bool>> b_board(row,vector<bool>(col,false));
          //xunhuan
          string s="";
          for(int i=0; i<row ;i++)
          for(int j=0 ;j<col && wordCount>res.size() ;j++)
            {
				DFS(trie->root,i,j,board,b_board,res,s);
            }
         return res;
    }
};