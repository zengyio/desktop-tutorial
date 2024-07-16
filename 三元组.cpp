#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        int n = nums.size();
        int right = n - 1;
        int left = 0,max,min;
        if (n > 1) {
            max = nums[0] + nums[1];//-5
            min = nums[n - 1] + nums[n - 2];//3
            cout<<"min="<<min<<endl;
             if(max>0||min<0){
            	return ans;
			}
            //while(-max<nums[right]){right--;}
        }
        for (int i = left; i<n; ++i) {
            int x = nums[i];
            printf("1");
            if(x<-min){
            			cout<<x<< -min<<endl;
            	continue;
			}
            if(x>0) {

		break;	}
            if (i && x == nums[i - 1]) continue; 
            int j = i+1, k = right;
            while (j < k && k > 0) {
                int s = x+nums[j] + nums[k];
                if (s > 0) --k;
                else if (s < 0) ++j;
                else {
                	ans.push_back({x, nums[j], nums[k]});	
                    for (++j; j < k && nums[j] == nums[j - 1]; ++j); 
                    for (--k; k > j && nums[k] == nums[k + 1]; --k); 
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    int numsSize = nums.size();
    int returnSize;
    int *returnColumnSizes;
     vector<vector<int> > result = Solution().threeSum(nums);
    // 打印结果
    printf("找到的三元组个数: %d\n", result.size());
    for (int i = 0; i < result.size(); i++) {
        printf("三元组 %d: %d, %d, %d\n", i + 1, result[i][0], result[i][1], result[i][2]);
    }
    return 0;
}
