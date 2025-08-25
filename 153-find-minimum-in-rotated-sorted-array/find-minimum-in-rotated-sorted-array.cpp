class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] <= arr[end]) {
                // Minimum is in left part (including mid)
                end = mid;
            } else {
                // Minimum is in right part
                start = mid + 1;
            }
        }
        return arr[start]; // or arr[end], both point to min
    }
};
