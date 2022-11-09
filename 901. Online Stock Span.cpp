// Accepted using stack

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    stack<pair<int, int>> st;
    int next(int price) {
        int ctr =  1;
        while(!st.empty() && st.top().first <= price){
            ctr += st.top().second;
            st.pop();
        }
        st.push({price, ctr});
        return ctr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/* 
//  OR  
//  Naive Approach (TLE)

    vector<int> res;
    int next(int price) {
        int ctr = 0;
        for(int i=0;i<res.size();i++){
            if(res[i] <= price) 
                ctr++;
            
            else 
                ctr = 0;
        }
        res.push_back(price);
        return 1 + ctr;
    }
};
