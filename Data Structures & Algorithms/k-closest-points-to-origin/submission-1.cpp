class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<points.size();i++){
            pq.push({(points[i][0]*points[i][0])+(points[i][1]*points[i][1]),i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        vector<int> cur;

        while(k--){
            int x=points[pq.top().second][0];
            int y=points[pq.top().second][1];
            cur.push_back(x);
            cur.push_back(y);
            ans.push_back(cur);
            pq.pop();
            cur.clear();
        }
        return ans;
    }
};
