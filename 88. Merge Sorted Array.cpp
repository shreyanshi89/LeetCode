// T.C. :- O(m+n) 
// S.C. :- O(m);

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int num[m+1];
        for(int i=0;i<m;i++)
            num[i] = nums1[i];
        num[m] = INT_MAX;
        nums2.resize(n+1);
        nums2[n] = INT_MAX;
        int a = 0;
        int i = 0;
        int j = 0;
        while(i <= m && j <= n){
            if(a == m+n)
                break;
            if(num[i] <= nums2[j])
                nums1[a++] = num[i++];
            else if(num[i] > nums2[j])
                nums1[a++] = nums2[j++];
        }
    }
};
