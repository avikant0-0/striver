#include<bits/stdc++.h>
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;

        while(i < version1.size() || j < version2.size()){
            string t1 = "";
            int v1,v2;
            while(i < version1.size() && version1[i] != '.') t1.push_back(version1[i++]);
            v1 = t1 != "" ?  stoi(t1) : 0 ;
            ++i;

            t1 = "";
            while(j < version2.size() &&version2[j] != '.') t1.push_back(version2[j++]);
            v2 = t1 != "" ?  stoi(t1) : 0 ;
            ++j;

            if(v1 < v2) return -1;
            else if(v1 > v2) return 1;
        }

        return 0;
    }
};