A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.




int numDecodings(string s)
{
        if(s.length() ==0 || s=="")
            return 0;
        vector<int> f;
        f.resize(s.length());
        
        for(int i=0;i<s.length();i++)
        {
            f[i]=0;
            if(i>=1)
            {
                 if ('1' <= s[i] && s[i] <= '9')
                    f[i] += f[i-1];
                    
                 if(('1' == s[i-1] && s[i] <= '9') || ('2' == s[i-1] && s[i] <= '6'))
                    if(i==1) f[i] += 1;
                    else     f[i] +=f[i-2];
                    
            }else //i==0
            {
                if ('1' <= s[i] && s[i] <= '9')
                    f[i] = 1;
            }
            
        }
        
        return f[s.length()-1];
}




int numDecodings(string s)
{
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
    int r1 = 1, r2 = 1;

    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;

        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}