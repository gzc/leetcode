/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
// Ref: http://www.algorithmist.com/index.php/Monotone_Chain_Convex_Hull.cpp
class Solution {
 public:
  typedef int coord_t;  // coordinate type
  typedef long long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
  // 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross
  // product. Returns a positive value, if OAB makes a counter-clockwise turn,
  // negative for clockwise turn, and zero if the points are collinear.
  coord2_t cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (coord2_t)(B.y - O.y) -
           (A.y - O.y) * (coord2_t)(B.x - O.x);
  }

  static bool cmp(Point &p1, Point &p2) {
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
  }

  static bool equ(Point &p1, Point &p2) { return p1.x == p2.x && p1.y == p2.y; }
  // Returns a list of points on the convex hull in counter-clockwise order.
  // Note: the last point in the returned list is the same as the first one.
  vector<Point> outerTrees(vector<Point> &P) {
    int n = P.size(), k = 0;
    vector<Point> H(2 * n);

    // Sort points lexicographically
    sort(P.begin(), P.end(), cmp);

    // Build lower hull
    for (int i = 0; i < n; i++) {
      while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
      H[k++] = P[i];
    }

    // Build upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
      while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
      H[k++] = P[i];
    }

    // Remove duplicates
    H.resize(k);
    sort(H.begin(), H.end(), cmp);
    H.erase(unique(H.begin(), H.end(), equ), H.end());
    return H;
  }
};
