class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double windowsum = 0;
        for(int i=0; i<k; i++){
            windowsum += nums[i];
        }

        double maxsum = windowsum;

        for(int right=k; right<n; right++){
             windowsum += nums[right] - nums[right -k];
             maxsum = max(maxsum , windowsum);
        }
        return maxsum/k;
    }
};