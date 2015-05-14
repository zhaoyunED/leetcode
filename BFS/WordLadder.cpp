Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.


 public:
    int ladderLength(string start, string end, unordered_set<string> &dict) 
{
	
	if (dict.empty() || dict.find(start) == dict.end() || dict.find(end) == dict.end()) return 0;//û�ҵ�
	
	//ÿ���ҺͶ������ַ������1���ַ��� ����ӵ������� 
	queue<string> q;
        q.push(start);

	unordered_map<string,int> map_visit;//��������ÿ���ַ����Ƿ񱻷��ʹ��Լ���Ҫ�ı�Ĵ��� ��un_map������ʿ�
        map_visit[start] =1;
	unordered_set<string> left_dict = dict; //����û�б����ʹ����ַ���
	left_dict.erase(start);

	while(q.size()!=0)
	{
		string word = q.front();
		q.pop();
		auto it = left_dict.begin();
		while(it != left_dict.end())
		{
			if(oneCharDiff(*it,word))
			{
				map_visit[*it] = map_visit[word] + 1; //�����1
				if(*it == end) return map_visit[*it];
				q.push(*it); //�ӵ�������
				it = left_dict.erase(it);
			}else
			{
			  it++;
			}
		}
	}

	return 0;//û���ҵ�	
}

inline bool oneCharDiff(const string& str1, const string& str2)
{
	int diff =0;
	for(int i=0;i<str1.size();i++)
	{
		if(str1[i] !=str2[i])
			diff++;
		if(diff>1) break;
	}
	return diff == 1;
}

