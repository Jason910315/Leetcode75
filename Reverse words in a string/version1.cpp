//Time complexity:O(n),traverse entire string s,which length is n
//Space complexity:O(n),we create a vector string to store the input string 
//解題思路:利用 vector<string>的特性儲存輸入字串，因為push_back都是新增一獨立的字串元素，故在第一個for loop結束後雖然
//整個字串都是相連無空格，但各字詞都代表一個vector位置，ex:leetcode，leet為 s[0]，code為 s[1]，後續即可使用for從尾遞迴到頭
//將字串單字一一顛倒

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string> str;
        string word = "";  //word存放每一個獨立單字
        for(char ch:s){  //遞迴整個字串s
            if(ch == ' '){  //if下個元素是空格' '
                if(word!=""){  //檢查word是否為空，若為空表示頭部有空格或中間字詞間有連續兩空格以上
                    str.push_back(word);  //每次push_back都是增加一格元素的位置
                    word.clear();
                }
            }
            else{
                word += ch;  //若沒有空格則不斷增加單字到word，每次的word皆為獨自字詞
            }
        }       //結束後會變成每個字詞相連，ex:leet  code -> leetcode
        if(word!=""){
            str.push_back(word);
        }   //若最後無空格會有一單詞未加入str

        string ans = "";
        for(int i = str.size()-1;i >= 0;i--){   //str.size()表示共有幾個獨立字詞
            ans += str[i];
            ans += ' ';
        }
        ans.pop_back();  //清除最後的空格 
        return ans;
    }
};
int main(){
    Solution s;
    string str = " leet code  is my   ";
    string result = s.reverseWords(str);
    cout<<result<<"\n";
}