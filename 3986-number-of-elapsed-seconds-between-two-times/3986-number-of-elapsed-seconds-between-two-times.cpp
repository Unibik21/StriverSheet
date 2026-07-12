class Solution {
public:
    int secondsBetweenTimes(string s, string e) {
        int sec1 = (s[6]-'0')*10+(s[7]-'0');
        int sec2 = (e[6]-'0')*10+(e[7]-'0');

        int min1 = (s[3]-'0')*10+(s[4]-'0');
        int min2 = (e[3]-'0')*10+(e[4]-'0');

        int hr1 = (s[0]-'0')*10+(s[1]-'0');
        int hr2 = (e[0]-'0')*10+(e[1]-'0');

        return (hr2*60*60+min2*60+sec2)-(hr1*60*60+min1*60+sec1);


    }   
};