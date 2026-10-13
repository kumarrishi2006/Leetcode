
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(string op : operations) {
            if(op == "C") {
                st.pop();
            }
            else if(op == "D") {
                st.push(2 * st.top());
            }
            else if(op == "+") {
                int a = st.top();
                st.pop();

                int b = st.top();

                st.push(a);
                st.push(a + b);
            }
            else {
                st.push(stoi(op));
            }
        }

        int total = 0;

        while(!st.empty()) {
            total += st.top();
            st.pop();
        }

        return total;
    }
};

