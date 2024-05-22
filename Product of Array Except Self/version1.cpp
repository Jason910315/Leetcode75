//Time complexity:O(n),we use three for loop and each oh them traverse the nums.size()
//Space complexity:O(n),leftProduct and rightProduct space
//解題思路:使用 Dynamic programming，用兩array儲存左右元素乘積，假設想找第i元素之左右乘積，則用此兩array儲存prefix and suffix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i,n = nums.size();
        vector<int> ans(n);
        vector<int> leftProduct(n);
        vector<int> rightProduct(n);
        leftProduct[0] = 1;
        for(i = 1;i < n;i++){
            leftProduct[i] = leftProduct[i-1] * nums[i-1]; 
        }  //leftProduct[i]代表nums[i]左邊的元素乘積總和
        rightProduct[n-1] = 1;
        for(i = n-2;i >= 0;i--){
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
        }  //rightProduct[i]代表nums[i]右邊的元素乘積總和
        for(i = 0;i < n;i++){
            ans[i] = leftProduct[i] * rightProduct[i];
        }  //故leftProduct[i] * rightProduct[i]即為除第i元素外其餘元素乘積
        return ans;   
    }
};
int main()
{   
    Solution s;
    vector<int> nums = {1,2,4,8};
    vector<int> ans = s.productExceptSelf(nums);
    for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<"  ";
    }
}
