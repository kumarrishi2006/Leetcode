class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>st;
        vector<int>res = prices;

        for(int i=0; i<n; i++){

            while (!st.empty() && prices[st.top()] >= prices[i]){
                int prev = st.top();
                st.pop();
                res[prev] = prices[prev] - prices[i];
            }
            st.push(i);
        }
        return res;
 }
};