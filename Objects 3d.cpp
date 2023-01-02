#include "Objects 3d.h"

Object::Object()
{
	rotation = { 0,0,0 };
	scale = { 0,0,0 };
	position = { 0,0,0 };
	matTransform = Mat2<float>(4, 4);
	matTransform.identity_mat();
}

Object::~Object()
{
}
void Object::draw_edges(Canvas& gr)
{
	//static Gdiplus::Pen pen(Gdiplus::Color(0, 0, 0));
	Point2<signed char> here0, here1, here2; //if point on screen
	for (int i = 0; i < polygons.size(); i += 3) {
		here0.x = showVertices[polygons[i]].x < 0 ? -1 : 0;
		here0.x = showVertices[polygons[i]].x >= SCREEN_WIDTH ? 1 : here0.x;
		here0.y = showVertices[polygons[i]].y < 0 ? -1 : 0;
		here0.y = showVertices[polygons[i]].y >= SCREEN_HEIGHT ? 1 : here0.y;

		here1.x = showVertices[polygons[i + 1]].x < 0 ? -1 : 0;
		here1.x = showVertices[polygons[i + 1]].x >= SCREEN_WIDTH ? 1 : here1.x;
		here1.y = showVertices[polygons[i + 1]].y < 0 ? -1 : 0;
		here1.y = showVertices[polygons[i + 1]].y >= SCREEN_HEIGHT ? 1 : here1.y;

		here2.x = showVertices[polygons[i + 2]].x < 0 ? -1 : 0;
		here2.x = showVertices[polygons[i + 2]].x >= SCREEN_WIDTH ? 1 : here2.x;
		here2.y = showVertices[polygons[i + 2]].y < 0 ? -1 : 0;
		here2.y = showVertices[polygons[i + 2]].y >= SCREEN_HEIGHT ? 1 : here2.y;
		
		if (here0.x + here1.x != -2 && here0.x + here1.x != 2)
		if (here0.y + here1.y != -2 && here0.y + here1.y != 2)
			gr.draw_line(showVertices[polygons[i]].x, showVertices[polygons[i]].y, showVertices[polygons[i + 1]].x, showVertices[polygons[i + 1]].y, 0x0);

		if (here1.x + here2.x != -2 && here1.x + here2.x != 2)
		if (here1.y + here2.y != -2 && here1.y + here2.y != 2)
			gr.draw_line(showVertices[polygons[i + 1]].x, showVertices[polygons[i + 1]].y, showVertices[polygons[i + 2]].x, showVertices[polygons[i + 2]].y, 0x0);

		if (here0.x + here2.x != -2 && here0.x + here2.x != 2)
		if (here0.y + here2.y != -2 && here0.y + here2.y != 2)
			gr.draw_line(showVertices[polygons[i]].x, showVertices[polygons[i]].y, showVertices[polygons[i + 2]].x, showVertices[polygons[i + 2]].y, 0x0);
	}
}

void Object::draw_polygons(Canvas& gr)
{
	Point2<signed char> here0, here1, here2; //if point on screen
	int color = 0;
	for (int i = 0; i < polygons.size(); i += 3) {
		if (i / 3 < colors.size())
			color = colors[i / 3];
		else
			color = 0;
		here0.x = showVertices[polygons[i]].x < 0 ? -1 : 0;
		here0.x = showVertices[polygons[i]].x >= SCREEN_WIDTH ? 1 : here0.x;
		here0.y = showVertices[polygons[i]].y < 0 ? -1 : 0;
		here0.y = showVertices[polygons[i]].y >= SCREEN_HEIGHT ? 1 : here0.y;

		here1.x = showVertices[polygons[i + 1]].x < 0 ? -1 : 0;
		here1.x = showVertices[polygons[i + 1]].x >= SCREEN_WIDTH ? 1 : here1.x;
		here1.y = showVertices[polygons[i + 1]].y < 0 ? -1 : 0;
		here1.y = showVertices[polygons[i + 1]].y >= SCREEN_HEIGHT ? 1 : here1.y;

		here2.x = showVertices[polygons[i + 2]].x < 0 ? -1 : 0;
		here2.x = showVertices[polygons[i + 2]].x >= SCREEN_WIDTH ? 1 : here2.x;
		here2.y = showVertices[polygons[i + 2]].y < 0 ? -1 : 0;
		here2.y = showVertices[polygons[i + 2]].y >= SCREEN_HEIGHT ? 1 : here2.y;
		
		if (here0.x + here1.x + here2.x != -3 && here0.x + here1.x + here2.x != 3)
		if (here0.y + here1.y + here2.y != -3 && here0.y + here1.y + here2.y != 3) {
			if (here0.y == -1)
				here0.y = 0;
			//if (Vec3<float>{0, 0, 1 } *((showVertices[polygons[i]] - showVertices[polygons[i + 1]]).crossProduct((showVertices[polygons[i + 1]] - showVertices[polygons[i + 2]])).unit_vec()) > 0)
			//(showVertices[polygons[i + 1]] - showVertices[polygons[i]]).print_in_debug(L"%f ");
			//((showVertices[polygons[i + 1]] - showVertices[polygons[i]]).crossProduct((showVertices[polygons[i + 2]] - showVertices[polygons[i]]))).print_in_debug(L"%f ");
			if(Vec3<float>{ 0,0,-1 } *((showVertices[polygons[i]] - showVertices[polygons[i + 1]]).crossProduct((showVertices[polygons[i + 1]] - showVertices[polygons[i + 2]]))) < 0)
				gr.draw_triangle(showVertices[polygons[i]].x, showVertices[polygons[i]].y, showVertices[polygons[i + 1]].x, showVertices[polygons[i + 1]].y ,showVertices[polygons[i + 2]].x, showVertices[polygons[i + 2]].y , color);
		}
	}

}

