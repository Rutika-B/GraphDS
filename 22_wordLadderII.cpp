https://leetcode.com/problems/word-ladder-ii/description/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      queue<vector<string>>q;
      unordered_set<string>s(wordList.begin(),wordList.end());
      q.push({beginWord});
      vector<string>used={beginWord};
      int level=0;
      vector<vector<string>>ans;
      while(!q.empty())
      {
        vector<string>dum=q.front();
        q.pop();
        if(dum.size()>level)
        {
          level++;
          for(auto it:used)
          {
            s.erase(it);
          }
          used.clear();
        }
        string str=dum.back();
        if(str==endWord)
        {
          if(ans.size()==0)
          {
            ans.push_back(dum);
          }
          else if(ans[0].size()==dum.size())
          {
            ans.push_back(dum);
          }
        }
        for(int i=0;i<str.size();i++)
          {
            char org=str[i];
            for(char ch='a';ch<='z';ch++)
            {
              str[i]=ch;
              if(s.find(str)!=s.end())
              {
                dum.push_back(str);
                q.push(dum);
                used.push_back(str);
                dum.pop_back();
              }
            }
            str[i]=org;
          }
      }
      return ans;
    }
};