class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);

        // Step 1a: build leftMax — walk left to right, keep running max
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        // Step 1b: build rightMax — walk right to left, keep running max
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        // Step 2 + 3: water[i] = min(leftMax[i], rightMax[i]) - height[i], then sum
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int water = min(leftMax[i], rightMax[i]) - height[i];
            sum += water;
        }

        return sum;
    }
};