void Object::draw_vertices(Gdiplus::Graphics& gr)
{
	Gdiplus::SolidBrush brush(Gdiplus::Color(0, 0, 0));
	static Gdiplus::FontFamily  fontFamily(L"Times New Roman");
	static Gdiplus::Font font(&fontFamily, 12);
	int c = 0;
	for (std::vector<Vec3<float>>::iterator i = showVertices.begin(); i != showVertices.end(); i++) {
		if(i->x>=0 && i->x<SCREEN_WIDTH)
			if (i->y >= 0 && i->y < SCREEN_HEIGHT) {
				gr.FillEllipse(&brush, (int)i->x, (int)i->y, 5, 5);
				gr.DrawString((wchar_t*)std::to_wstring(c).c_str(), 4, &font, Gdiplus::PointF(i->x, i->y), &brush);
			}
		c++;
	}
}

void Object::set_vertices(std::vector<Vec3<float>> vert)
{
	vertices = vert;
}

void Object::set_polygons(std::vector<int> polygons)
{
	this->polygons = polygons;
}

void Object::set_colors(std::vector<int> colors)
{
	this->colors = colors;
}

void Object::update_mat_transform(Camera const& camera)
{
	if(showVertices.size()!=vertices.size())
		showVertices = vertices;
	matTransform.identity_mat(); 
	matTransform = get_scale_mat(scale) * matTransform;
	matTransform = get_rotation_mat(rotation) * matTransform;
	matTransform = camera.lookatMat * matTransform;
	matTransform = get_position_mat(position) * matTransform;
	matTransform = camera.perspectiveMat * matTransform;

	Vec4<float> vert;
	Mat2<float> vertMat(4,1);
	for (int i = 0; i < vertices.size(); i++) {
		vert = Vec4<float>{ vertices[i] };
		vert.w = 1;
		vertMat = Mat2<float>(vert);
		vertMat = matTransform * vertMat;
		
		showVertices[i].x = (vertMat.get_element(0, 0) / vertMat.get_element(3,0) + 1) * SCREEN_WIDTH / 2;
		showVertices[i].y = (vertMat.get_element(1, 0) / vertMat.get_element(3,0) + 1) * SCREEN_HEIGHT / 2;
		//showVertices[i].x = vertMat.get_element(0, 0) / vertMat.get_element(2, 0) * 100;
		//showVertices[i].y = vertMat.get_element(1, 0) / vertMat.get_element(2, 0) * 100;
		showVertices[i].z = vertMat.get_element(2, 0) / vertMat.get_element(3, 0);
		//showVertices[i].print_in_debug(L"%f ");
		//vertMat.print_in_debug(L"%f ");
	}
}

Mat2<float> Object::get_scale_mat(Vec3<float> scale)
{
	Mat2<float> res(4, 4);
	res.set_element(0, 0, scale.x);
	res.set_element(1, 1, scale.y);
	res.set_element(2, 2, scale.z);
	res.set_element(3, 3, 1);
	return res;
}

