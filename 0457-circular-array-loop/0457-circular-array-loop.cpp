class Solution {
public:

    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();

        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (nums[i] == 0)
                continue;

            int slow = i;
            int fast = i;

            while (
                nums[i] * nums[slow] > 0 &&
                nums[i] * nums[fast] > 0 &&
                nums[i] * nums[nextIndex(nums, fast)] > 0
            ) {

                slow = nextIndex(nums, slow);

                fast = nextIndex(nums, fast);
                fast = nextIndex(nums, fast);

                if (slow == fast) {

                    // single element cycle
                    if (slow == nextIndex(nums, slow))
                        break;

                    return true;
                }
            }

            // Mark this path as useless
            int curr = i;

            while (nums[i] * nums[curr] > 0) {

                int next = nextIndex(nums, curr);

                nums[curr] = 0;

                curr = next;
            }
        }

        return false;
    }
};