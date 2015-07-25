Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true


class TrieNode {
public:
	bool isWord;
    TrieNode *child[26];
    // Initialize your data structure here.
    TrieNode():isWord(false) {
        for (auto &a : child) a = NULL;
    }
};

class WordDictionary {
public:
    
    WordDictionary()
    {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p =root;

		for(auto &sc : word)
		{
			if(p->child[sc-'a'] == NULL) p->child[sc-'a'] =new TrieNode();
			p = p->child[sc-'a'];
		}
		p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        
		return find(word,root);
    }
    
private:
    TrieNode* root;
    
    bool find(string key,TrieNode* root)
	{
		TrieNode* p =root;
		for(int i=0; i<key.size();i++)
		{
		    char sc= key[i];
		    if(sc == '.')
		    {
		        
		        for(auto node : p->child)
		        {
		            
		           if(node != NULL)
		           {
					   bool is = find(key.substr(i+1),node);
					   if(is)
		                   return true;
				   }
		        }
		        
		        return false;
		        
		    }else if(p->child[sc-'a'] != NULL)
				p = p->child[sc-'a'];
			else
				return false;
		}
		return p->isWord;
	}
};