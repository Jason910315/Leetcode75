//Time complexity:O(n),we use for loop to traverse the flowerbed,where n equals the size of flowerbed
//Space commplexity:O(1)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0;i < flowerbed.size();i++){
            bool left = (i==0 || flowerbed[i-1]==0);
            bool right = (i==flowerbed.size()-1 || flowerbed[i+1]==0);
            if(left && right && flowerbed[i]==0){
                n--;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};

int main(){
    vector<int> flowers = {1,0,0,0,0,1};
    int n = 1;
    Solution s;
    bool result = s.canPlaceFlowers(flowers,n);
    cout<<result;
}

//解題思路:
//1. 使用兩個bool變數儲存左右之狀態，i表示現在位置，從頭遍歷並記錄該位置的左邊及右邊是否為空(可放置花) 
//2. left = (i==0 || flowerbed[i-1]==0)，當i==0表示現在在vector的第一個位置，此位置的左邊已經out of bound，表示unplanted，
//   left直接設true，right部分同理
//3. 最後當i位置是unplanted且左右bool皆true(代表都是unplanted)，i可以放置花，而放置完後要將flowerbed[i]設為1，
//   以便下一個位置判斷
