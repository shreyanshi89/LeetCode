class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {        
        unordered_map<int, int> m;

        for(auto t: trust){
            m[t[0]]--;
            m[t[1]]++;
        }

        for(int i=1;i<n+1;i++){
            if(m[i] == n-1)
                return i;
        }

        return -1;
    }
};
