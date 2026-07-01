// changes from elements wala question
// CHANGE 1:
// unordered_map<int,int>  -> unordered_map<string,int>
// because now we are counting frequencies of words instead of numbers

// CHANGE 2:
// pair<int,int> -> pair<int,string>
// heap now stores {frequency, word} instead of {frequency, element}

// CHANGE 3:
// vector<int> -> vector<string>
// because final answer contains words, not integers

// CHANGE 4 (MOST IMPORTANT):
// For same frequency, lexicographically smaller word should come first.
// Therefore in the min heap, lexicographically larger word is treated
// as the weaker candidate and kept at the top for possible removal.
//lexiographically matlab sirf first letter compare hota hai ki pehle kon aaya tha alphabet me 
class cmp {
public:
    bool operator()(pair<int,string>& a, pair<int,string>& b) {

        // smaller frequency should stay at top
        if(a.first != b.first)
            return a.first > b.first;


        return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> freq;

        for(string word : words)
            freq[word]++;

        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            cmp
        > pq;

        for(auto it : freq) {

            pair<int,string> curr = {it.second, it.first};

            if(pq.size() < k) {
                pq.push(curr);
                continue;
            }

            // if current candidate is better than heap top,
            // replace heap top

            if(curr.first > pq.top().first ||
              (curr.first == pq.top().first &&
               curr.second < pq.top().second))
            {
                pq.pop();
                pq.push(curr);
            }
        }

        vector<string> res;

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};