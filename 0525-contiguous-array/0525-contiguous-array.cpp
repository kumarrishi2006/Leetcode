class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int> firstOccurrence;
        firstOccurrence[0] = -1;
        int sum =0;
        int
         maxLen = 0;

        for(int i=0; i<nums.size(); i++){

            sum+= (nums[i] ==0) ? -1 : 1;

             if(firstOccurrence.find(sum) != firstOccurrence.end()){

                maxLen = max(maxLen , i - firstOccurrence[sum]);
             }
             else {
                firstOccurrence[sum] = i;
             }
            
        }
        return maxLen;
    }
};