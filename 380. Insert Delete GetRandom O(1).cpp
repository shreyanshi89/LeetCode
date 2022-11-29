class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val))
            return false;
        m[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(m.count(val)){
            int num = nums.back();
            nums[m[val]] = num;
            m[num] = m[val];
            m.erase(val);
            nums.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int index = rand()%nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
