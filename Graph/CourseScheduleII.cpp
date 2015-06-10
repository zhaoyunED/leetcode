
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order 
is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
Another correct ordering is[0,2,1,3].



//用类似邻接表的结构存储图
//用BFS类似的方法进行拓扑排序
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
{
        vector<unordered_set<int>> table(numCourses);
        
        vector<int> de(numCourses,0);
        
        vector<int> result;
        
        for(auto pair :prerequisites )
        {
            if(table[pair.second].find(pair.first) == table[pair.second].end())
            {
                table[pair.second].insert(pair.first);
                de[pair.first]++;
            }
        }
        
        queue<int> queue;
        for(int i=0;i<numCourses;i++)
        {
           if(de[i] ==0)
            queue.push(i);
        }
        int count = numCourses;
        
        while(!queue.empty())
        {
            int cur = queue.front();
            queue.pop();
            result.push_back(cur);
            count--;
            for(auto s:table[cur])
            {
                de[s]--;
                if(de[s] == 0)
                    queue.push(s);
            }
        }
        
        if(count ==0)
            return result;
        else{
            vector<int> eresult;
            return eresult;
        }
}