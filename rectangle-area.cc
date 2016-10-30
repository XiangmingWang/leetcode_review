//https://leetcode.com/problems/rectangle-area/
struct Rectangle {
    int a, b, c, d;
    Rectangle(int A, int B, int C, int D) : a(A), b(B), c(C), d(D) {}
    int CoverArea(const Rectangle& other) {
        int h = 0;
        if (min(d, other.d) > max(b, other.b)) h = min(d, other.d) - max(b, other.b);
        else return 0;
        int w = 0;
        if (min(c, other.c) > max(a, other.a)) w = min(c, other.c) - max(a, other.a);
        else return 0;
        return h * w;
    }
    int Area() {
        return (c - a) * (d - b);
    }
};
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        Rectangle r1(A, B, C, D);
        Rectangle r2(E, F, G, H);
        return r1.Area() - r1.CoverArea(r2) + r2.Area() ;
    }
};
