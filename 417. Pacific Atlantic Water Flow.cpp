class Solution {
public:
    
    void traverse(vector<vector<int>>& heights,int i,int j,int prev,vector<vector<int>>& ocean){
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size())
            return;
        
        if(ocean[i][j] == 1)
            return;
        
        if(prev > heights[i][j])
            return;
        
        ocean[i][j] = 1;
        
        traverse(heights,i+1,j,heights[i][j],ocean);
        traverse(heights,i-1,j,heights[i][j],ocean);
        traverse(heights,i,j+1,heights[i][j],ocean);
        traverse(heights,i,j-1,heights[i][j],ocean);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        if(heights.empty())
            return ans;
            
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> pacific(row,vector<int> (col,0));
        vector<vector<int>> atlantic(row,vector<int> (col,0));
        
        for(int i=0;i<row;i++){
            traverse(heights,i,0,INT_MIN,pacific);
            traverse(heights,i,col-1,INT_MIN,atlantic);
        }
        
        for(int i=0;i<col;i++){
            traverse(heights,0,i,INT_MIN,pacific);
            traverse(heights,row-1,i,INT_MIN,atlantic);
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(atlantic[i][j] == 1 && pacific[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<pacific[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<atlantic[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};
