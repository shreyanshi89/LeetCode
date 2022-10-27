class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(event2[0] <= event1[1] && event1[0] <= event2[1])
            return true;
        return false;
    }
};

//  OR (Extra Memory)
/*
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int s1 = ((10*(event1[0][0] - '0')) + event1[0][1] - '0') * 60 + ((10*(event1[0][3] - '0')) + event1[0][4] - '0');
        int s2 = ((10*(event2[0][0] - '0')) + event2[0][1] - '0') * 60 + ((10*(event2[0][3] - '0')) + event2[0][4] - '0');
        int e1 = ((10*(event1[1][0] - '0')) + event1[1][1] - '0') * 60 + ((10*(event1[1][3] - '0')) + event1[1][4] - '0');
        int e2 = ((10*(event2[1][0] - '0')) + event2[1][1] - '0') * 60 + ((10*(event2[1][3] - '0')) + event2[1][4] - '0');
        if(s2 <= e1 && s1 <= e2)
            return true;
        return false;
    }
};
*/
