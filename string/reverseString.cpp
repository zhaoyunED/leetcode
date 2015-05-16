Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

//
void reverseWord(string &s,int left, int right)
{
	while(left <right)
	{
		char temp = s[left];
		s[left++] = s[right];
		s[right--] = temp;
	}
}
//O(1)空间
void reverseWords(string &s) 
{
      int i;
	  int j;//去除空格后实际字符串字符的位置
	  int l=0; //记录每个新的单词的起始位置
	  int len = s.length();
	  bool isFirstWord =true; //第一个单词前面不需要空格

	  while(true)
	{
		while((i< len) && s[i]==' ') i++; //每个word前的空格去掉
		if(i==len) break;
		if(!isFirstWord) s[j++]=' ';// 加空格
		l=j;
		while(i<len && s[i] != ' ') 
		{
			s[j++]=s[i++];
		}
		reverseWord(s,l,j-1);
		isFirstWord = false;
	}

	s.resize(j);

	reverseWord(s,0,j-1);
}

//方法二
