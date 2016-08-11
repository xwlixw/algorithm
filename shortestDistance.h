class Solution {
public:
   int shortestDistance(vector<vector<int>>& grid) {
      if (grid.empty()) return -1;
      int m = grid.size(), n = grid[0].size();
      if (m < 1 || n < 1) return -1;

      vector<vector<int>> dist(m,vector<int>(n,0)), reached(dist);
      int num(0);
      for (int i = 0; i < m; ++i){
         for (int j = 0; j < n; ++j){
            if (grid[i][j] == 1){
               ++num;
               queue<pair<int, int>> Q;
               vector<vector<int>> visited(grid);

               Q.push({i,j});
               visited[i][j] = 3;
               int curdist(0);
               while (!Q.empty()){
                  int sz(Q.size());
                  for (int iq = 0; iq < sz; ++iq){
                     auto frt=Q.front();
                     Q.pop();
                     dist[frt.first][frt.second] += curdist;
                     if (curdist) ++reached[frt.first][frt.second];

                     int d[8] = { -1, 0, 1, 0, 0, 1, 0, -1 };
                     for (int k = 0; k < 4; ++k){
                        int ik(frt.first + d[k]), jk(frt.second+d[4+k]);
                        if (ik<0 || ik>=m || jk < 0 || jk >= n || visited[ik][jk])
                           continue;
                        visited[ik][jk] = 3;
                        Q.push({ik,jk});
                     }
                  }
                  ++curdist;
               }
            }
         }
      }

      int res(INT_MAX);
      for (int i = 0; i < m; ++i){
         for (int j = 0; j < n; ++j){
            if (reached[i][j] == num){
               res = std::min(res, dist[i][j]);
            }
         }
      }
      return res==INT_MAX?-1:res;
   }

};
