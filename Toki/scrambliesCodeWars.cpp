#include "bits/stdc++.h"

using namespace std;

bool scramble(const std::string& s1, const std::string& s2){
    string s1Copy = s1;
    string s2Copy = s2;
    sort(s1Copy.begin(), s1Copy.end());
    sort(s2Copy.begin(), s2Copy.end());
    int i = 0;
    int j = 0;
    while(i < s1Copy.length() && j < s2Copy.length()){
        if(s1Copy[i] == s2Copy[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(j == s2Copy.length()){
        return true;
    }
    return false;
}


int main(){
    cout << scramble("rkqodlw", "world") << endl;
    cout << scramble("cedewaraaossoqqyt", "codewars") << endl;
    cout << scramble("katas", "steak") << endl;
    cout << scramble("scriptjava", "javascript") << endl;
    cout << scramble("scriptingjava", "javascript") << endl;
    cout << scramble("scriptsjava", "javascripts") << endl;
    cout << scramble("jscripts", "javascript") << endl;
    cout << scramble("aabbcamaomsccdd", "commas") << endl;
    cout << scramble("commas", "commas") << endl;
    cout << scramble("sammoc", "commas") << endl;
    return 0;
}