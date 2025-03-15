#include "2d canvas.h"

Canvas::Canvas(int width, int height):width(width),height(height)
{
	bitMap = new int[width * height];
	zBufferMap = new float[width * height];
	memset(bitMap, 0, width * height * sizeof(bitMap[0]));
	memset(zBufferMap, 1, width * height * sizeof(zBufferMap[0]));
}

Canvas::~Canvas()
{
	delete[] bitMap;
	delete[] zBufferMap;
}

void Canvas::fill_bitMap(int rgb)
{
	memset(bitMap, rgb, width * height * sizeof(bitMap[0]));
	for (int i = 0; i < width * height; i++) {
		zBufferMap[i] = INFINITY;
	}
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

}

void Canvas::draw_triangle(Vec3<float> p1, Vec3<float> p2, Vec3<float> p3, int color)
{
	Vec3<float> temp;

	//1 point smaller, 3 point bigger
	if (p1.y > p2.y) {
		temp = p1;
		p1 = p2;
		p2 = temp;
	}
	if (p2.y > p3.y) {
		temp = p2;
		p2 = p3;
		p3 = temp;
	}
	if (p1.y > p2.y) {
		temp = p1;
		p1 = p2;
		p2 = temp;
	}

	if (p1.y == p2.y && p2.y == p3.y) {
		p3.y += 1;
	}

	std::vector<std::pair<int, float>>& v1 = *get_xs_of_line(p1.x, p1.y, p1.z, p3.x, p3.y, p3.z);
	std::vector<std::pair<int, float>>& v2 = *get_xs_of_line(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	std::vector<std::pair<int, float>>& v3 = *get_xs_of_line(p2.x, p2.y, p2.z, p3.x, p3.y, p3.z);

	temp.x = v2.size(); //temp.x - size xs
	int i = 0;
	int yi = p1.y < 0 ? 0 : p1.y; //y of drawing horizontal line = yi + i

	float dy13 = p3.y - p1.y;
	float dy12 = p2.y - p1.y;
	float dy23 = p3.y - p2.y;

	float dz13 = p3.z - p1.z;
	float dz12 = p2.z - p1.z;
	float dz23 = p3.z - p2.z;
	//TODO: bug with z index, when polygon goes beyond
	for (; i < v1.size(); i++) {
		if (i + p1.y >= height)
			break;
		if (i < v2.size()) {
			if (v2[i] > v1[i]) {
				draw_horizontal_line(yi + i, v1[i].first, v2[i].first, v1[i].second, v2[i].second, color);
			}
			else {
				draw_horizontal_line(yi + i, v2[i].first, v1[i].first, v2[i].second, v1[i].second, color);
			}
		}
		else {
			if (v3[i - v2.size()] > v1[i]) {
				draw_horizontal_line(yi + i, v1[i].first, v3[i - v2.size()].first, v1[i].second, v3[i - temp.x].second, color);
			}
			else {
				draw_horizontal_line(yi + i, v3[i - v2.size()].first,  v1[i].first, v3[i - temp.x].second, v1[i].second, color);

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

//first - x, second - z
std::vector<std::pair<int, float>>* Canvas::get_xs_of_line(int x1, int y1, float z1, int x2, int y2, float z2)
{
	int dx, dy, x, y;
	float dz, z;
	std::pair<int, float> addElem;
	std::vector<std::pair<int, float>>* res = new std::vector<std::pair<int, float>>();

	Point2<char> pos1 = pixel_position(x1, y1);
	Point2<char> pos2 = pixel_position(x2, y2);

	if (abs(pos1.y + pos2.y) == 2)
		return res;

	dx = x2 - x1;
	dy = y2 - y1;
	dz = z2 - z1;

	for (y = y1 < 0 ? 0 : y1; y < y2; y++) {
		if (y >= height)
			break;
		x = x1 + (dx * (y - y1)) / dy; 
		z = dz / dy * (y - y1)+z1;
		addElem = { x,z };
		res->push_back(addElem);
	}
	return res;
}

void Canvas::draw_horizontal_line(int y, int x1, int x2, float z1, float z2, int const& color)
{
	int dx = x2 - x1;
	float dz = z2 - z1;
	int maxI = x2 >= width ? width - x1 : dx;

	int offset = get_offset(x1, y);
	float z;

	for (int i = x1 < 0 ? -x1 : 0; i < dx; i++) {
		if (i >= maxI)
			break;
		z = (dz / dx * (i) + z1);
		if (zBufferMap[offset + i] > z && z > 0) {
			bitMap[offset + i] = color;
			zBufferMap[offset + i] = z;
		}
	}
}
