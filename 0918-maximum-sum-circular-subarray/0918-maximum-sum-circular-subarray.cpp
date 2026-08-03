class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        // Maximum subarray sum (Kadane's Algorithm)
        int currMax = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            currMax += nums[i];
            maxSum = max(maxSum, currMax);
            if (currMax < 0)
                currMax = 0;
            totalSum += nums[i];
        }

        // Minimum subarray sum (Kadane's Algorithm)
        int currMin = 0, minSum = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            currMin += nums[i];
            minSum = min(minSum, currMin);
            if (currMin > 0)
                currMin = 0;
        }

        int circularSum = totalSum - minSum;

        // If all elements are negative
        if (circularSum == 0)
            return maxSum;

        return max(maxSum, circularSum);
    }
};