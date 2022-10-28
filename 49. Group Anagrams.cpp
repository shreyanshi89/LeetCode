class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;

        for(string str: strs){
            string s = str;
            sort(s.begin(),s.end());
            m[s].push_back(str) ;
        }

        for(auto num: m){
            vector<string> res;
            for(int i=0;i<num.second.size();i++)
                res.push_back(num.second[i]);
            ans.push_back(res);
        }
        return ans;
    }
};
