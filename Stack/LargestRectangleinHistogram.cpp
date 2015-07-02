Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.


//典型的stack 使用
int largestRectangleArea(vector<int> &height)
{
        
     if(height.size() == 0) return 0;
         
        int res = 0;
        vector<int> tmp = height;
        tmp.push_back(0);  // Important  让 最终所有的元素出栈
 
        stack<int> s;
        for(int i = 0; i < tmp.size(); i++)
        {
            if(s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()])) s.push(i);
            else{
                while(!s.empty() && tmp[s.top()] > tmp[i])
                {
                    int idx = s.top(); s.pop();
                    int width = s.empty() ? i : (i-s.top()-1);
                    res = max(res, tmp[idx] * width);
                }
                s.push(i);  // Important
            }
        }
     return res;
}