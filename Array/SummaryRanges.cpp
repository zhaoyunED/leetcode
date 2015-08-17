Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].



vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, size = nums.size();
        vector<string> result; 
        while(i < size){
            int j = 1; 
            while(i + j < size && nums[i + j] - nums[i] == j) ++j;
            result.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j; 
        }
        return result; 
    }