Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.




int lengthOfLastWord(string s)
{
      int i;int size = s.length();
      while(s[size-1]==' ')   s.resize(--size);
      i = s.find_last_of(' ');
      return (i==-1)?size:size-i-1;
}