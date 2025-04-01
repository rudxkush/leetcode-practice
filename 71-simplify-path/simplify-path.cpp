class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string> dir;

        for(int i = 0; i < n; i++) {
           if(path[i] == '/') continue;

           string blah = "";
           while(i < n && path[i] != '/') {
            blah += path[i];
            i++;
           } 

           if(blah == ".") continue;
           else if(blah == "..") {
            if(!dir.empty()) dir.pop();
           }
           else dir.push(blah);
        } 

        string res = "";
        while(!dir.empty()) {
            res =  "/" + dir.top() + res;
            dir.pop();
        }
        if(res.size() == 0) return "/";

        return res;
    }
};
/*
    '.', '...' -> nothing has to be done
    '..' -> pop it as we come out of a directory
    '//', '///', '/' -> should be just repersented as '/'

    Ex: path = "/home/user/Documents/../Pictures"
    output = "/home/user/Pictures"
*/