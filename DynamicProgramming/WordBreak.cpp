Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated 
sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".


//动态规划方法

bool wordBreak(string s, unordered_set<string> &dict)
{
        if(dict.size()==0) return false;

        vector<bool> dp(s.size()+1,false);
        dp[0]=true;

        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }

        return dp[s.size()];
}

//动态规划方法2
//优化版 只针对 字典里面的字符串的大小 进行遍历

bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        if(!n)
            return true;
        vector<bool> ret(n+1, false);
        ret[n] = true;
        unordered_set<int> dsize;
        for(auto d : dict)
            dsize.insert(d.size());
        ret[n] = true;
        for(int i=n-1; i>=0; i--){
            for(auto k : dsize){
                if(i+k<=n && dict.find(s.substr(i,k))!=dict.end() && ret[i+k]){
                    ret[i] = true;
                    break;
                }
            }
        }
        return ret[0];
    }


//BFS的方法
bool wordBreak(string s, unordered_set<string> &dict) {
    // BFS
    queue<int> BFS;
    unordered_set<int> visited;

    BFS.push(0);
    while(BFS.size() > 0)
    {
        int start = BFS.front();
        BFS.pop();
        if(visited.find(start) == visited.end())
        {
            visited.insert(start);
            for(int j=start; j<s.size(); j++)
            {
                string word(s, start, j-start+1);
                if(dict.find(word) != dict.end())
                {
                    BFS.push(j+1);
                    if(j+1 == s.size())
                        return true;
                }
            }
        }
    }

    return false;
}