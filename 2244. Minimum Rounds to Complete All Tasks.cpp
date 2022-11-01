class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map<int, int> m;

        for(int i=0;i<tasks.size();i++)
            m[tasks[i]]++;
        
        int x = 0;
        for(auto num: m){
            cout<<num.second<<" ";
            if(num.second == 1)
                return -1;

            int a = num.second;
            while(a){
                if(a == 1)
                    return -1;

                else if(a % 3 == 0){
                    ans++;
                    a -= 3;
                }
                
                else if(a % 2 == 0){
                    ans++;
                    a -= 2;
                }

                else {
                    if(a % 3 == 2){
                        ans++;
                        a -= 3;
                    }
                    else {
                        ans++;
                        a -= 2;
                    }
                }
            }
        }
        return ans;
    }
};
