class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> m;

        for(int i=0;i<nums2.size();i++){
            int j = i+1;
            int ctr;
            while(j<nums2.size() && nums2[j] < nums2[i]) 
                j++;

            if(j == nums2.size())
                ctr = -1;
            else
                ctr = nums2[j];
            m[nums2[i]] = ctr;
        }   

        for(int i=0;i<nums1.size();i++)
            ans.push_back(m[nums1[i]]);
        return ans;
    }
};