Mat2<float> Object::get_position_mat(Vec3<float> position)
{
	Mat2<float> res(4, 4);
	res.identity_mat();
	res.set_element(0, 3, position.x);
	res.set_element(1, 3, position.y);
	res.set_element(2, 3, position.z);
	res.set_element(3, 3, 1);
	return res;
}

Mat2<float> Object::get_rotation_mat(Vec3<float> rotation)
{
	Mat2<float> res(4, 4);
	Mat2<float> res2(4, 4);
	res.identity_mat();

	//x
	float sina = sinf(M_1_DEGREE_IN_PI * rotation.x);
	float cosa = cosf(M_1_DEGREE_IN_PI * rotation.x);
	res2.set_element(0, 0, 1);
	res2.set_element(1, 1, cosa);
	res2.set_element(1, 2, -sina);
	res2.set_element(2, 1, sina);
	res2.set_element(2, 2, cosa);
	res2.set_element(3, 3, -1);

	res *= res2;

	//y
	res2.fill(0);
	sina = sinf(M_1_DEGREE_IN_PI * rotation.y);
	cosa = cosf(M_1_DEGREE_IN_PI * rotation.y);
	res2.set_element(0, 0, cosa);
	res2.set_element(0, 2, sina);
	res2.set_element(1, 1, 1);
	res2.set_element(2, 0, -sina);
	res2.set_element(2, 2, cosa);
	res2.set_element(3, 3, 1);

	res = res * res2;

	//z
	res2.fill(0);
	sina = sinf(M_1_DEGREE_IN_PI * rotation.z);
	cosa = cosf(M_1_DEGREE_IN_PI * rotation.z);
	res2.set_element(0, 0, cosa);
	res2.set_element(0, 1, -sina);
	res2.set_element(1, 0, sina);
	res2.set_element(1, 1, cosa);
	res2.set_element(2, 2, 1);
	res2.set_element(3, 3, 1);

	res = res * res2;

	return res;
}

Camera::Camera()
{
	position = { 0,-100,-400 };
	up = { 0,-1,0 };
	direction = { 0,0,1 };

	fov = 90;
	aspect = float(SCREEN_WIDTH) / SCREEN_HEIGHT;
	nearZ = 10;
	farZ = 1000;
	lookatMat = create_lookat_mat();
	perspectiveMat = create_perspective_mat();
}

Camera::~Camera()
{
}

void Camera::update_perspective_mat()
{
	perspectiveMat = create_perspective_mat();
}

void Camera::update_lookat_mat()
{
	lookatMat = create_lookat_mat();
}
//
//Vec3<float> Camera::get_position()
//{
//	return position;
//}
//
//Vec3<float> Camera::get_up()
//{
//	return up;
//}
//
//Vec3<float> Camera::get_direction()
//{
//	return direction;
//}
//
//void Camera::set_position(Vec3<float> const& pos)
//{
//	position = pos;
//	lookatMat = create_lookat_mat();
//}
//
//void Camera::set_up(Vec3<float> const& up)
//{
//	this->up = up;
//	lookatMat = create_lookat_mat();
//}
//
//void Camera::set_direction(Vec3<float> const& dir)
//{
//	direction = dir;
//	lookatMat = create_lookat_mat();
//}

Mat2<float> Camera::create_perspective_mat()
{
	Mat2<float> res(4, 4);
	float tanFov = 1 / tanf(M_1_DEGREE_IN_PI * fov / 2);
	float sx = tanFov / aspect;
	float sy = tanFov;
	float sz = (farZ + nearZ) / (farZ - nearZ);
	float dz = -(2 * farZ * nearZ) / (farZ - nearZ);

	res.set_element(0, 0, sx);
	res.set_element(1, 1, sy);
	res.set_element(2, 2, sz);
	res.set_element(2, 3, dz);
	res.set_element(3, 2, 1);

	return res;
}

Mat2<float> Camera::create_lookat_mat() {

	Vec3<float> vz = (direction).unit_vec();
	Vec3<float> vx = (up.crossProduct(vz)).unit_vec();
	Vec3<float> vy = (vz.crossProduct(vx)).unit_vec();

	float arr[] = {
		vx.x,vx.y,vx.z,0,
		vy.x,vy.y,vy.z,0,
		vz.x,vz.y,vz.z,0,
		0, 0, 0, 1
	};
	Mat2<float> res(4, 4, arr);
	Mat2<float> res2(4, 4);
	res2.identity_mat();
	res2.set_element(0, 3, -position.x);
	res2.set_element(1, 3, -position.y);
	res2.set_element(2, 3, -position.z);
	res = res2 * res;

	return res;
}

