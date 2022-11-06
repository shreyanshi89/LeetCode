class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        string min = s;
        string str = s;
        do{
            str += str[0];
            string m(str.begin() + 1, str.end());
            str = m;
            if(str < min)
                min = str;
        }while(s != str);
        return min;
    }
};
