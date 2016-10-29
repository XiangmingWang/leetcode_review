//https://leetcode.com/problems/max-points-on-a-line/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
bool samePoint(const Point& p1, const Point& p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}
struct Line {
    Point p;
    float k;
    bool vertical;
    Line(const Point& p1, const Point& p2) {
        if (p1.x == p2.x) vertical = true;
        else vertical = false;
        p = p1;
        k = 1.0 * (p1.y - p2.y) / (p1.x - p2.x);
    }

    bool verticalContain(const Point& po) {
        return vertical && (po.x == p.x);
    }
    bool containsPoint(const Point& po) {
        if (samePoint(po, p) || verticalContain(po) || fabs(1.0 * (po.y - p.y) / (po.x - p.x) - k) < 0.00001)
            return true;
        return false;
    }
};
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 1) return points.size();
        int max_size = 2;
        for (int i = 0; i < points.size() - 1; ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int now_size = 1;
                while (j < points.size() && samePoint(points[i],points[j])) {
                    ++j;
                    ++now_size;
                }
                if (j < points.size()) {
                    Line l(points[i], points[j]);
                    ++now_size;
                    for (int k = j + 1; k < points.size(); ++k) {
                        if (l.containsPoint(points[k])) ++now_size;
                    }
                }
                max_size = max(max_size, now_size);
            }
        }
        return max_size;
    }
};
