// T.C. - O(nlogn)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        map<int, int> m;

        for(int i=0;i<arr.size();i++)
                m[arr[i]] = 0;
        
        int a = 1;
        for(auto it = m.begin();it != m.end();it++){
            it->second = a;
            a++;
        }
        
        for(int i=0;i<arr.size();i++){
            auto it = m.find(arr[i]);
            ans.push_back(it->second);
        }
        return ans;
    }
};
