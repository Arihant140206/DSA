class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;

        while (start < end) {   // we use < because eventually start==end will be peak
            int mid = start + (end - start) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // we are on the increasing side
                start = mid + 1;
            } else {
                // we are on the decreasing side OR at the peak
                end = mid;
            }
        }

        // at the end, start == end == peak index
        return start;
    }
};
