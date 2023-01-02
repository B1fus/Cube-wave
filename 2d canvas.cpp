#include "2d canvas.h"

Canvas::Canvas(int width, int height):width(width),height(height)
{
	bitMap = new int[width * height];
	zBufferMap = new float[width * height];
	memset(bitMap, 0, width * height * sizeof(bitMap[0]));
	memset(zBufferMap, 0, width * height * sizeof(zBufferMap[0]));
}

Canvas::~Canvas()
{
	delete[] bitMap;
	delete[] zBufferMap;
}

void Canvas::fill_bitMap(int rgb)
{
	memset(bitMap, rgb, width * height * sizeof(bitMap[0]));
}

void Canvas::set_pixel(int x, int y, char r, char g, char b)
{
	if (!is_pixel_inside(x, y))
		return;
	int rgb = r;
	rgb = (rgb << 8) | g;
	rgb = (rgb << 8) | b;
	bitMap[get_offset(x, y)] = rgb;
}

void Canvas::set_pixel(int x, int y, int rgb)
{
	if (!is_pixel_inside(x, y))
		return;
	bitMap[get_offset(x, y)] = rgb;
}

void Canvas::set_pixel_zBuffer(int x, int y, float val)
{
	if (!is_pixel_inside(x, y))
		return;
	zBufferMap[get_offset(x, y)] = val;
}

//z - zBuffer
void Canvas::set_pixel_and_zBuffer(int x, int y, float z, char r, char g, char b)
{
	if (!is_pixel_inside(x, y))
		return;
	int rgb = r;
	rgb = (rgb << 8) | g;
	rgb = (rgb << 8) | b;
	bitMap[get_offset(x, y)] = rgb;
	zBufferMap[get_offset(x, y)] = z;
}

//z - zBuffer
void Canvas::set_pixel_and_zBuffer(int x, int y, float z, int rgb)
{
	if (!is_pixel_inside(x, y))
		return;
	bitMap[get_offset(x, y)] = rgb;
	zBufferMap[get_offset(x, y)] = z;
}

void Canvas::draw_line(int x1, int y1, int x2, int y2, int color)
{
	Point2<char> pos1 = pixel_position(x1, y1);
	Point2<char> pos2 = pixel_position(x2, y2);
	if (abs(pos1.x + pos2.x) == 2)
		return;
	if (abs(pos1.y + pos2.y) == 2)
		return;
	
	int dx = x2 - x1;
	int dy = y2 - y1;

	//x=(dy*y-a*dx+dy*b)/dx
	//y = (dx*x+a*dx-dy*b)/dy
	//a - x of point, b - y of point
	//x,y - coord of new point

	/*if (pos1.x == -1) {
		y1 = y1 - dy * (-float(x1) / dx);
		x1 = 0;
	}
	if (pos2.x == -1) {
		y2 = y2 - dy * (-float(x2) / dx);
		x2 = 0;
	}

	if (pos1.x == 1) {
		y1 = y1 - dy * (float(x1 - width) / dx);
		x1 = width - 1;
	}*/

	int x, y;

	if (pos1.x == -1) {
		x = 0;
		y = (dy * x - x1 * dy + y1 * dx) / dx;
		if (y < 0 || y >= height) {
			y = 0;
			x = (dx * y + x1 * dy - y1 * dx) / dy;
		}
		if (x < 0 || y >= width)
			return;
		x1 = x;
		y1 = y;
	}

	else if (pos1.x == 1) {
		x = width - 1;
		y = (dy * x - x1 * dy + y1 * dx) / dx;
		if (y < 0 || y >= height) {
			y = height - 1;
			x = (dx * y + x1 * dy - y1 * dx) / dy;
		}
		if (x < 0 || y >= width)
			return;
		x1 = x;
		y1 = y;
	}

	else if (pos1.y == -1) {
		y = 0;
		x = (dx * y + x1 * dy - y1 * dx) / dy;
		if (x < 0 || x >= width) {
			x = 0;
			y = (dy * x - x1 * dy + y1 * dx) / dx;
		}
		if (y < 0 || y >= height)
			return;
		x1 = x;
		y1 = y;
	}

	else if (pos1.y == 1) {
		y = height - 1;
		x = (dx * y + x1 * dy - y1 * dx) / dy;
		if (x < 0 || x >= width) {
			x = width - 1;
			y = (dy * x - x1 * dy + y1 * dx) / dx;
		}
		if (y < 0 || y >= height)
			return;
		x1 = x;
		y1 = y;
	}

	if (pos2.x == -1) {
		x = 0;
		y = (dy * x - x2 * dy + y2 * dx) / dx;
		if (y < 0 || y >= height) {
			y = 0;
			x = (dx * y + x2 * dy - y2 * dx) / dy;
		}
		if (x < 0 || y >= width)
			return;
		x2 = x;
		y2 = y;
	}

	else if (pos2.x == 1) {
		x = width - 1;
		y = (dy * x - x2 * dy + y2 * dx) / dx;
		if (y < 0 || y >= height) {
			y = height - 1;
			x = (dx * y + x2 * dy - y2 * dx) / dy;
		}
		if (x < 0 || y >= width)
			return;
		x2 = x;
		y2 = y;
	}

	else if (pos2.y == -1) {
		y = 0;
		x = (dx * y + x2 * dy - y2 * dx) / dy;
		if (x < 0 || x >= width) {
			x = 0;
			y = (dy * x - x2 * dy + y2 * dx) / dx;
		}
		if (y < 0 || y >= height)
			return;
		x2 = x;
		y2 = y;
	}

	else if (pos2.y == 1) {
		y = height - 1;
		x = (dx * y + x2 * dy - y2 * dx) / dy;
		if (x < 0 || x >= width) {
			x = width - 1;
			y = (dy * x - x2 * dy + y2 * dx) / dx;
		}
		if (y < 0 || y >= height)
			return;
		x2 = x;
		y2 = y;
	}

	dx = x2 - x1;
	dy = y2 - y1;

	int dx1, dy1, px, py, xe, ye, i;
	dx1 = abs(dx);
	dy1 = abs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;
	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		set_pixel_inside(x, y, color);
		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
			{
				px = px + 2 * dy1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					y = y + 1;
				}
				else
				{
					y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
			set_pixel_inside(x, y, color);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		set_pixel_inside(x, y, color);
		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
			{
				py = py + 2 * dx1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					x = x + 1;
				}
				else
				{
					x = x - 1;
				}
				py = py + 2 * (dx1 - dy1);
			}
			set_pixel_inside(x, y, color);
		}
	}

	/*int p = 2 * dy - dx;
	while (x < x2) {
		if (p >= 0) {
			set_pixel_inside(x, y, 0xff);
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else {
			set_pixel_inside(x, y, 0xff);
			p = p + 2 * dy;
		}
		x = x + 1;
	}*/

}

