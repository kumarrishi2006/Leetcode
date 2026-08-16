class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>Firstindex;
        Firstindex[0] = -1;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int r = sum % k;
        
        if(Firstindex.count(r)){
            
                if(i - Firstindex[r] >= 2)
                return true;
            }
            else{
                Firstindex[r] = i;
            }


        }
        return false;
    }
};