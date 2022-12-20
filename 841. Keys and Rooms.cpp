class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> s;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int n = q.front();
            q.pop();
            
            if(s.find(n) == s.end())
                s.insert(n);
            else 
                continue;

            for(auto num: rooms[n]){
                if(s.find(num) == s.end())
                    q.push(num);
            }
            if(s.size() == rooms.size())
                return true;
        }
        return false;
    }
};
