//? 벡터 방향성 판별
// https://www.acmicpc.net/blog/view/27
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int temp = x1*y2+x2*y3+x3*y1;
    temp = temp - y1*x2-y2*x3-y3*x1;
    if (temp > 0) {
        return 1;
    } else if (temp < 0) {
        return -1;
    } else {
        return 0;
    }
}

struct Point{
    int x, y; // 실제 위치
    int p, q; // 기준점으로부터의 상대 위치
    Point(): Point(0, 0, 1, 0){}
    Point(int x1, int y1): Point(x1, y1, 1, 0){}
    Point(int x1, int y1, int p1, int q1): x(x1), y(y1), p(p1), q(q1){}
    // p, q 값을 기준으로 정렬하기 위한 관계연산자
    bool operator <(const Point& O){
        if(1LL*q*O.p != 1LL*p*O.q) return 1LL*q*O.p < 1LL*p*O.q;
        if(y != O.y) return y < O.y;
        return x < O.x;
    }
};
 
// 벡터 AB와 벡터 AC의 CW/CCW
long long ccw(const Point& A, const Point& B, const Point& C){
    return 1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
}