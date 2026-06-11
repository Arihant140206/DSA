class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //make hashmap and store elemenets
        unordered_map<char,int>freq;
        for(auto ch:tasks){
            freq[ch]++;
        }
        //making max heap and storing freq od elemnets
        priority_queue<int>pq;
        for(auto it:freq){
            pq.push(it.second);
        }
        //making queue for storing pair of freq and cooldown
        queue<pair<int,int>>cooldown;
        
        int time=0;

        while(!pq.empty()||!cooldown.empty()){
            time++;
            if(!pq.empty()){
                int currFreq=pq.top();
                pq.pop();

                currFreq--;
                if(currFreq>0){
                    cooldown.push({currFreq,time+n});
                }
            }

            if(!cooldown.empty()&&cooldown.front().second==time){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }return time;
    }
};