class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs((ay2 - ay1)*(ax2 - ax1));
        int area2 = abs((by2 - by1)*(bx2 - bx1));
        
        pair<int, int> right;
        pair<int, int> left;
        right.first = min(ax2, bx2);
        right.second = min(ay2, by2);
        left.first = max(ax1, bx1);
        left.second = max(ay1, by1);
        
        int area = 0;
        if(bx1 < ax2 && by1 < ay2 && ax1 < bx2 && ay1 < by2)
            area = abs(right.second - left.second) * abs(right.first - left.first);
        return area1 + area2 - area;
    }
};
