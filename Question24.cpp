24 -> Find the Index of the First Occurrence in a String

Solution :

class Solution {
public:
    int strStr(string haystack, string needle) {
     int ans=-1;
        ans=haystack.find(needle);  //strinh bhej do  s.find()
        return ans; //bs i did it.
    }
};