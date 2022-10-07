class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    map<int, int>m;
    int maxBook = INT_MIN;
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int ctr = 0;
        for(auto num: m){
            ctr += num.second;
            maxBook = max(maxBook, ctr);
        }
        return maxBook;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
