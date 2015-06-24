Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false






bool isMatch(string s, string p) 
{
        int s_size = s.size();
        int p_size =p.size();
        int s_i=0,p_i=0;
        
        int s_start=0;
        int p_start =-1;
        while(s_i<s_size)
        {
            if(s[s_i] == p[p_i] || ( p[p_i]=='?' ))
            {
                s_i++;
                p_i++;
                continue;
            }
            
            if(p[p_i] =='*')
            {
                p_start = p_i++;
                s_start = s_i;
                continue;
            }
            
            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if(p_start !=-1)
            {
                p_i =p_start+1;
                s_i = ++s_start;
                continue;
            }
            
            return false;
        }
        
        while(p[p_i] == '*') p_i++;
        
        return p_i>=p_size;
}


// Recursion version.
bool isMatch(const char *s, const char *p) 
{
    if (s == NULL || p == NULL) return false;
    if (*p == '\0') return *s == '\0';
    
    if (*p == '*')
    {
        while (*p == '*') ++p;
        
        while (*s != '\0')
        {
            if (isMatch(s, p)) return true;
            ++s;
        }
        
        return isMatch(s, p);
    }
    else if ((*s != '\0' && *p == '?') || *p == *s)
    {
        return isMatch(s + 1, p + 1);
    }
    
    return false;
}