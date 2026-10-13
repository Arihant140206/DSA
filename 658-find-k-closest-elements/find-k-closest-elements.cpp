class cmp {
public:
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        if(a.first != b.first)
            return a.first < b.first;

        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
       for(int i=0;i<arr.size();i++)
       {
        int dist=abs(arr[i]-x);
        pair<int,int>curr={dist,arr[i]};
        if(pq.size()<k)
        {
            pq.push(curr);
            continue;
        }

        if(curr.first<pq.top().first|| (curr.first==pq.top().first&&curr.second<pq.top().second))
        {
            pq.pop();
            pq.push(curr);
        }
       } 
       vector<int>ans;
       while(!pq.empty())
       {
        ans.push_back(pq.top().second);
        pq.pop();
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};