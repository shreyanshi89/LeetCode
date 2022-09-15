class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        sort(changed.begin(),changed.end());
        unordered_map<int, int> m;
        
        for(int num: changed)
            m[num]++;
        
        for(int num: changed){
            auto l = m.find(num);
            auto it = m.find(2 * num);
            
            if(l->second == 0)
                continue;
            
            else if(it == m.end() || l->second > it->second)
                return {};
            
            else if(num == 0){
                if(l->second % 2 == 0){
                    for(int i=0;i<l->second/2;i++)
                        ans.push_back(num);
                    l->second = 0;
                }
                else 
                    return {};
            }
            
            
            else {
                for(int i=0;i<l->second;i++)
                    ans.push_back(num);
                it->second -= (l->second);
                l->second = 0;
            }
        }
        return ans;
    }
};

// OR
/*
Simplified: 

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        sort(changed.begin(),changed.end());
        unordered_map<int, int> m;
        
        if(changed.size() % 2 != 0)
            return {};
        
        for(int num: changed)
            m[num]++;
        
        for(int num: changed){
            auto l = m.find(num);
            auto it = m.find(2 * num);
            
            if(l->second == 0)
                continue;
            
            else if(it == m.end() || l->second > it->second)
                return {};
          
            ans.push_back(num);
            it->second -=1;
            l->second -= 1;
        }
        return ans;
    }
};
*/
