//Time complexity:O(n)
//Space complexity:O(1),result為輸出陣列不列入space且只使用些許變數，與version1雷同痛樣使用prefix、postfix的概念，只是都在
//原輸入陣列上操作因此可使空間複雜度維持在O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int i;
        vector<int> result(n);
        result[0] = 1;
        for(i = 1;i < n;i++){
            result[i] = result[i-1] * nums[i-1];
        }
        int right = 1;
        for(i = n-1;i >= 0 ;i--){
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};
int main()
{   
    Solution s;
    vector<int> nums = {2,1,4,2,8};
    vector<int> ans = s.productExceptSelf(nums);
    for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<"  ";
    }
}
