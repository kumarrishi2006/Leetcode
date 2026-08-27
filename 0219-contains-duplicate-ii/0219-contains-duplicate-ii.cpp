class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_set<int> window;

        for (int right = 0; right < nums.size(); right++) {

            // Keep the window size at most k
            if (right > k) {
                window.erase(nums[right - k - 1]);
            }

            // If the current number already exists in the window
            if (window.count(nums[right])) {
                return true;
            }

            // Add current number to the window
            window.insert(nums[right]);
        }

        return false;
    }
};