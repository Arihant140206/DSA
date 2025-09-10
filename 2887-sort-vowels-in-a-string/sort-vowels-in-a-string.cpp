class Solution {
public:
    string sortVowels(string s) {
        string vowels = "AEIOUaeiou";
        vector<char> v;

        // Step 1: collect all vowels
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                v.push_back(c);
            }
        }

        // Step 2: sort vowels in ASCII order
        sort(v.begin(), v.end());

        // Step 3: replace vowels back into string
        int idx = 0;
        for (char &c : s) {
            if (vowels.find(c) != string::npos) {
                c = v[idx++];
            }
        }

        return s;
    }
};

