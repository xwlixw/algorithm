class Solution_rearrangeString {
public:
   struct freq{
      char ch;
      int count;
      freq(char ch_, int count_) :ch(ch_), count(count_){}
      bool operator<(const freq &rhs) const{
         return count < rhs.count;
      }
   };
   string rearrangeString(string str, int k) {
      if (k<=1) return str;
      string res(str.length(), ' ');
      unordered_map<char, int> hist;
      for (auto x : str) ++hist[x];
      priority_queue<freq, vector<freq>, less<freq>> pq;

      for (auto x : hist){
         pq.push(freq(x.first, x.second));
      }

      int i(0);
      while (!pq.empty()){
         auto tp(pq.top());
         pq.pop();
         char ch(tp.ch);
         int count(tp.count);
         while (i<res.length() && res[i] != ' ') ++i;
         if (i == res.length()) return "";
         int nk(0);
         while (nk < count){
            if (i + nk*k >= res.length()) return "";
            res[i + nk*k] = ch;
            ++nk;
         }
      }
      return res;
   }
};
