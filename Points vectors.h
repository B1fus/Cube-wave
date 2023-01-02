#pragma once
#include "framework.h"

template <typename T>
struct Point2
{
	T x, y;

	Point2()
	{
		x = T();
		y = T();
	}

	Point2(T x, T y) :x(x), y(y) {}

	Point2<T> operator+(Point2<T> const& r) const {
		Point2<T> res;
		res.x = x + r.x;
		res.y = y + r.y;
		return res;
	}

	Point2<T> operator+(T r) const {
		Point2<T> res;
		res.x = x + r;
		res.y = y + r;
		return res;
	}

	Point2<T> operator-(Point2<T> const& r) const {
		Point2<T> res;
		res.x = x - r.x;
		res.y = y - r.y;
		return res;
	}

	Point2<T> operator-(T r) const {
		Point2<T> res;
		res.x = x - r;
		res.y = y - r;
		return res;
	}

	Point2<T> operator*(Point2<T> const& r) const {
		Point2<T> res;
		res.x = x * r.x;
		res.y = y * r.y;
		return res;
	}
	
	Point2<T> operator*(T r) const {
		Point2<T> res;
		res.x = x * r;
		res.y = y * r;
		return res;
	}
	
	Point2<T> operator/(Point2<T> r) const {
		Point2<T> res;
		res.x = x / r.x;
		res.y = y / r.y;
		return res;
	}
	
	Point2<T> operator/(T r) const {
		Point2<T> res;
		res.x = x / r;
		res.y = y / r;
		return res;
	}
	
	Point2<T>& operator+=(Point2<T> const& r) {
		x = x + r.x;
		y = y + r.y;
		return *this;
	}
	
	Point2<T>& operator+=(T r) {
		x = x + r;
		y = y + r;
		return *this;
	}
	
	Point2<T>& operator-=(Point2<T> const& r) {
		x = x - r.x;
		y = y - r.y;
		return *this;
	}
	
	Point2<T>& operator-=(T r) {
		x = x - r;
		y = y - r;
		return *this;
	}
	
	Point2<T>& operator*=(Point2<T> const& r) {
		x = x * r.x;
		y = y * r.y;
		return *this;
	}
	
	Point2<T>& operator*=(T r) {
		x = x * r;
		y = y * r;
		return *this;
	}
	
	Point2<T>& operator/=(Point2<T> r) {
		x = x / r.x;
		y = y / r.y;
		return *this;
	}
	
	Point2<T>& operator/=(T r) {
		x = x / r;
		y = y / r;
		return *this;
	}
	
};

template <typename T>
inline bool operator==(const Point2<T> r, const Point2<T> l) {
	return l.x == r.x && l.y == r.y;
}


template <typename T>
struct Point3
{
	T x, y, z;

	Point3()
	{
		x = T();
		y = T();
		z = T();
	}

	Point3(T x, T y, T z) :x(x), y(y), z(z) {}

	Point3<T> operator+(Point3<T> const& r) const {
		Point3<T> res;
		res.x = x + r.x;
		res.y = y + r.y;
		res.z = z + r.z;
		return res;
	}

	Point3<T> operator+(T r) const {
		Point3<T> res;
		res.x = x + r;
		res.y = y + r;
		res.z = z + r;
		return res;
	}

	Point3<T> operator-(Point3<T> const& r) const {
		Point3<T> res;
		res.x = x - r.x;
		res.y = y - r.y;
		res.z = z - r.z;
		return res;
	}

	Point3<T> operator-(T r) const {
		Point3<T> res;
		res.x = x - r;
		res.y = y - r;
		res.z = z - r;
		return res;
	}

	Point3<T> operator*(Point3<T> const& r) const {
		Point3<T> res;
		res.x = x * r.x;
		res.y = y * r.y;
		res.z = z * r.z;
		return res;
	}
	
	Point3<T> operator*(T r) const {
		Point3<T> res;
		res.x = x * r;
		res.y = y * r;
		res.z = z * r;
		return res;
	}
	
	Point3<T> operator/(Point3<T> r) const {
		Point3<T> res;
		res.x = x / r.x;
		res.y = y / r.y;
		res.z = z / r.z;
		return res;
	}
	
	Point3<T> operator/(T r) const {
		Point3<T> res;
		res.x = x / r;
		res.y = y / r;
		res.z = z / r;
		return res;
	}
	
