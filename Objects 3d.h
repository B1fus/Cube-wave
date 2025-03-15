
#pragma once
#include <fstream>
#include <sstream>
#include <random>
#include "framework.h"
#include "2d canvas.h"

class Camera
{
public:
	Camera();
	~Camera();
	float fov, aspect, nearZ, farZ;

	Vec3<float> position;
	Vec3<float> up;
	Vec3<float> direction;

	void update_perspective_mat();
	void update_lookat_mat();

	Vec3<float> get_position();
	Vec3<float> get_up();
	Vec3<float> get_direction();

	void set_position(Vec3<float> const& pos);
	void set_up(Vec3<float> const& up);
	void set_direction(Vec3<float> const& dir);

	Mat2<float> lookatMat = Mat2<float>(4,4);
	Mat2<float> perspectiveMat = Mat2<float>(4, 4);
private:

	Mat2<float> create_perspective_mat();
	Mat2<float> create_lookat_mat();
};

class Object
{
public:
	Object();
	~Object();

	void draw_vertices(Gdiplus::Graphics& gr);
	void draw_polygons(Canvas& const gr, Camera& const camera);
	void draw_edges(Canvas& gr);

	void set_vertices(std::vector<Vec3<float>> vert);
	void set_polygons(std::vector<int> polygons);
	void set_colors(std::vector<int> colors);

	void update_mat_transform(Camera const& camera);

	static Object load_obj_file(const std::string& filepath);

	Vec3<float> rotation;
	Vec3<float> scale;
	Vec3<float> position;

private:
	std::vector<Vec3<float>> vertices;
	std::vector<Vec3<float>> showVertices; // after transformation
	std::vector<Vec3<float>> normals;
	std::vector<int> polygons;
	std::vector<int> colors; // colors of polygons

	Mat2<float> matTransform;

	static Mat2<float> get_scale_mat(Vec3<float> scale);
	static Mat2<float> get_position_mat(Vec3<float> position);
	static Mat2<float> get_rotation_mat(Vec3<float> rotation);
};
