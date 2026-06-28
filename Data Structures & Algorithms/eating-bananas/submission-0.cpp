class Solution {
public:
    bool checkspeed(int speed,int k, vector<int>& piles){
        int sum=0;
        long long count=0;
        for(int i=0;i<piles.size();i++){
            count+=ceil((double)piles[i]/speed);
        }
        if(count<=k){
            return true;
        }else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
          int low=1;
          int high=*max_element(piles.begin(),piles.end());
          int ans=high;
          while(low<=high){
            int mid=low+(high-low)/2;
            if(checkspeed(mid,h,piles)){
                ans=mid;
                high=mid-1;
               
            }else{
                low=mid+1;
            }
          }
          return ans;
    }
};
