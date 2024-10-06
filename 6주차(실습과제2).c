#include<stdio.h>
#include<math.h>
typedef struct point {
	int x;
	int y;
}POINT;
typedef struct{
	POINT center;
	double radius;
}CIRCLE;
typedef struct rect {
	POINT lb;
	POINT rt;
};
double dist(POINT p1,POINT p2)
{
	double distance;
	distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
	return distance;
}

int main()
{
	struct point p1 = { 10,20 };
	POINT p2;
	double d;
	p1.x = 20;
	p2.x = 30;
	p2.y = 40;
	printf("p1.x=%d p1.y=%d \np2.x=%d p2.y=%d\n", p1.x, p1.y, p2.x, p2.y);
	d=dist(p1, p2);
	printf("두 점 사이의 거리는 %lf",d);

	return 0;
}
