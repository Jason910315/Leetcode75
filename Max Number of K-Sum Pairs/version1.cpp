//Time complexity:O(nlogn)+O(n) = O(nlogn)
//Sqpce complexity:O(1)

//使用sort()先排序，注意排序演算法最快可達O(nlogn)，像是heapsort、quicksort等，
//第22行，因為已由小到大，若兩者相加<k，代表若再移動右方(會越變越小)一定不會得正確答案，故要移動左邊使其越來越大才可能等於k
#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());  //先採升序排序，花O(nlogn)
        int i{0};
        int j = nums.size()-1;
        int count = 0;
        while(i < j){
            int res = nums[i]+nums[j];
            if(res == k){ //若兩元素相加等於k
                count++;
                i++;  //陣列左邊往右移
                j--;  //陣列右邊往左移
            }
            else if(res < k){   //兩者相加<k
                i++;  
            }
            else j--;
        }
        return count;
    }
};

int main(){
    vector<int> nums = {4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4};  
    int k = 2;
    Solution s;
    cout<<s.maxOperations(nums,k);
}