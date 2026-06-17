class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int ptr1, ptr2;
        int sum=0;
      
        vector<int> ele;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                sum=nums[i]+nums[j];
                if(sum==target){
                    ptr1=i;
                    ptr2=j;
                    break;
                }
            }
        }
                     ele.push_back(ptr1);
                    ele.push_back(ptr2);
        return ele;
    }
       
};
