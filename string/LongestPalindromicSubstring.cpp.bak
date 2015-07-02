Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.




//方法一 O(n^2)的算法 粗暴法

string longestPalindrome(string s) 
{
        int len = s.length(), max = 1, ss = 0, tt = 0;
        bool flag[len][len];
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                if (i >= j)
                    flag[i][j] = true;
                else flag[i][j] = false;
        for (int j = 1; j < len; j++)
            for (int i = 0; i < j; i++)
            {
                if (s[i] == s[j])
                {
                    flag[i][j] = flag[i+1][j-1];
                    if (flag[i][j] == true && j - i + 1 > max)
                    {
                        max = j - i + 1;
                        ss = i;
                        tt = j;
                    }
                }
                else flag[i][j] = false;
            }
        return s.substr(ss, max);
}

//方法二 Is it O(n) ?

 string longestPalindrome(string s) 
{
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) 
		{
			  if (s.size() - i <= max_len / 2) break;
			  int j = i, k = i;
			  while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
			  i = k+1;
			  while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
			  int new_len = k - j + 1;
			  if (new_len > max_len) { min_start = j; max_len = new_len; }
        }
        return s.substr(min_start, max_len);
 }

 //方法三 Manacher's algorithm
 
string longestPalindrome(string s) 
{
        string t;
	for(int i=0;i<s.size();i++)
		t=t+"#"+s[i];
	t.push_back('#');

	vector<int> P(t.size(),0);
	int center=0,boundary=0,maxLen=0,resCenter=0;

	for(int i=1;i<t.size()-1;i++)
	{
		int j= 2*center -i;

		if(boundary>i) 
		{
			P[i] = min(P[j],boundary-i);
		}else
		P[i] =0;

		while(i-1-P[i]>=0 && i+1+P[i]<t.size() && t[i+1+P[i]] ==  t[i-1-P[i]])
			P[i]++;
		if(i+P[i]>boundary) 
		{ // update center and boundary
                center = i;
                boundary = i+P[i];
		}

		if(P[i]>maxLen) 
		{ // update result
                maxLen = P[i];
                resCenter = i;
        } 
	}
	return s.substr((resCenter - maxLen)/2, maxLen);
}