Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?


//O(k)的空间 在 原数组上 进行操作
vector<int> getRow(int rowIndex)
{
        vector<int> result;
        if(rowIndex<0)
            return result;
        result.push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            int size = result.size();
            for(int j=size-1; j>0;j--)
            {
                result[j] += result[j-1];
            }
            result.push_back(1);
        }
        
        return result;
}