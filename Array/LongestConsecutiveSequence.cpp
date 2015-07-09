Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.




//每次找 s-1 与 s+1 数 的 边长度
//See if n - 1 and n + 1 exist in the map, and if so, it means there is an existing sequence next to n. 
//Variables left and right will be the length of those two sequences, 
//while 0 means there is no sequence and n will be the boundary point later. 
//Store (left + right + 1) as the associated value to key n into the map.
 int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int r = 0;
        
        for(int s:nums)
        {
            if(m[s]) continue;
            
            int left = (m.find(s-1) == m.end()) ? 0: m[s-1];
            int right = (m.find(s+1) == m.end()) ? 0: m[s+1];
            
            int leng = right +left +1;
            m[s] =leng;
            
            r = max(leng,r);
            
            m[s-left] = leng;
            m[s+right] = leng;
        }
        return r;
}

//精简版代码

int longestConsecutive(vector<int> &num)
{
    unordered_map<int, int> m;
    int r = 0;
    for (int i : num) {
        if (m[i]) continue;
        r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
    }
    return r;
}