class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        while(!q.empty()){

            auto [word,t] = q.front();
            q.pop();

            if(word==endWord)return t;

            for(int i=0;i<word.size();i++){
                char act = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.count(word)){
                        q.push({word,t+1});
                        s.erase(word);
                    }
                }
                word[i]=act;
            }


        }

        return 0;
    }
};