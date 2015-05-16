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
//O(1)�ռ�
void reverseWords(string &s) 
{
      int i;
	  int j;//ȥ���ո��ʵ���ַ����ַ���λ��
	  int l=0; //��¼ÿ���µĵ��ʵ���ʼλ��
	  int len = s.length();
	  bool isFirstWord =true; //��һ������ǰ�治��Ҫ�ո�

	  while(true)
	{
		while((i< len) && s[i]==' ') i++; //ÿ��wordǰ�Ŀո�ȥ��
		if(i==len) break;
		if(!isFirstWord) s[j++]=' ';// �ӿո�
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

//������
