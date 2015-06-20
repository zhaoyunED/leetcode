Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)




//two pointer的思路
vector<vector<int> > fourSum(vector<int> &num, int target) 
{
    vector<vector<int> > ret;
    
    if (num.size() == 0) return ret;
    
    sort(num.begin(), num.end());
    
    for (size_t a = 0; a < num.size(); ++a)
    {
        if (a != 0 && num[a] == num[a - 1])
        {
            continue;
        }
        
        for (size_t b = a + 1; b < num.size(); ++b)
        {
            if (b != a + 1 && num[b] == num[b - 1])
            {
                continue;
            }
            
            size_t c = b + 1;
            size_t d = num.size() - 1;
            
            while (c < d)
            {
                const int sum = num[a] + num[b] + num[c] + num[d];
                
                if (sum > target)
                {
                    --d;
                }
                else if (sum < target)
                {
                    ++c;
                }
                else if (c != b + 1 && num[c] == num[c - 1])
                {
                    ++c;
                }
                else if (d != num.size() - 1 && num[d] == num[d + 1])
                {
                    --d;
                }
                else
                {
                    vector<int> result;
                    
                    result.push_back(num[a]);
                    result.push_back(num[b]);
                    result.push_back(num[c]);
                    result.push_back(num[d]);
                    
                    ret.push_back(result);
                    
                    ++c;
                    --d;
                }
            }
        }
    }
    
    return ret;
}

//方法二 还有hashmap的思路