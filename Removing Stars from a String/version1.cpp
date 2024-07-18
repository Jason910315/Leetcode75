//Time complexity:O(n)
//Space complexity:O(n-m),n為原字串長度，m為去除'*'及其左邊元素後的字串長度，我們新建一個string ans來儲存最後結果

#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
    string removeStars(string s){
        int count = 0;
        for(int i = s.size();i>=0;i--){ //從尾部遍歷
            if(s[i]=='*') count++;      //紀錄遇到的'*'個數
            else{                       //若字元不是 '*'
                if(count > 0){
                    s[i] = '*';         //根據前面遇到的'*'個數將後幾個字元變成'*'
                    count--;
                }
            }
        }
        string ans;
        for(int i = 0;i<s.size();i++){
            if(s[i]!='*'){              //將'*'去除即是答案
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution s; 
    string str = "abb*cdfg*****x*";
    string ans = s.removeStars(str);
    cout<<ans;
}