class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n ,1);

        int arrLeft = 1;
        for(int i =0; i<n; i++){
            ans[i] = arrLeft ;
            arrLeft = arrLeft * nums[i];
        }
        int arrRight = 1;
        for(int i=n-1; i>=0; i--){
            ans[i] = arrRight * ans[i];
            arrRight = arrRight * nums[i];
        }
        return ans;
    }
};