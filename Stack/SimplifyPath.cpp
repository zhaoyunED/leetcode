
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".


//方法1
string simplifyPath(string path) 
{
       vector<string>   nameVect;
        string name;
    
        path.push_back('/');
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(name.size()==0)continue;
                if(name==".."){     //special case 1：double dot，pop dir
                     if(nameVect.size()>0)nameVect.pop_back();
                }else if(name=="."){//special case 2:singel dot，don`t push
                }else{          
                    nameVect.push_back(name);
                }
                name.clear();
            }else{
                name.push_back(path[i]);//record the name
            }
        }
    
        string result;
        if(nameVect.empty())return "/";
        for(int i=0;i<nameVect.size();i++){
            result.append("/"+nameVect[i]);
        }
        return result;
}

//方法2 利用 stringstream 的 getline方法 类似于 java 的split
string simplifyPath(string path)
{
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}