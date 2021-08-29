struct Point {
	int x = 0, y = 0;
};

int ccw(Point A, Point B, Point C) {
	return (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y);
}
