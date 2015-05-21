


class TrieNode {
public:
	bool isWord;
    TrieNode *child[26];
    // Initialize your data structure here.
    TrieNode():isWord(false) {
        for (auto &a : child) a = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* p =root;

		for(auto &sc : s)
		{
			if(p->child[sc-'a'] == NULL) p->child[sc-'a'] =new TrieNode();
			p = p->child[sc-'a'];
		}
		p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* p= find(key);
        if(p&&p->isWord)
			return true;
		return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(find(prefix))
			return true;
		return false;
    }
private:
    TrieNode* root;

	TrieNode* find(string key)
	{
		TrieNode* p =root;
		for(auto &sc : key)
		{
			if(p->child[sc-'a'] != NULL)
				p = p->child[sc-'a'];
			else
				return NULL;
		}
		return p;
	}
};