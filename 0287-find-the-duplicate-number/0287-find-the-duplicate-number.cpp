class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        //Move once first 
        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

            // entrance the arrau
            slow = 0;

            while (slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }
        
        return slow;
    }
};