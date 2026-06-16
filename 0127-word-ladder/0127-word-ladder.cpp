class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]!=beginWord){
                st.insert(wordList[i]);
            }
        }
        queue<string>q;
        int level=1;
        if(!st.count(endWord)) return 0;
        q.push(beginWord);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string curr=q.front();
                q.pop();
                if(curr==endWord) return level;
                for(int i=0;i<curr.size();i++){
                    char c=curr[i];
                    for(int j=97;j<=122;j++){
                      if(curr[i]==j) continue;
                      curr[i]=j;
                      if(st.count(curr)){
                        q.push(curr);
                        st.erase(curr);
                      }
                    }
                    curr[i]=c;
                }
            }
            level++;
        }
        return 0;
    }
};