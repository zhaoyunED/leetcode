Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)




//DFS + »ØËÝ
vector<string> restoreIpAddresses(string s)
{
        vector<int> nums;  
        vector<string> result;  
        
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }
        
        getAllIp(result,s,0,nums);
        
        return result;
}
    
void getAllIp(vector<string> &result,string s,int idx,vector<int> nums)
{
        if(nums.size() == 4 && idx == s.size())  
        {  
            string tmp = s;  
            for(int i = nums.size()-2; i >= 0; --i) tmp.insert(nums[i]+1, 1, '.');//insert char before pos  
            result.push_back(tmp);  
            return;  
        }
        
        if(nums.size() >= 4 || idx >= s.size()) return;
        
        if(s[idx] == '0')
        {
            nums.push_back(idx);  
            getAllIp(result,s, idx+1,nums);  
            nums.pop_back();
            return;
        }
        
        int curNum =0;
        
        for( int i= idx; i< s.size();i++)
        {
            curNum = curNum*10 + s[i]-'0';
            if(curNum > 255)
                break;
            nums.push_back(i);  
            getAllIp(result,s, i+1,nums);  
            nums.pop_back(); 
        }
}