class Solution {
public:
    
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        vector<pair<int, int>> res(arr.size());
        for(int i=0;i<arr.size();i++){
            res[i].first = abs(arr[i] - x);
            res[i].second = arr[i];
        }
        
        sort(res.begin(),res.end(),comp);
        for(int i=0;i<k;i++)
            ans.push_back(res[i].second);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
