//Time complexity:O(n),because we traverse whole array
//Spqce complexity:O(1),we manipulate the process inside the input vector

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        int ansIndex = 0; //此為返回值，即修改後壓縮陣列長度
        while(i < chars.size()){
            while(j < chars.size() && chars[i]==chars[j]){
                j++; //到此處算出第一個與前方不同的元素
            }
            chars[ansIndex++] = chars[i]; //修改陣列
            int count = j-i; //某一元素的重複個數
            if(count > 1){  ////元素只有1個的話不用修改陣列為其個數
                string length = to_string(count);
                for(char ch:length){
                    chars[ansIndex++] = ch; //若個數超過10位數則會佔陣列兩個位置，故用for loop
                }
            }
        i = j;
        }
        return ansIndex;
    }
    
};


int main(){
    vector<char> flowers = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    Solution s;
    int result = s.compress(flowers);
    cout<<result;
}