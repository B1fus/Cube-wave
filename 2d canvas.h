#pragma once
#include "Points vectors.h"
#include "framework.h"


class Canvas
{
public:
	Canvas(int width, int height);
	~Canvas();

	void fill_bitMap(int rgb);
	void set_pixel(int x, int y, char r, char g, char b);
	void set_pixel(int x, int y, int rgb);
	void set_pixel_zBuffer(int x, int y, float val);
	void set_pixel_and_zBuffer(int x, int y, float z, char r, char g, char b);
	void set_pixel_and_zBuffer(int x, int y, float z, int rgb);

	void set_pixel(Point2<int> p, char r, char g, char b);
	void set_pixel(Point2<int> p, int rgb);
	void set_pixel_zBuffer(Point2<int> p, float val);
	void set_pixel_and_zBuffer(Point2<int> p, float z, char r, char g, char b);
	void set_pixel_and_zBuffer(Point2<int> p, float z, int rgb);

	void draw_line(int x1, int y1, int x2, int y2, int color);
	void draw_line(Point2<int> p1, Point2<int> p2);

	void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color);

	int* get_bitMap();

private:
	inline int get_offset(int x, int y);
	inline bool is_pixel_inside(int x, int y);
	inline void set_pixel_inside(int x, int y, int rgb);
	Point2<char> pixel_position(int x, int y);
	std::vector<int>* get_xs_of_line(int x1, int y1, int x2, int y2);
	void draw_horizontal_line(int y, int x1, int x2, int const& color);
	int width, height;
	int* bitMap; //pixels of image
	float* zBufferMap; //z buffer of image
};
