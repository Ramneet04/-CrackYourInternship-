71 -> word ladder 

Solution :

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord); //as starting it so no point of visited again and agian will make diff in answer
        
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord)return steps;
            
            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,steps+1});
                    }
                    }
                word[i]=original;
            }
        }
        return 0;
    }
};
