class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

for (string token : tokens) {

    // NUMBER → push into stack
    if (token != "+" && token != "-" &&
        token != "*" && token != "/") {

        st.push(stoi(token));
    }

    // OPERATOR → take top 2 numbers
    else {

        int b = st.top();
        st.pop();

        int a = st.top();
        st.pop();

        int result;

        if (token == "+")
            result = a + b;
        else if (token == "-")
            result = a - b;
        else if (token == "*")
            result = a * b;
        else
            result = a / b;

        // Put result back
        st.push(result);
    }
}

return st.top();
    }
};