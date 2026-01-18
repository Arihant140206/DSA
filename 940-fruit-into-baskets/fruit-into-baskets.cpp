class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //make and unordered map storing the frequency of elements 
        unordered_map<int,int>freq;
        int start=0,end=0,maxlen=0;
//hum pehle map me daalte jaayenge 
        for(int end=0;end<fruits.size();end++){
            freq[fruits[end]]++;
            //agar 2 types ke fruits se jyada ho jaaye toh hum left side se -- karte jaayenge 
            while(freq.size()>2){
                freq[fruits[start]]--;
                if(freq[fruits[start]]==0){
                    freq.erase(fruits[start]);
                }
                start++;
                
            }//imp!!!!!
            maxlen=max(maxlen,end-start+1);


        }return maxlen;
    }
};