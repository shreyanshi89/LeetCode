class Solution {
public:

    void lengthstr(int ind, vector<int> vis, vector<string> arr, int len, int& maxLen){
        if(ind < 0){
            maxLen = max(maxLen, len);
            return;
        }

        int n = arr[ind].size();
        int flag = 0;
        vector<int> temp = vis;

        for(int i=0;i<n;i++){
            if(temp[arr[ind][i] - 'a'] == 1){
                flag = 1;
                break;
            }
            temp[arr[ind][i] - 'a'] = 1;
        }

        if(flag == 0)
            lengthstr(ind - 1, temp, arr, len + arr[ind].size(), maxLen);
        lengthstr(ind - 1, vis, arr, len, maxLen);
    }

    int maxLength(vector<string>& arr) {
        int len = 0;
        vector<int> vis(26,0);
        int maxLen = INT_MIN;
        lengthstr(arr.size() - 1, vis, arr, len, maxLen);
        return maxLen;
    }
};
