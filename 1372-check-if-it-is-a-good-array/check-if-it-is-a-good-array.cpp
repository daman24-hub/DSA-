class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcdValue = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            gcdValue = gcd(gcdValue, nums[i]);
        } 
        return gcdValue == 1;
    }
};