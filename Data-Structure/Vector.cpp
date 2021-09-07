const double PI =  2.0 * acos(0.0);

struct vector {
	double x, y;

	explicit vector(double _x = 0, double _y = 0) : x(_x), y(_y) {}

	bool operator == (const vector& other) const {
		return x == other.x && y == other.y;
	}

	bool operator < (const vector& other) const {
		return (x != other.x) ? x < other.x : y < other.y;
	}

	vector operator + (const vector& other) const {
		return vector(x + other.x, y + other.y);
		// other의 시작점을 *this의 끝점으로 옮겼을 때 other의 끝점에서 끝나는 vector
	}

	vector operator - (const vector& other) const {
		return vector(x - other.x, y - other.y);
		// x - y 는 y의 끝점에서 x의 끝점으로 가는 vector
	}

	vector operator * (double n) const {
		return vector(n * x, n * y);
		// vector의 길이를 n배로 늘린 vector
	}

	double norm() const {
		// hypotenuse -> https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/hypot-hypotf-hypotl-hypot-hypotf-hypotl?view=vs-2019
		return hypot(x, y);
	}
	
	// 동일한 방향의 unit vector를 반환
	vector normalize() const {
		return vector(x / norm(), y / norm());
	}

	double polar_angle() const {
		// double fmod(double x, double y) returns the remainder of x divided by y
		// atan2 -> https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/hypot-hypotf-hypotl-hypot-hypotf-hypotl?view=vs-2019
		return fmod(atan2(y, x) + 2 * PI, 2 * PI);
		
		/*
		atan2()의 return 값은 [ -PI, PI ] 이므로, [ 0, 2 * PI ) 구간의 값이 되도록 fmod()를 사용.
		(2 * PI)를 더한 뒤 (2 * PI)로 나눈 나머지는 항상 [ 0, 2 * PI ) 구간에 존재.
		*/
	}

	// https://wikidocs.net/22384
	// inner product
	double dot_product(const vector& other) const {
		return x * other.x + y * other.y;
	}
	
	// outer product
	double cross_product(const vector& other) const {
		return x * other.y - other.x * y;
	}

	vector projection_vector(const vector& other) const {
		vector r = other.normalize();
		return r * r.dot_product(*this);
	}
};

// 3개의 점에서 a가 b보다 p에 얼마나 가까운가
double howMuchCloser(vector& p, vector& a, vector& b){
	return (b - p).norm() - (a - p).norm();
}

double Counter_ClockWise(vector& a, vector& b) {
	return a.cross_product(b);
	// 원점에서 vector b가 vector a의 반시계 방향이면 양수, 시계방향이면 음수, 평행이면 0을 return
}

double Counter_ClockWise(vector& p, vector& a, vector& b) {
	return Counter_ClockWise(a - p, b - p);
	// p를 기준으로 vector b가 vector a의 반시계 방향이면 양수, 시계방향이면 음수, 평행이면 0을 return
}
