class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char task:tasks){
            freq[task]++;
        }
        priority_queue<int> pq;
        for(auto &[task,fre]:freq){
            pq.push(fre);
        }
        int time=0;
        queue<pair<int,int>> cooldown;
        while(!pq.empty()||!cooldown.empty()){
            time++;
            if(!cooldown.empty()&& cooldown.front().second<=time){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
            if(!pq.empty()){
                int cnt=pq.top();
                pq.pop();
                cnt--;
                if(cnt>0){
                    cooldown.push({cnt, time+n+1});
                }
            }
        }
        return time;
    }
};
