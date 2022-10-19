class Solution {
public:

struct comp{
    bool operator() (const pair<int, string>& a,const pair<int, string>& b){
        if(a.first == b.first)
            return a.second > b.second;
        else 
            return a.first < b.first;
    }
};

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        vector<string> ans;

        for(int i=0;i<words.size();i++)
            m[words[i]]++;

        priority_queue <pair<int, string>, vector<pair<int, string>> ,comp> pq;
        
        for(auto num:m)
            pq.push({num.second,num.first});
        
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
