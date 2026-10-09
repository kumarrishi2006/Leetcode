class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int curr = nums[i % n];

            while (!st.empty() && st.top() <= curr)
            {
                st.pop();
            }

            // only fill the answer during the first pass (real indices 0..n-1)
            if (i < n && !st.empty())
            {
                res[i] = st.top();
            }

            st.push(curr);
        }
        return res;
    }
};