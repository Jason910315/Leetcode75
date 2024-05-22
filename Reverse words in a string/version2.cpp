#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int i = 0,j;
        int n = s.length();
        string ans = "";
        while(i < n){
            string st = "";  //st每次都只存一個字詞，故while loop一開始都會重置
            while(i < n && s[i]==' '){  //先讓指標移動到第一個不是空格的元素上
                i++;
            }
            j = i;
            while(j < n && s[j]!=' '){    //以j控制單字將一個單詞加到st上
                st += s[j]; 
                j++;
            }
            if(st.length() > 0){
                if(ans.length()==0){
                    ans += st;
                }
                else{
                    ans = st + " " + ans;  //將st不斷加到前一個ans前面，讓整個字串的單字能相反過來
                }
            }
            i = j + 1;  //i移動到j 之下一個表是一個字詞以新增完畢
        }
        return ans;
    }
};
int main(){
    Solution s;
    string str = "leet code  is";
    string result = s.reverseWords(str);
    cout<<result;
}