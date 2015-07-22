There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, 
and to take course 0 you should also have finished course 1. So it is impossible.



//DFS

bool DFS(vector<unordered_set<int>>& table,vector<int> &color,int num)
{
        color[num] =-1; //正在被访问还没有访问完事
         for(auto  i: table[num])
        {
            if(color[i] ==-1)
                return false;
            if(color[i]==0 && !DFS(table,color,i))
                return false;
        }
        color[num] =1; //访问完成
        return true;
}


bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<unordered_set<int>> table(numCourses);
        
        vector<int> color(numCourses, 0);
        
        for(auto s:prerequisites)
        {
           if(table[s.second].find(s.first) == table[s.second].end())
			{
				table[s.second].insert(s.first);
			}
        }
        
        for(int i =0;i<numCourses ;i++)
        {
            if(color[i] ==0)
                if(!DFS(table,color,i))
                    return false;
        }
        
        return true;
}



//BFS

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
        vector<unordered_set<int>> table(numCourses);
        
        vector<int> de(numCourses, 0);
        
        for(auto s:prerequisites)
        {
           if(table[s.second].find(s.first) == table[s.second].end())
			{
				table[s.second].insert(s.first);
				de[s.first]++;
			}
        }
        
        queue<int> queue;
        for (int i = 0; i < numCourses; ++ i)
            if (de[i] == 0)
                queue.push(i);
        
        int count = numCourses;
        
        while(!queue.empty())
        {
            int cur = queue.front();
            queue.pop();
            count --;
            
            for(auto  i: table[cur])
            {
                de[i]--;
                if (de[i] == 0)
                    queue.push(i);
            }
        }
        
        return count ==0;
        
}