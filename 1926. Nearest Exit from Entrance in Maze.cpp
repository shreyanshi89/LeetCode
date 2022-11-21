class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int level = 0;

        int a[4] = {1, -1, 0, 0};
        int b[4] = {0, 0, 1, -1};
        maze[entrance[0]][entrance[1]] = '+';

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                if(x == 0 || y == 0 || x == maze.size() - 1 || y == maze[0].size() - 1){
                    if(x != entrance[0] || y != entrance[1])
                        return level;
                }
                for(int i=0;i<4;i++){
                    int newx = a[i] + x;
                    int newy = b[i] + y;
                    if(newx >= 0 && newy >= 0 && newx <= maze.size() - 1 && newy <= maze[0].size() - 1){
                        if(maze[newx][newy] == '.'){
                            q.push({newx, newy});
                            maze[newx][newy] = '+';
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
