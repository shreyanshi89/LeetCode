class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
            return false;

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for(int i=0;i<word1.length();i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }

        for(int i=0;i<word1.length();i++){
            if(m1.find(word2[i]) == m1.end())
                return false;
        }
        
        for(int i=0;i<word1.length();i++){
            if(m2.find(word1[i]) == m2.end())
                return false;
        }

        vector<int> arr1;
        vector<int> arr2;
        for(auto num: m1)
            arr1.push_back(num.second);
        for(auto num: m2)
            arr2.push_back(num.second);
        
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        for(int i=0;i<arr1.size();i++){
            if(arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
};
