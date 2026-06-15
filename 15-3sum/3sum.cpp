class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {

        int n = a.size();
        vector<vector<int>> ans;

        sort(a.begin(), a.end());

        for(int i = 0; i < n - 2; i++) {

            if(i > 0 && a[i] == a[i-1])
                continue;

            int l = i + 1;
            int r = n - 1;
            int sum = -a[i];

            while(l < r) {

                int s = a[l] + a[r];

                if(s == sum) {

                    ans.push_back({a[i], a[l], a[r]});

                    l++;
                    r--;

                    while(l < r && a[l] == a[l-1])
                        l++;

                    while(l < r && a[r] == a[r+1])
                        r--;
                }

                else if(s < sum)
                    l++;

                else
                    r--;
            }
        }

        return ans;
    }
};