class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int maxLen = 0;
        for(int i=-n+1;i<n;i++){
            int len = 0;
            for(int j=0;j<m;j++){
                if(i+j < 0)
                    continue;
                else if(i+j >= n)
                    break;
                else if(nums1[i+j] == nums2[j])
                    len++;
                else 
                    len = 0;
                maxLen = max(len,maxLen);
            }
        }
        return maxLen;
    }
};
