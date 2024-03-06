// https://leetcode.com/problems/rectangle-area

int getArea(int x1, int y1, int x2, int y2) {
    return (x2-x1) * (y2-y1);
}

int duplicateArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int x = 0, y = 0;

    if (ax1 <= bx1 && bx1 < ax2) {
        x = fmin(bx2, ax2) - bx1;
    } else if (bx1 <= ax1 && ax1 < bx2) {
        x = fmin(ax2, bx2) - ax1;
    }

    if (ay1 <= by1 && by1 < ay2) {
        y = fmin(by2, ay2) - by1;
    } else if (by1 <= ay1 && ay1 < by2) {
        y = fmin(ay2, by2) - ay1;
    }

    return x * y;
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int ans = 0;

    ans += getArea(ax1, ay1, ax2, ay2);
    ans += getArea(bx1, by1, bx2, by2);
    ans -= duplicateArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

    return ans;
}
