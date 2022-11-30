class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;

        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;

        arr.clear();
        for(auto num: m)
            arr.push_back(num.second);
        
        sort(arr.begin(), arr.end());
        for(int i=1;i<arr.size();i++){
            if(arr[i-1] == arr[i])
                return false;
        }
        return true;
    }
};
