25 -> Longest Common Prefix

Solution :

class Solution {
public:
    
    class TrieNode{
        public:
        bool isEnd;
        int childcount;
        TrieNode*children[26];
        TrieNode(){
            this->isEnd=false;
            this->childcount=0;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
    };
    class Trie{
        public:
        TrieNode*root;
        Trie(){
            root=new TrieNode();
            return;
        }
        void insert(string word){
            TrieNode*curr=root;
            for(auto x:word){
                if(curr->children[x-'a']==NULL){
                    TrieNode*ptr=new TrieNode();
                    curr->children[x-'a']=ptr;
                    curr->childcount++;
                }
                curr=curr->children[x-'a'];
            }
            curr->isEnd=true;
        }
        string getans(string s){
            string ans="";
            TrieNode*curr=root;
            for(int i=0;i<s.length();i++){
                if(curr->childcount!=1||curr->isEnd==true){
                    break;
                }
                ans+=s[i];
                curr=curr->children[s[i]-'a'];
                }
        return ans;
        }
    };
    string longestCommonPrefix(vector<string>& strs) {
        Trie* newnode=new Trie();
        //ek bar construct kr diya ab uske function call krdiye.
        for(auto x:strs){
            newnode->insert(x);
        }
        return newnode->getans(strs[0]);
    }
};