class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for(char i : tasks){
            freq[i]++;
        }

        priority_queue<int>maxHeap;

        for(auto i : freq){
            maxHeap.push(i.second);
        }

        queue<pair<int, int>> lq;

        int t = 0;

        while(!maxHeap.empty() || !lq.empty()){
            t++;

            if( !lq.empty() && lq.front().second == t){
                maxHeap.push(lq.front().first);
                lq.pop();
            }

            if(!maxHeap.empty()){
                int count = maxHeap.top();
                maxHeap.pop();
                count--;
                if(count > 0){
                    lq.push({count, t+n+1});
                }
            }
        } 

        return t;
        
    }
};