	Point3<T>& operator+=(Point3<T> const& r) {
		x = x + r.x;
		y = y + r.y;
		z = z + r.z;
		return *this;
	}
	
	Point3<T>& operator+=(T r) {
		x = x + r;
		y = y + r;
		z = z + r;
		return *this;
	}
	
	Point3<T>& operator-=(Point3<T> const& r) {
		x = x - r.x;
		y = y - r.y;
		z = z - r.z;
		return *this;
	}
	
	Point3<T>& operator-=(T r) {
		x = x - r;
		y = y - r;
		z = z - r;
		return *this;
	}
	
	Point3<T>& operator*=(Point3<T> const& r) {
		x = x * r.x;
		y = y * r.y;
		z = z * r.z;
		return *this;
	}
	
	Point3<T>& operator*=(T r) {
		x = x * r;
		y = y * r;
		z = z * r;
		return *this;
	}
	
	Point3<T>& operator/=(Point3<T> r) {
		x = x / r.x;
		y = y / r.y;
		z = z / r.z;
		return *this;
	}
	
	Point3<T>& operator/=(T r) {
		x = x / r;
		y = y / r;
		z = z / r;
		return *this;
	}
	
};

template <typename T>
inline bool operator==(const Point3<T> r, const Point3<T> l) {
	return l.x == r.x && l.y == r.y && l.z == r.z;
}



template <typename T>
struct Vec2
{
	T x, y;

	Vec2() {
		x = T();
		y = T();
	}

	Vec2(T x, T y) :x(x), y(y) {}

	Vec2<T> operator+(Vec2<T> const& r) const {
		Vec2<T> res;
		res.x = x + r.x;
		res.y = y + r.y;
		return res;
	}

	Vec2<T> operator+(T r) const {
		Vec2<T> res;
		res.x = x + r;
		res.y = y + r;
		return res;
	}

	Vec2<T> operator-(Vec2<T> const& r) const {
		Vec2<T> res;
		res.x = x - r.x;
		res.y = y - r.y;
		return res;
	}

	Vec2<T> operator-(T r) const {
		Vec2<T> res;
		res.x = x - r;
		res.y = y - r;
		return res;
	}

	T operator*(Vec2<T> const& r) const {
		T res;
		res = x * r.x + y * r.y;
		return res;
	}

	Vec2<T> operator*(T r) const {
		Vec2<T> res;
		res.x = x * r;
		res.y = y * r;
		return res;
	}

	Vec2<T> operator/(T r) const {
		Vec2<T> res;
		res.x = x / r;
		res.y = y / r;
		return res;
	}

	Vec2<T>& operator+=(Vec2<T> const& r) {
		x = x + r.x;
		y = y + r.y;
		return *this;
	}

	Vec2<T>& operator+=(T r) {
		x = x + r;
		y = y + r;
		return *this;
	}

	Vec2<T>& operator-=(Vec2<T> const& r) {
		x = x - r.x;
		y = y - r.y;
		return *this;
	}

	Vec2<T>& operator-=(T r) {
		x = x - r;
		y = y - r;
		return *this;
	}

	Vec2<T>& operator*=(T r) {
		x = x * r;
		y = y * r;
		return *this;
	}

	Vec2<T>& operator/=(T r) {
		x = x / r;
		y = y / r;
		return *this;
	}

	double length() {
		return sqrt(x * x + y * y);
	}

	Vec2<T> unit_vec() {
		double len = this->length();
		return { x / len, y / len };
	}

	void print_in_debug(const wchar_t* format) {
		wchar_t buffer[200];
		swprintf(buffer, 200, L"Vector 2: \n\tCoords: ");
		OutputDebugString(buffer);
		swprintf(buffer, 200, format, x);
		OutputDebugString(buffer);
		swprintf(buffer, 200, format, y);
		OutputDebugString(buffer);
		swprintf(buffer, 200, L"\n\tLength: %f\n", float(this->length()));
		OutputDebugString(buffer);
	}
};

template <typename T>
inline bool operator==(const Vec2<T> r, const Vec2<T> l) {
	return l.x == r.x && l.y == r.y;
}



template <typename T>
struct Vec3
{
	T x, y, z;

	Vec3() {
		x = T();
		y = T();
		z = T();
	}

	Vec3(Vec2<T>& vec) {
		x = vec.x;
		y = vec.y;
		z = T();
	}

