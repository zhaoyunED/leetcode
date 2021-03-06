Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines 
are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.



// two pointers
int maxArea(vector<int> &height)
{
	if (height.empty()) return 0;
	int result =0;
	
	int l=0;
	int r = height.size()-1;
	
	int area =0;
	while(l<r)
	{
		area = (r-l)*(min(height[l], height[r]));
		result = max(result,area);

		if(height[l] < height[r])
		{
			do
			{
               l++;
            } while (l < r && height[l-1] >= height[l]);
		}else
		{
			 do
			 {
                 r--;
             } while (r > l && height[r+1] >= height[r]);
		}
	}

	return result;	
}