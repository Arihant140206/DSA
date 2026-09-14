class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

for (char c : s) {

    // Opening bracket → PUSH
    if (c == '(' || c == '[' || c == '{') {
        st.push(c);
    }

    // Closing bracket
    else {

        // Nothing to match
        if (st.empty())
            return false;

        // Check matching pair
        if (c == ')' && st.top() != '(')
            return false;

        if (c == ']' && st.top() != '[')
            return false;

        if (c == '}' && st.top() != '{')
            return false;

        // Match found → remove opening bracket
        st.pop();
    }
}

// Everything must be matched
return st.empty();
    }
};