// TC - O(n)  &   SC - O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int num: nums){
            if(i < 2 || num > nums[i-2])
                nums[i++] = num;
        }
        return i;
    }
};


/*  OR
//  TC - O(n)  &   SC - O(n) 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> m;

        for(int num: nums) {
            if(m[num] < 2)
                m[num]++;
        }

        int i = 0;
        for(auto num: m){
            nums[i++] = num.first;
            if(num.second == 2)
                nums[i++] = num.first;
        }
        return i;
    }
};
*/
