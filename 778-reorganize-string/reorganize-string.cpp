class Solution {
public:
    string reorganizeString(string s) {
        //hashmap banake frequency daalunga
        unordered_map<char,int>freq;
        for(auto ch:s){
            freq[ch]++;
        }
        //max heap banake fewq daalunga par ulta taaki pehle freq aaye
        priority_queue<pair<int,char>>pq;

        for(auto i:freq){
            pq.push({i.second,i.first});
        }
        //answer string
        string ans="";

        pair<int,char>prev={0,'#'};

        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int count=curr.first;
            char ch=curr.second;

            ans+=ch;
            count--;
            if(prev.first>0){
                pq.push(prev);
            }

            prev={count,ch};
        }
        if(ans.size()!=s.size())
        return "";
        return ans ;
    }
};