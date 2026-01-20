class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int siz = a.size();
        vector<int> neg;
        vector<int> pos;

        // split into neg and pos
        for (int i = 0; i < siz; i++) {
            if (a[i] < 0)
                neg.push_back(a[i]);
            else
                pos.push_back(a[i]);
        }

        // case 1: all positive
        if (neg.size() == 0) {
            for (int i = 0; i < pos.size(); i++) {
                pos[i] = pos[i] * pos[i];
            }
            return pos;
        }

        // case 2: all negative
        if (pos.size() == 0) {
            for (int i = 0; i < neg.size(); i++) {
                neg[i] = neg[i] * neg[i];
            }
            reverse(neg.begin(), neg.end());
            return neg;
        }

        // square negatives
        for (int i = 0; i < neg.size(); i++) {
            neg[i] = neg[i] * neg[i];
        }
        reverse(neg.begin(), neg.end());

        // square positives
        for (int i = 0; i < pos.size(); i++) {
            pos[i] = pos[i] * pos[i];
        }

        // merge two sorted arrays
        int i = 0, j = 0, id = 0;
        int n = neg.size(), m = pos.size();
        vector<int> res(n + m);

        while (i < n && j < m) {
            if (neg[i] < pos[j]) {
                res[id] = neg[i];
                id++;
                i++;
            } else {
                res[id] = pos[j];
                id++;
                j++;
            }
        }

        while (i < n) {
            res[id] = neg[i];
            id++;
            i++;
        }

        while (j < m) {
            res[id] = pos[j];
            id++;
            j++;
        }

        return res;
    }
};
