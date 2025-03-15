#pragma once
#include "framework.h"
#include "2d canvas.h"
#include "Points vectors.h"
#include "Objects 3d.h"

class World_scene
{
public:
	//void set_gdiGraphics(Gdiplus::Graphics* gr);
	void set_canvas(Canvas* canvas);

	Camera get_camera();
	void set_camera(Camera newCamera);
	void set_position_camera(Vec3<float> pos);
	void add_position_camera(Vec3<float> pos);
	Vec3<float> get_direction_camera();
	void set_direction_camera(Vec3<float> dir);

	void add_object(Object obj);
	Object get_object(int num);
	void set_object(int num, Object obj);
	Object& edit_object(int num);
	int get_count_objects();

	void update_world();
	void draw_objects();

	World_scene();
	~World_scene();
private:
	Camera camera;
	//Gdiplus::Graphics* GdiGr;
	Canvas* canvas;
	std::vector<Object> objects;
	std::vector<bool> updateProjObj;
	bool updateCameraLookat, updateCameraPerspective;

	void update_camera();
};