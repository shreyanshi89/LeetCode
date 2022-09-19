class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(auto path: paths){
            string dir;
            int i = 0;
            for(i=0;i<path.size() && path[i] != ' ';i++)
                dir += path[i];
            i++;
            while(i < path.size()){
                string name;
                while(i < path.size() && path[i] != '(')
                    name += path[i++];
                
                string content = "";
                while(i<path.size() && path[i] != ' ')
                    content += path[i++];
                m[content].push_back(dir + '/' + name);
                i++;
            }
        }
        
        for(auto num:m){
            if(num.second.size() > 1)
                ans.push_back(num.second);
        }
        return ans;
    }
};
