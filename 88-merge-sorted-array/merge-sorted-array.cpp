class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {

        int i = 0;
        int j = 0;
        int id = 0;

        vector<int> res(m + n);

        while (i < m && j < n) {
            if (a[i] < b[j]) {
                res[id] = a[i];
                id++;
                i++;
            } else {
                res[id] = b[j];
                id++;
                j++;
            }
        }

        while (j < n) {
            res[id] = b[j];
            id++;
            j++;
        }

        while (i < m) {
            res[id] = a[i];
            id++;
            i++;
        }

        // copy back to array a
        for (int k = 0; k < m + n; k++) {
            a[k] = res[k];
        }
    }
};
