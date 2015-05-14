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
	
	if (dict.empty() || dict.find(start) == dict.end() || dict.find(end) == dict.end()) return 0;//没找到
	
	//每次找和队列中字符串相差1的字符串 并添加到队列中 
	queue<string> q;
        q.push(start);

	unordered_map<string,int> map_visit;//用来保存每个字符串是否被访问过以及需要改变的次数 用un_map保存访问快
        map_visit[start] =1;
	unordered_set<string> left_dict = dict; //保存没有被访问过的字符串
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
				map_visit[*it] = map_visit[word] + 1; //距离加1
				if(*it == end) return map_visit[*it];
				q.push(*it); //加到队列中
				it = left_dict.erase(it);
			}else
			{
			  it++;
			}
		}
	}

	return 0;//没有找到	
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