	Vec3(T x, T y, T z) :x(x), y(y), z(z) {}

	Vec3<T> operator+(Vec3<T> const& r) const {
		Vec3<T> res;
		res.x = x + r.x;
		res.y = y + r.y;
		res.z = z + r.z;
		return res;
	}

	Vec3<T> operator+(T r) const {
		Vec3<T> res;
		res.x = x + r;
		res.y = y + r;
		res.z = z + r;
		return res;
	}

	Vec3<T> operator-(Vec3<T> const& r) const {
		Vec3<T> res;
		res.x = x - r.x;
		res.y = y - r.y;
		res.z = z - r.z;
		return res;
	}

	Vec3<T> operator-(T r) const {
		Vec3<T> res;
		res.x = x - r;
		res.y = y - r;
		res.z = z - r;
		return res;
	}

	T operator*(Vec3<T> const& r) const {
		T res;
		res = x * r.x + y * r.y + z * r.z;
		return res;
	}

	Vec3<T> operator*(T r) const {
		Vec3<T> res;
		res.x = x * r;
		res.y = y * r;
		res.z = z * r;
		return res;
	}

	Vec3<T> operator/(T r) const {
		Vec3<T> res;
		res.x = x / r;
		res.y = y / r;
		res.z = z / r;
		return res;
	}

	Vec3<T>& operator+=(Vec3<T> const& r) {
		x = x + r.x;
		y = y + r.y;
		z = z + r.z;
		return *this;
	}

	Vec3<T>& operator+=(T r) {
		x = x + r;
		y = y + r;
		z = z + r;
		return *this;
	}

	Vec3<T>& operator-=(Vec3<T> const& r) {
		x = x - r.x;
		y = y - r.y;
		z = z - r.z;
		return *this;
	}

	Vec3<T>& operator-=(T r) {
		x = x - r;
		y = y - r;
		z = z - r;
		return *this;
	}

	Vec3<T>& operator*=(T r) {
		x = x * r;
		y = y * r;
		z = z * r;
		return *this;
	}

	Vec3<T>& operator/=(T r) {
		x = x / r;
		y = y / r;
		z = z / r;
		return *this;
	}

	Vec3<T> crossProduct(Vec3<T> const& r) {
		Vec3<T> res;
		res.x = y * r.z - z * r.y;
		res.y = z * r.x - x * r.z;
		res.z = x * r.y - y * r.x;
		return res;
	}

	double length() {
		return sqrt(x * x + y * y + z * z);
	}

	Vec3<T> unit_vec() {
		double len = this->length();
		return { T(x / len), T(y / len), T(z / len)};
	}

	void print_in_debug(const wchar_t* format) {
		wchar_t buffer[200];
		swprintf(buffer, 200, L"Vector 3: \n\tCoords: ");
		OutputDebugString(buffer);
		swprintf(buffer, 200, format, x);
		OutputDebugString(buffer);
		swprintf(buffer, 200, format, y);
		OutputDebugString(buffer);
		swprintf(buffer, 200, format, z);
		OutputDebugString(buffer);
		swprintf(buffer, 200, L"\n\tLength: %f\n", float(this->length()));
		OutputDebugString(buffer);
	}
};

template <typename T>
inline bool operator==(const Vec3<T> r, const Vec3<T> l) {
	return l.x == r.x && l.y == r.y && l.z == r.z;
}



template <typename T>
struct Vec4
{
	T x, y, z, w;

	Vec4() {
		x = T();
		y = T();
		z = T();
		w = T();
	}

	Vec4(Vec2<T>& vec) {
		x = vec.x;
		y = vec.y;
		z = T();
		w = T();
	}

	Vec4(Vec3<T>& vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = T();
	}

	Vec4(T x, T y, T z, T w) :x(x), y(y), z(z), w(w) {}

	Vec4<T> operator+(Vec4<T> const& r) const {
		Vec4<T> res;
		res.x = x + r.x;
		res.y = y + r.y;
		res.z = z + r.z;
		res.w = w + r.w;
		return res;
	}

	Vec4<T> operator+(T r) const {
		Vec4<T> res;
		res.x = x + r;
		res.y = y + r;
		res.z = z + r;
		res.w = w + r;
		return res;
	}

