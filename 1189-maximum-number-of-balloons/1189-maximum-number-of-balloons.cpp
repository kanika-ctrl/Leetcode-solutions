class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mymap;
        for(auto it:text){
            if(it=='b'||it=='a'||it=='l'||it=='o'||it=='n'){
                mymap[it]++;
            }
        }
        if(mymap.size()!=5){
            return 0;
        }
        int minfreq=INT_MAX;
            for(auto it:mymap){
              char key=it.first;
              int freq=it.second;
              if(key=='l'||key=='o'){
                freq=freq/2;
              }
              if(minfreq>=freq){
                minfreq=freq;
              }
            }
        
        return minfreq;
    }
};
