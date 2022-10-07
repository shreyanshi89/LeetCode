class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    map<int, int> m;
    bool book(int start, int end) {
        m[start]++;
        m[end]--;

        int ctr = 0;
        for(auto num: m){
            ctr += num.second;
            if(ctr == 3){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
