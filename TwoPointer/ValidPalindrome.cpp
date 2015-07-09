Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

//简单的twopointer题目
bool isPalindrome(string s) {
        
        int st=0,e=s.size()-1;
       
        while(st<e)
        {
            
            if( !isalpha(s[st]) ) {
                ++st;
                continue;
              }
              if( !isalpha(s[e]) ) {
                --e;
                continue;
              }
            
            if(s[st] != s[e])
                return false;
            st++;
            e--;
        }
        
        return true;
    }
    
    
bool isalpha(char &c)
{
    if((c>='A'&&c<='Z')){
      c = c-'A'+'a';
      return true;
    }
    return (c>='a'&&c<='z') || (c>='0'&&c<='9');
}