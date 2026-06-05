class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(char ch : s) {
            if(st.empty()) {
                st.push(ch);
            }
            else if(st.top() == ch) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }

        string res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};