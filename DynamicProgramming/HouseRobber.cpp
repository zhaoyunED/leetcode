You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is 
that adjacent houses have security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount 
of money you can rob tonight without alerting the police.



int rob(vector<int> &num)
{
        
        if(num.size()<=0)
        {
            return 0;
        }
        if(num.size()==1)
            return num[0];
        vector<int> result(num.size(),0);
        result[0]=num[0];
        result[1]=max(num[0],num[1]);
        
        for(int i=2;i<num.size();i++)
        {
            result[i]=max(result[i-1],num[i]+result[i-2]);
        }
        
        return result[num.size()-1];
}