class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Count frequency
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a')
                lower[s[i] - 'a']++;
            else
                upper[s[i] - 'A']++;
        }

        int count = 0;
        bool odd = false;

        // Process lowercase
        for (int i = 0; i < 26; i++) {
            count += (lower[i] / 2) * 2;  // take pairs
            if (lower[i] % 2 == 1) odd = true;
        }

        // Process uppercase
        for (int i = 0; i < 26; i++) {
            count += (upper[i] / 2) * 2;
            if (upper[i] % 2 == 1) odd = true;
        }

        // If there's at least one odd character, we can place it in the center
        if (odd) count += 1;

        return count;
    }
};
