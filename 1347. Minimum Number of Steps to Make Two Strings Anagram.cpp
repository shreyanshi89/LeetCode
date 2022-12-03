// My Approach
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> nums1(26,0);
        vector<int> nums2(26,0);

        for(int i=0;i<s.length();i++){
            nums1[s[i] - 'a']++;
            nums2[t[i] - 'a']++;
        }

        int ctr = 0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] - nums2[i] > 0)
                ctr += (nums1[i] - nums2[i]);
        }
        return ctr;
    }
};

/*  OR
// Updated Approach
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> nums(26,0);

        for(int i=0;i<s.length();i++){
            nums[s[i] - 'a']++;
            nums[t[i] - 'a']--;
        }

        int ctr = 0;
        for(auto num: nums){
            if(num > 0)
                ctr += num;
        }
        return ctr;
    }
};
*/