void Canvas::draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
	int temp = 0;
	//1 point smaller, 3 point bigger
	if (y1 > y2) {
		temp = y1;
		y1 = y2;
		y2 = temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (y2 > y3) {
		temp = y2;
		y2 = y3;
		y3 = temp;
		temp = x2;
		x2 = x3;
		x3 = temp;
	}
	if (y1 > y2) {
		temp = y1;
		y1 = y2;
		y2 = temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
	}

	if (y1 == y2 && y2==y3) {
		y3 += 1;
	}

	std::vector<int>& v1 = *get_xs_of_line(x1, y1, x3, y3);
	std::vector<int>& v2 = *get_xs_of_line(x1, y1, x2, y2);
	std::vector<int>& v3 = *get_xs_of_line(x2, y2, x3, y3);

	//Vec4<int> f1{ x1,y1,x2,y2 };
	//Vec2<int> f2{ x3,y3 };
	//f1.print_in_debug(L"%d ");
	//f2.print_in_debug(L"%d ");
	temp = v2.size() - 2; //temp - size xs
	int i = 0;
	int yi = v1[0] < 0 ? 0 : v1[0];
	for (; i < v1.size()-2; i++) {
		if (i +v1[0] >= height)
			break;
		if (i < temp) {
			if (v2[i + 2] > v1[i + 2]) {
				draw_horizontal_line(yi + i, v1[i + 2], v2[i + 2], color);
			}
			else {
				draw_horizontal_line(yi + i, v2[i + 2], v1[i + 2], color);
			}
				// TODO: swap 1 and 2 if x1>x2
		}
		else {
			if (v3[i + 2 - temp] > v1[i + 2]) {
				draw_horizontal_line(yi + i,  v1[i + 2 ], v3[i + 2 - temp], color);
			}
			else {
				draw_horizontal_line(yi + i, v3[i + 2 - temp],  v1[i + 2], color);

			}
		}
	}
	delete &v1;
	delete &v2;
	delete &v3;

}

int* Canvas::get_bitMap()
{
	return bitMap;
}

int Canvas::get_offset(int x, int y)
{
	return y * width + x;
}

bool Canvas::is_pixel_inside(int x, int y)
{
	return x >= 0 && x < width && y >= 0 && y < height;
}

void Canvas::set_pixel_inside(int x, int y, int rgb)
{
	bitMap[get_offset(x, y)] = rgb;
}

Point2<char> Canvas::pixel_position(int x, int y)
{
	Point2<char> res;
	res.x = x < 0 ? -1 : 0;
	res.x = x >= width ? 1 : res.x;
	res.y = y < 0 ? -1 : 0;
	res.y = y >= height ? 1 : res.y;
	return res;
}

std::vector<int>* Canvas::get_xs_of_line(int x1, int y1, int x2, int y2)
{
	int dx, dy, oldDy, x, y;
	std::vector<int>* res = new std::vector<int>();

	Point2<char> pos1 = pixel_position(x1, y1);
	Point2<char> pos2 = pixel_position(x2, y2);
	res->push_back(y1);
	res->push_back(y2);

	if (abs(pos1.x + pos2.x) == 2 && abs(pos1.y + pos2.y) == 2)
		return res;
	if (abs(pos1.y + pos2.y) == 2)
		return res;

	dx = x2 - x1;
	dy = y2 - y1;

	for (y = y1 < 0 ? 0 : y1; y < y2; y++) {
		if (y >= height)
			break;
		x = x1 + (dx * (y - y1)) / dy;
		if (x < 0)
			res->push_back(0);
		else if (x >= width)
			res->push_back(width);
		else
			res->push_back(x);
	}
	return res;
}

void Canvas::draw_horizontal_line(int y, int x1, int x2, int const& color)
{
	std::fill(bitMap + get_offset(x1, y), bitMap + get_offset(x2, y), color);
	//memset(bitMap + get_offset(x1, y), 0xff00af, (x2 - x1) * sizeof(bitMap[0]));
}
