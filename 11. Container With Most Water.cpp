class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int i = 0;
        int j = height.size() - 1;
        int lh = 0, rh = 0;
        while(i<j){
            int area = 0;
            if(height[i] < height[j]){
                if(height[i] > lh){
                    area = min(height[i],height[j]) * (j - i);
                }
                i++;
            }
            else {
                if(height[j] > rh){
                    area = min(height[i],height[j]) * (j - i);
                }
                j--;
            }
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};
