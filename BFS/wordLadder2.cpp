//方法1 是通过不断的找可能的字符与现有比较字符的距离是否为1
//方法2 是通过不断的剩余字典中的字符串与现有比较字符的距离是否为1，若这个字典很大话时间会很长
//function 1
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
          vector<vector<string> >ans;
          if(start == end) return ans;
          unordered_set<string>current , next;
          unordered_set<string> flag;
          unordered_map<string,vector<string> > father;
          
          current.insert(start);

          bool found = false;
         
          while(!current.empty() && !found) {
              //expand
              for(const auto &x : current) {
                  flag.insert(x);
              }
              
              for(auto x : current) {
                  for(int i = 0 ; i < x.size() ; ++i) {
                      for(int j = 'a' ; j <= 'z' ; ++j) {
                          if(x[i] == j) continue;
                          string tmp = x;
                          tmp[i] = j;
                          if(tmp == end) found = true;
                          if(dict.find(tmp) != dict.end() && flag.find(tmp) == flag.end()) {
                              next.insert(tmp);
                              father[tmp].push_back(x);
                          }
                     }
                  }
              }
              //end expand
              
              current.clear();
              swap(current, next);
          }
          //start foudn father
          
          if(found) {
              vector<string> c;
              dfs(ans , father , c , start , end);
          }
          return ans;
    }
private:
    void dfs(vector<vector<string> >&ans, 
             unordered_map<string,vector<string> >& father ,
             vector<string>& c , 
             string& start ,
             string& now) {
                 
        c.push_back(now);
        if(now == start) {
            ans.push_back(c);
            reverse(ans.back().begin() , ans.back().end());
            c.pop_back();
            return;
        }
        auto que = father.find(now) -> second;
        for(auto& x : que) {
            dfs(ans , father , c , start , x);
        }
        c.pop_back();
    }

//function 2
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
{
	vector<vector<string> >ans;
          if(start == end) return ans;
          unordered_set<string>current , next;
          unordered_set<string> flag;
          unordered_map<string,vector<string> > father;
          unordered_set<string> left_dict = dict;
          current.insert(start);

          bool found = false;
         
          while(!current.empty() && !found) {
              //expand
              for(const auto &x : current) {
                  left_dict.erase(x);
              }
              
              for(auto x : current) {
                  auto it = left_dict.begin();
		            while(it != left_dict.end())
		           {
            			if(oneCharDiff(*it,x))
            			{
            				father[*it].push_back(x);
            				if(*it == end) found =true;
            				next.insert(*it); //加到队列中
							it++;
            			}else
            			{
            			  it++;
            			}
		           }
              }
              //end expand
              
              current.clear();
              swap(current, next);
          }
          //start foudn father
          
          if(found) {
              vector<string> c;
              dfs( start , end,c,ans , father );
          }
          return ans;		
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

private:
void dfs(string start, string now,
		vector<string>& c ,
		vector<vector<string> >&ans, 
             unordered_map<string,vector<string> >& father)
{
	c.push_back(now);
	if(start == now)
	{
		
		ans.push_back(c);
		reverse(ans.back().begin() , ans.back().end());
		c.pop_back();
		return;
	}

	auto vect = father.find(now)->second;
	for(auto& x : vect)
	{
		dfs(start , x , c , ans,father);
	}
	c.pop_back();
}


