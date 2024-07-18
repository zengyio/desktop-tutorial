class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=nums.size();
        int left=0,right=0,result=0,bestresult=len+1,sum=0;
        while(right<len){
            sum+=nums[right];
            while(sum>=target){
                result=right-left+1;
                if(result<bestresult){
                    bestresult=result; }   
                sum-=nums[left++];
            }
            right++;
        }
        return bestresult==len+1?0:bestresult;
        }
};
