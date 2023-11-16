https://leetcode.com/problems/word-ladder/description/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;        
        q.push({beginWord,1});
        s.erase(beginWord);
        // Time COmplexity--O(N* sizeof(string)*26)
        while(!q.empty())
        {
          string str=q.front().first;
          int steps=q.front().second;
          q.pop();
          if(str==endWord) return steps;
          for(int i=0;i<str.size();i++)
          {
            char org=str[i];
            for(char ch='a';ch<='z';ch++)
            {
              str[i]=ch;
              if(s.find(str)!=s.end())
              {
                q.push({str,steps+1});
                s.erase(str);
              }
            }
            str[i]=org;
          }
        }
        return 0;
    }
};