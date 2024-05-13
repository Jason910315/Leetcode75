//Time complexity:O(n)
//Space complexity:O(n)
#include <iostream>
#include <string>
using namespace std;

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2==str2 + str1){
            return str1.substr(0,gcd(str1.size(),str2.size()));
        }
        else{
            return "null";
        }
    }
};
int main(){
    string str1 = "ABC";
    string str2 = "ABCAB";
    Solution s;
    string result = s.gcdOfStrings(str1,str2);
    cout<<result;
}

//解題思維:要判斷兩字串是否有最大公因的字串如ABCABC、ABC有ABC此公因，則須滿足
//1. str1+str2==str2+str1，兩字串無論怎麼相加都必須相等，否則無gcd
//2. 若相等則取兩字串長度的公因數，如此才會有此公因數長度的子字串出現
//3. 最後取某一字串的substr(0,gcd)代表此字串的公因子字串，gcd即為長度
