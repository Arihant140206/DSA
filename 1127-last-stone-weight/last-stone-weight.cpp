class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i:stones)
        {
            pq.push(i);
        }
        while(pq.size()>1)
        {
            int curr1=pq.top();
            pq.pop();
            int curr2=pq.top();
            pq.pop();
            if(curr1==curr2||curr1>curr2)
            pq.push(curr1-curr2);
        }if(!pq.empty())
        return pq.top();
        return 0;
        }
    };