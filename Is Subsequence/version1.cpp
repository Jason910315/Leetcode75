//Time complexity:O(n)
//Sqace complexity:O(1)

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sub = 0,i;
        if(s.length()==0 && t.length()==0){
            return true;
        }
        for(i = 0;i < t.length();i++){
            if(s[sub]==t[i]){
                sub++;
            }
            if(sub==s.length()){
                return true;
            }
        }
        return false;  
    }
};

int main(){
    string s ="abc";
    string t = "abedjced";
    Solution ex;
    bool result = ex.isSubsequence(s,t);
    if(result==0){
        cout<<"false";
    }
    else{
        cout<<"True";
    }
}