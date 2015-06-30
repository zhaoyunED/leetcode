Given a string S and a string T, find the minimum window 
in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.








string minWindow(string s, string T) 
{
        
        int sLen=s.size();
        int tLen=T.size();
        if(tLen==0 || sLen<tLen) return "";
        
        int needFind[256]={0};//¿ÉÓÃunordered_map ´úÌæ
        int hasFind[256]={0};
        
        for(auto &c : T)
        {
            needFind[c]++;
        }
        
        int minWindowLength=INT_MAX;
        int minBegin=0;
        int minEnd=sLen-1;
        
        int begin =0;
        int end =0;
        int count =0;
        for(;end<sLen;end++)
        {
            if(needFind[s[end]] == 0) continue;
            
            hasFind[s[end]]++;
            if(hasFind[s[end]] <=needFind[s[end]] )
                count++;
                
            if(count == tLen)
            {
                while(begin <end)
                {
                    if(needFind[s[begin]]==0) 
                    {
                        begin++;
                        continue;
                    }
                    if(hasFind[s[begin]] >needFind[s[begin]])
                    {
                        hasFind[s[begin]]--;
                        begin++;
                        continue;
                    }else
                        break;
                }
                
                int tmpWindowLength=end-begin+1;
                
                if(tmpWindowLength < minWindowLength)
                {
                    minBegin=begin;
                    minEnd=end;
                    minWindowLength=tmpWindowLength;
                }
            }
            
        }
        
        if(minWindowLength==INT_MAX)
            return "";
        return s.substr(minBegin,minWindowLength);
 }