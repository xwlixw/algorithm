class Solution {
public:
   vector<string> addOperators(string num, int target) {
      vector<string> res;
      if (num.empty()) return res;
      helper(res, "", num, 0, 0, target, 0);
      return res;
   }
private:
   void helper(vector<string> &res, string line, const string &num, int pos, long long val, const int target, long long pre){
      if (pos >= num.length()){
         if (val==target) res.push_back(line);
         return;
      }

      for (int i = pos; i < num.length(); ++i){
         if (pos != i && num[i] == '0') break;
         string curstr(num.substr(pos, i - pos + 1));
         long long cur(stol(curstr));
         if (pos == 0) helper(res, curstr, num, i+1, cur, target, cur);
         else{
            helper(res, line+"+"+curstr, num, i+1, val+cur, target, cur);
            helper(res, line+"-"+curstr, num, i+1, val-cur, target, -cur);
            helper(res, line+"*"+curstr, num, i+1, val-pre+pre*cur, target, pre*cur);
         }
      }
   }
};
