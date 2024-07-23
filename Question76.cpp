76 ->  Furthest Building You Can Reach


Solution :
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int>pq;
        
        for (int i = 0; i < heights.size() - 1; i++) {
            if(heights[i+1]<=heights[i])continue;
            int diff = heights[i + 1] - heights[i];
            
            if(diff<=bricks){
                bricks-=diff;
                pq.push(diff);
            }
            else if(ladders>0){
                if(!pq.empty()){
                    if(diff<pq.top()){
                        bricks+=pq.top();
                        pq.pop();
                        bricks-=diff;
                        pq.push(diff);
                    }
                }
                ladders--;
            }
            else{
                return i;
            }
        }
        return heights.size()-1;
    }
};