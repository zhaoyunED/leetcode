implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.


//∆”ÀÿÀ„∑®
int strStr(string haystack, string needle)
{
        
        int len_a = haystack.size();
        int len_b = needle.size();
        
        if (len_a < len_b) return -1;

        for (int i = 0; i <= len_a-len_b; ++i) {
            int j = 0;
            while(j < len_b && haystack[j+i] == needle[j]) {
                j++;
            }
            if (j == len_b) {
                return i;
            }
        }
        return -1;
}

//KMPÀ„∑®

int strStr(string haystack, string needle) 
{
        if(needle =="") return 0;
        
        int need_len = needle.size();
        vector<int> next(need_len,-1);
        
        int k = -1;
        for(int i=1; i<need_len ;i++)
        {
            while(k>-1 && needle[k+1] != needle[i])
                k = next[k];
            if(needle[k+1] == needle[i])
                k++;
            next[i] =k;
        }
        
        int q=-1;
        int h_len = haystack.size();
        for(int i=0 ; i<h_len ; i++)
        {
            while(q>-1 && needle[q+1] != haystack[i])
                q= next[q];
            if(needle[q+1] == haystack[i])
                q++;
            if(q == need_len-1)
            {
                return i-q;
            }
        }
        
        return -1;
}