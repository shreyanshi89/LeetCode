class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        
        for(int i=2;i<=n;i++){
            string prev = ans;
            int l = ans.size();
            int j = 0;
            ans = "";
            while(j < l){
                int ctr = j;
                while(j < l && prev[j] == prev[ctr])
                    ctr++;
                ans += to_string(ctr - j) + prev[j];
                j = ctr;
            }
        }
        return ans;
    }
};
