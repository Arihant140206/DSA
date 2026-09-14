class Solution {
public:
    string decodeString(string s) {
        

    stack<int> numberStack;
    stack<string> stringStack;

    int num = 0;
    string curr = "";

    for (char c : s) {

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        else if (c == '[') {
            numberStack.push(num);
            stringStack.push(curr);

            num = 0;
            curr = "";
        }

        else if (isalpha(c)) {
            curr += c;
        }

        else if (c == ']') {

            int repeat = numberStack.top();
            numberStack.pop();

            string previous = stringStack.top();
            stringStack.pop();

            string temp = "";

            for (int i = 0; i < repeat; i++) {
                temp += curr;
            }

            curr = previous + temp;
        }
    }

    return curr;

    }
};