Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

//先进行排序 然后找size>2的数字
vector<string> anagrams(vector<string>& strs) {
        vector<string> result;
        unordered_map<string,vector<string>> hash;
        
        for(auto &str : strs)
        {
            string temp = str;
            sort(str.begin(),str.end());
            hash[str].push_back(temp);
        }
        
        for(auto map : hash)
        {
            if(map.second.size()>1)
                result.insert(result.end(),map.second.begin(),map.second.end());
        }
        
        return result;
    }