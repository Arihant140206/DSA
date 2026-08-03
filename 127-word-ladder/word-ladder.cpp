class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Store all words in a hash set for O(1) lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Agar endWord hi dictionary me nahi hai,
        // to kabhi bhi waha nahi pahunch sakte.
        if (st.find(endWord) == st.end())
            return 0;

        // BFS Queue
        queue<string> q;

        // Source word push karo
        q.push(beginWord);

        // Begin word ko visited maan lo
        st.erase(beginWord);

        // Level = Number of words in path
        int level = 1;

        while (!q.empty()) {

            // Current level me jitne words hain
            int size = q.size();

            while (size--) {

                string word = q.front();
                q.pop();

                // Destination mil gaya
                if (word == endWord)
                    return level;

                // Word ke har character ko ek-ek karke change karenge
                for (int i = 0; i < word.length(); i++) {

                    // Original character save kar lo
                    char original = word[i];

                    // a se z tak try karo
                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;

                        // Agar ye word dictionary me hai
                        if (st.find(word) != st.end()) {

                            // Queue me daal do
                            q.push(word);

                            // Visited mark kar do
                            st.erase(word);
                        }
                    }

                    // Original character wapas rakh do
                    word[i] = original;
                }
            }

            // Ek level complete ho gaya
            level++;
        }

        // Agar destination nahi mila
        return 0;
    }
};