/*
Time complexity:O(n)
Space complexity:O(n),字串t為返回值
用兩個stack來解，其中一個來儲存數字，紀錄該重複的倍數，另一個儲存字串，現在有四種case，
case1: 當遇到數字記錄下來(count)
case2: 當遇到字串紀錄，t+=c
case3: 當遇到'['，則將當前count 與t都push
case4: 當遇到']，則執行彈出，數字堆疊彈出代表要重複倍數，
用temp紀錄當前t，t則改為字串堆疊的top()，接者重複k次 t+=temp; 則下一次在']'要輸出時，temp就可以記錄此次的t以此繼續循環
最後返回t
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> str;
        int count = 0;
        string t = "";
        for(int c:s){
            if(c>='0' && c<='9'){
                count = count*10 + (c-'0');
            }
            else if(c=='['){
                num.push(count);
                count = 0;
                str.push(t);
                t = "";
            }
            else if(c==']'){
                int k = num.top();
                num.pop();
                string temp = t;
                t = str.top();
                str.pop();
                for(int i=0;i<k;i++){
                    t+=temp;
                }  
            }
            else{
                t+=c;
            }
        }
        return t;
    }
};

int main(){
    Solution s;
    string t = "3[2a[c]]";
    cout<<s.decodeString(t);
}






