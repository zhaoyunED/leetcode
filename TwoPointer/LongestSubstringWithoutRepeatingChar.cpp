Given a string, find the length of the longest substring without repeating characters. 

For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.





//所有可能的字符 存在 256大小的vector中
int lengthOfLongestSubstring(string s) 
{
        vector<int> vect(256,-1);
        int maxlength =0,start=0;
        for(int i=0;i<s.size();i++)
        {
            start = max(start,vect[s[i]]+1);
            vect[s[i]]=i;
            maxlength = max(maxlength,i-start+1);
        }
        return maxlength;
}