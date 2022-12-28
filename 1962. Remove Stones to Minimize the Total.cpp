class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        
        int sum = 0;
        for(int i=0;i<piles.size();i++)
            sum += piles[i];

        for(int i=0;i<k;i++){
            int num = pq.top();
            sum -= num / 2;

            pq.pop();
            pq.push(num - num/2);
        }
        return sum;
    }
};
