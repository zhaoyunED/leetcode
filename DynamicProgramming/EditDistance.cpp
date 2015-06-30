Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
//典型的字符串匹配的问题



//方法1 O(mn)的空间
int minDistance(string word1, string word2)
{
       vector<vector<int>> distance(word1.length()+1, vector<int>(word2.length()+1, 0));
       
       for(int i=0;i<=word1.length();i++)
            distance[i][0]=i;
       for(int i=0;i<=word2.length();i++)
            distance[0][i]=i;
     
     // when insert a char to word1 it means we are trying to match word1 at i-1 to word2 at j
     // when delete a char from word1 it equals to insert a char to word2, which
     // means we are trying to match word1 at i to word2 at j-1
     // when replace a char to word1, then we add one step to previous i and j
       for(int i=1; i< distance.size(); i++)
       for(int j=1; j<distance[0].size(); j++){
            if(word1[i-1] == word2[j-1])
                distance[i][j] = distance[i-1][j-1];
            else
                distance[i][j] = 1+ min(distance[i-1][j-1], min(distance[i-1][j], distance[i][j-1]));//important to understand
        }
        
        return distance[word1.length()][word2.length()];
}

//O(n)的空间复杂度
//(a) if we replaced c with d: f[i][j] = f[i-1][j-1] + 1;
//(b) if we added d after c: f[i][j] = f[i][j-1] + 1;
//(c) if we deleted c: f[i][j] = f[i-1][j] + 1;
//Note that f[i][j] only depends on f[i-1][j-1], f[i-1][j] and f[i][j-1], 
//therefore we can reduce the space to O(n) by using only the (i-1)th array and previous updated element(f[i][j-1]).

int minDistance(string word1, string word2)
{
        int l1 = word1.size();
        int l2 = word2.size();

        vector<int> f(l2+1, 0);
        for (int j = 1; j <= l2; ++j)
            f[j] = j;

        for (int i = 1; i <= l1; ++i)
        {
            int prev = i;
            for (int j = 1; j <= l2; ++j)
            {
                int cur;
                if (word1[i-1] == word2[j-1]) {
                    cur = f[j-1];
                } else {
                    cur = min(min(f[j-1], prev), f[j]) + 1;
                }

                f[j-1] = prev;
                prev = cur;
            }
            f[l2] = prev;
        }
        return f[l2];
}