	Vec4<T> operator-(Vec4<T> const& r) const {
		Vec4<T> res;
		res.x = x - r.x;
		res.y = y - r.y;
		res.z = z - r.z;
		res.w = w - r.w;
		return res;
	}

	Vec4<T> operator-(T r) const {
		Vec4<T> res;
		res.x = x - r;
		res.y = y - r;
		res.z = z - r;
		res.w = w - r;
		return res;
	}

	T operator*(Vec4<T> const& r) const {
		T res;
		res = x * r.x + y * r.y + z * r.z + w * r.w;
		return res;
	}

	Vec4<T> operator*(T r) const {
		Vec4<T> res;
		res.x = x * r;
		res.y = y * r;
		res.z = z * r;
		res.w = w * r;
		return res;
	}

	Vec4<T> operator/(T r) const {
		Vec4<T> res;
		res.x = x / r;
		res.y = y / r;
		res.z = z / r;
		res.w = w / r;
		return res;
	}

	Vec4<T>& operator+=(Vec4<T> const& r) {
		x = x + r.x;
		y = y + r.y;
		z = z + r.z;
		w = w + r.w;
		return *this;
	}

	Vec4<T>& operator+=(T r) {
		x = x + r;
		y = y + r;
		z = z + r;
		w = w + r;
		return *this;
	}

	Vec4<T>& operator-=(Vec4<T> const& r) {
		x = x - r.x;
		y = y - r.y;
		z = z - r.z;
		w = w - r.w;
		return *this;
	}

	Vec4<T>& operator-=(T r) {
		x = x - r;
		y = y - r;
		z = z - r;
		w = w - r;
		return *this;
	}

	Vec4<T>& operator*=(T r) {
		x = x * r;
		y = y * r;
		z = z * r;
		w = w * r;
		return *this;
	}

	Vec4<T>& operator/=(T r) {
		x = x / r;
		y = y / r;
		z = z / r;
		w = w / r;
		return *this;
	}

	double length() {
		return sqrt(x * x + y * y + z * z + w * w);
	}

	Vec4<T> unit_vec() {
		double len = this->length();
		return { x / len, y / len, z / len , w / len};
	}

	void print_in_debug(const wchar_t* format) {
		wchar_t buffer[200];
		swprintf(buffer, 200, L"Vector 4: \n\tCoords: ");
		OutputDebugString(buffer);
		swprintf(buffer, 200, format, x);
		OutputDebugString(buffer);
		swprintf(buffer, 200, format, y);
		OutputDebugString(buffer);
		swprintf(buffer, 200, format, z);
		OutputDebugString(buffer);
		swprintf(buffer, 200, format, w);
		OutputDebugString(buffer);
		swprintf(buffer, 200, L"\n\tLength: %f\n", float(this->length()));
		OutputDebugString(buffer);
	}
};

template <typename T>
inline bool operator==(const Vec4<T> r, const Vec4<T> l) {
	return l.x == r.x && l.y == r.y && l.z == r.z && l.w == r.w;
}



//matrix M x N
//M - rows
//N - cols
template <typename T>
struct Mat2
{

	//M-rows, N-cols
	Mat2(int M, int N):M(M),N(N) {
		mat = new T[M*N];
		std::fill(mat, mat + M * N, 0);
	}

	Mat2(Mat2<T> const& cMat) {
		M = cMat.M;
		N = cMat.N;
		mat = new T[M*N];
		for (int i = 0; i < N * M; i++) {
			mat[i] = cMat.mat[i];
		}
	}

	//M-rows, N-cols
	Mat2(int M, int N, const T* arr) :M(M), N(N) {
		mat = new T[M * N];
		memcpy(mat, arr, M * N * sizeof(T));
	}

	Mat2(Vec4<T> vec) {
		mat = new T[4];
		mat[0] = vec.x;
		mat[1] = vec.y;
		mat[2] = vec.z;
		mat[3] = vec.w;
		M = 4, N = 1;
	}

	Mat2(Vec3<T> vec) {
		mat = new T[3];
		mat[0] = vec.x;
		mat[1] = vec.y;
		mat[2] = vec.z;
		M = 3, N = 1;
	}

	Mat2(Vec2<T> vec) {
		mat = new T[2];
		mat[0] = vec.x;
		mat[1] = vec.y;
		M = 2, N = 1;
	}

	Mat2() {}

	~Mat2() {
		delete[] mat;
	}

