



//
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