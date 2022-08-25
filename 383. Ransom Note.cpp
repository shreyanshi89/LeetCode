class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m1;
        map<char, int> m2;
        
        for(int i=0;i<magazine.length();i++)
            m1[magazine[i]]++;
        
        for(int i=0;i<ransomNote.length();i++)
            m2[ransomNote[i]]++;
        
        for(int i=0;i<ransomNote.length();i++){
            auto c1 = m1.find(ransomNote[i]);
            auto c2 = m2.find(ransomNote[i]);
            if(c1->second < c2->second)
                return false;
        }
        return true;
    }
};

//  OR

/*
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        
        for(int i=0;i<magazine.length();i++)
            m[magazine[i]]++;
        
        for(int i=0;i<ransomNote.length();i++){
            if(m[ransomNote[i]]-- <= 0)
                return false;
        }
        return true;
    }
};
*/
