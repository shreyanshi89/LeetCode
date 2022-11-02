class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int ans = 0;
        
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();

                if(curr == end)
                    return ans;
                
                for(char c: "ACGT"){
                    for(int j=0;j<curr.size();j++){
                        string alt = curr;
                        alt[j] = c;
                        if(!visited.count(alt) && find(bank.begin(), bank.end(), alt) != bank.end()){
                            q.push(alt);
                            visited.insert(alt);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
