class Solution {
public:

    bool static comp(pair<char,int>&  num1, pair<char,int>& num2){
        if(num1.second > num2.second)
            return true;
        return false;
    }

    string frequencySort(string s) {
        map<char, int> m1;
        map<char, int> m2;
        for(int i=0;i<s.length();i++){
            if(s[i] >= 'a')
                m1[s[i]]++;
            else 
                m2[s[i]]++;
        }

        vector<pair<char, int>> nums;
        for(auto num: m1)
            nums.push_back(num);
        for(auto num: m2)
            nums.push_back(num);

        sort(nums.begin(), nums.end(), comp);

        string str = "";
        for(auto num: nums){
            for(int i=0;i<num.second;i++)
                str += num.first;
        }
        return str;
    }
};
