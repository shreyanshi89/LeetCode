class Solution {
public:
    
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans = 0;
        sort(properties.begin(),properties.end(),comp);
        
        int m = INT_MIN;
        for(auto num: properties){
                if(m > num[1])
                    ans++;
                else
                    m = num[1];
        }
        return ans;
    }
};
