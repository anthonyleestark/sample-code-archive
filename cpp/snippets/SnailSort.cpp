#include <cstddef>
#include <vector>
using namespace std;

vector<int> snail(const vector<vector<int>>& xs) {
  vector<int> res;
  if (xs[0].empty())
    return res;
  const size_t ny = xs.size(), nx = xs[0].size();
  res.reserve(ny * nx);
  ptrdiff_t x0 = 0, y0 = 0, x1 = nx - 1, y1 = ny - 1, x = 0, y = 0;
  while (y0 <= y1) {
    while (x < x1) res.push_back(xs[y][x++]); y0++;
    while (y < y1) res.push_back(xs[y++][x]); x1--;
    while (x > x0) res.push_back(xs[y][x--]); y1--;
    while (y > y0) res.push_back(xs[y--][x]); x0++;
  }
  res.push_back(xs[y][x]);
  return res;
}

vector<int> snail(const vector<vector<int>> &snail_map) {
    vector<int> result;
    int m = snail_map.size(), n = snail_map[0].size();
 
    if (m == 0)
        return result;
        
    vector<vector<bool>> seen(m, vector<bool>(n, false));
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
    int x = 0, y = 0, di = 0;
    
    for (int i = 0; i < m * n; i++) {
        result.push_back(snail_map[x][y]);
        seen[x][y] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];
 
        if (0 <= newX && newX < m && 0 <= newY && newY < n && !seen[newX][newY]) {
            x = newX; 
            y = newY;
        }
        else {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
    return result;
}