	void fill(T val) {
		std::fill(mat, mat + M * N, val);
	}

	//clear all mat and makes identity matrix
	//need a square matrix
	void identity_mat() {
		if (N != M)
			return;
		int i, j;
		for (i = 0; i < M; i++)
			for (j = 0; j < M; j++)
				mat[get_offset(i, j)] = i == j ? 1 : 0;
	}
	
	//m-row, n-col
	inline T get_element(int m, int n) {
		if (m < 0 || m >= M || n < 0 || n >= N)
			return -1;
		return mat[get_offset(m, n)];
	}

	//m-row, n-col
	inline void set_element(int m, int n, T value) {
		if (m < 0 || m >= M || n < 0 || n >= N)
			return;
		mat[get_offset(m, n)] = value;
	}

	Mat2<T> operator+(Mat2<T> const& r) const {
		if (M != r.M || N != r.N)
			return *this;
		Mat2<T> res(M, N);

		for (int i = 0; i < M * N; i++)
			res.mat[i] = mat[i] + r.mat[i];
		
		return res;
	}

	Mat2<T>& operator+=(Mat2<T> const& r) {
		if (M != r.M || N != r.N)
			return *this;

		for (int i = 0; i < M * N; i++)
			mat[i] = mat[i] + r.mat[i];

		return *this;
	}

	Mat2<T> operator-(Mat2<T> const& r) const {
		if (M != r.M || N != r.N)
			return *this;
		Mat2<T> res(M, N);

		for (int i = 0; i < M * N; i++)
			res[i] = mat[i] - r.mat[i];

		return res;
	}

	Mat2<T>& operator-=(Mat2<T> const& r) {
		if (M != r.M || N != r.N)
			return *this;

		for (int i = 0; i < M * N; i++)
			mat[i] = mat[i] - r.mat[i];

		return *this;
	}

	Mat2<T> operator*(T const& r) const {
		Mat2<T> res(M, N);
		for (int i = 0; i < M * N; i++)
			res[i] = mat[i] * r;
		return res;
	}

	Mat2<T>& operator*=(T const& r) {
		for (int i = 0; i < M * N; i++)
			mat[i] = mat[i] * r;
		return *this;
	}

	Mat2<T> operator/(T const& r) const {
		Mat2<T> res(M, N);
		for (int i = 0; i < M * N; i++)
			res[i] = mat[i] / r;
		return res;
	}

	Mat2<T>& operator/=(T const& r) {
		for (int i = 0; i < M * N; i++)
			mat[i] = mat[i] / r;
		return *this;
	}

	Mat2<T> operator*(Mat2<T>const & r) const {
		if (N != r.M)
			return *this;
		Mat2<T> res(M, r.N);
		int i, j, k;
		T sum;
		for (i = 0; i < M; i++) {
			for (j = 0; j < r.N; j++) {
				sum = 0;
				for (k = 0; k < N; k++) {
					sum = sum + mat[get_offset(i, k)] * r.mat[r.get_offset(k, j)];
				}
				res.mat[res.get_offset(i,j)] = sum;
			}
		}
		return res;
	}

	Mat2<T>& operator*=(Mat2<T>const & r) {
		*this = *this * r;
		return *this;
	}

	Mat2<T>& operator=(Mat2<T>const & r) {
		if (this == &r)
			return *this;
		delete[] mat;
		M = r.M;
		N = r.N;
		mat = new T[N*M];
		memcpy(mat, r.mat, M * N * sizeof(r.mat[0]));
		return *this;
	}

	void print_in_debug(const wchar_t* format) {
		int i, j;
		wchar_t buffer[200];
		swprintf(buffer, 200, L"Printing matrix %d x %d:\n", M, N);
		OutputDebugString(buffer);
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				swprintf(buffer, 200, format, mat[get_offset(i, j)]);
				OutputDebugString(buffer);
			}
			swprintf(buffer, 200, L"\n");
			OutputDebugString(buffer);
		}
	}

	Mat2<T> transpose() {
		Mat2<T> res(N, M);
		int i, j;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				res.mat[res.get_offset(i, j)] = mat[get_offset(j, i)];
			}
		}
		return res;
	}
	//friend bool operator==(const Mat2<T>& r, const Mat2<T>& l);

private:
	int M, N;
	T* mat;

	inline int get_offset(int m, int n) const {
		return N * m + n;
	}
};
