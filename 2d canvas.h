#pragma once
#include "framework.h"

class Canvas
{
public:
	Canvas(int width, int height);
	~Canvas();

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

	void draw_line(int x1, int y1, int x2, int y2);
	void draw_line(Point2<int> p1, Point2<int> p2);

	int* get_bitMap();

private:
	int get_offset(int x, int y);
	bool is_pixel_inside(int x, int y);
	void set_pixel_inside(int x, int y, int rgb);
	Point2<char> pixel_position(int x, int y);
	int width, height;
	int* bitMap; //pixels of image
	float* zBufferMap; //z buffer of image
};
