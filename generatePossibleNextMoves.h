class Solution {
public:
   vector<string> generatePossibleNextMoves(string s) {
      vector<string> res;
      if (s.length() < 2) return res;
      for (int i = 1; i < s.length(); ++i){
         if (s[i] == '+' && s[i - 1] == '+'){
            s[i - 1] = s[i] = '-';
            res.push_back(s);
            s[i - 1] = s[i] = '+';
         }
      }
      return res;
   }

   bool firstPlayWinning(string s) {
      for (int i = 1; i < s.length(); ++i){
         if (s[i] == '+' && s[i - 1] == '+'){
            s[i - 1] = s[i] = '-';
            bool secondWin(firstPlayWinning(s));
            s[i - 1] = s[i] = '+';
            if (!secondWin) return true;
         }
      }
      return false;
   }
};
