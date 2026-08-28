class Solution {
public:

    int countSubarrays(vector<int>& nums, long long maxSum) {
        
        int count = 1;
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (sum + nums[i] <= maxSum) {
                sum += nums[i];
            }
            else {
                count++;
                sum = nums[i];
            }
        }

        return count;
    }

    int splitArray(vector<int>& nums, int k) {

        long long low = nums[0];
        long long high = 0;

        for (int i = 0; i < nums.size(); i++) {
            low = max(low, (long long)nums[i]);
            high += nums[i];
        }

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            int subarrays = countSubarrays(nums, mid);

            if (subarrays <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};