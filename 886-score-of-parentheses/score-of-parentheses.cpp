// RULES:
// 1. "()" = 1
// 2. AB = A + B   (concatenation → add scores)
// 3. (A) = 2 * A  (wrapping → double the score)


// INTUITION:
// - We track "depth" = number of currently open '('
// - Every time we see a primitive pair "()" → we add value
// - Value of "()" depends on depth:
//      contribution = 2^(current depth after closing)


// WHY?
// - Each enclosing '(' doubles the score
// - So deeper pairs contribute more


// DRY RUN: s = "(()(()))"
// i   char   depth   action                     score
// ----------------------------------------------------
// 0   (      1       open                       0
// 1   (      2       open                       0
// 2   )      1       "()" → add 2^1 = 2         2
// 3   (      2       open                       2
// 4   (      3       open                       2
// 5   )      2       "()" → add 2^2 = 4         6
// 6   )      1       no add                     6
// 7   )      0       no add                     6

//1 << depth   ==   2^depth

// FINAL ANSWER = 6

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                depth++;  // going deeper
            } 
            else {
                depth--;  // coming out of one level

                // check for primitive pair "()"
                if(s[i-1] == '(') {
                    score += (1 << depth);  // 2^depth
                }
            }
        }
        return score;
    }
};