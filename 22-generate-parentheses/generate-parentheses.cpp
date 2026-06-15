class Solution {
public:

    // Recursive function
    // open  = number of '(' used till now
    // close = number of ')' used till now
    // n     = total pairs required
    // temp  = current string being built
    // res   = stores all valid answers
    void fun(int open, int close, int n, string &temp, vector<string> &res)
    {
        // BASE CASE:
        // If we have used n opening and n closing brackets,
        // then we have formed a valid parenthesis string.
        if(open == n && close == n)
        {
            res.push_back(temp);
            return;
        }

        // ---------------- First Choice ----------------
        // We can add '(' only if we still have some left.
        if(open < n)
        {
            temp.push_back('(');          // choose '('

            fun(open + 1, close, n, temp, res); // recurse

            temp.pop_back();              // backtrack
        }

        // ---------------- Second Choice ----------------
        // We can add ')' only if number of ')' used
        // is less than number of '(' used.
        // Otherwise expression becomes invalid.
        if(close < open)
        {
            temp.push_back(')');          // choose ')'

            fun(open, close + 1, n, temp, res); // recurse

            temp.pop_back();              // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> res;
        string temp = "";

        fun(0, 0, n, temp, res);

        return res;
    }
};