class Solution {
public:

    void dfs(int i, vector<int>& edges, int dist, vector<int>& graph){
        while(i != -1 && graph[i] == -1){
            graph[i] = dist++;
            i = edges[i];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> g1(n, -1);
        vector<int> g2(n, -1);

        dfs(node1, edges, 0, g1);
        dfs(node2, edges, 0, g2);

        int ans = -1;
        int minDist = INT_MAX;
        for(int i=0;i<n;i++){
            if(min(g1[i], g2[i]) >= 0 && max(g1[i] , g2[i]) < minDist){
                minDist = max(g1[i], g2[i]);
                ans = i;
            }
        }
        return ans;
    }
};
