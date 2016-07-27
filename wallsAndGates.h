class Solution {
public:
   void wallsAndGates(vector<vector<int>>& rooms) {
      for (int i = 0; i < rooms.size(); ++i){
         for (int j = 0; j < rooms[0].size(); ++j){
            if (rooms[i][j] == 0){
               dfs(rooms, i + 1, j, 1);
               dfs(rooms, i - 1, j, 1);
               dfs(rooms, i, j + 1, 1);
               dfs(rooms, i, j - 1, 1);
            }
         }
      }
   }

   void dfs(vector<vector<int>>& rooms, int i, int j, int depth){
      if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[0].size()) return;
      if (rooms[i][j] <= 0) return;
      if (depth >= rooms[i][j]) return;
      rooms[i][j] = depth;
      dfs(rooms, i + 1, j, depth + 1);
      dfs(rooms, i - 1, j, depth + 1);
      dfs(rooms, i, j + 1, depth + 1);
      dfs(rooms, i, j - 1, depth + 1);
   }

   void bfs(vector<vector<int>> &rooms){
      queue<pair<int, int>> q;
      for (int i = 0; i < rooms.size(); ++i){
         for (int j = 0; j < rooms[0].size(); ++j){
            if (rooms[i][j] == 0) q.push({i,j});
         }
      }

      while (!q.empty()){
         auto pr(q.front());
         q.pop();
         int r(pr.first), c(pr.second);

         int dk[8] = {-1,0,1,0,0,1,0,-1};
         for (int k = 0; k < 4; ++k){
            int rk(r + dk[k]), ck(c+dk[k+4]);
            if (rk < 0 || rk >= rooms.size() || ck < 0 || ck >= rooms[0].size()) continue;
            if (rooms[rk][ck] <= 0) continue;
            if (rooms[rk][ck] <= 1 + rooms[r][c]) continue;
            rooms[rk][ck] = 1 + rooms[r][c];
            q.push({rk, ck});
         }
      }
   }
};
