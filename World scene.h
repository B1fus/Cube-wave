#pragma once
#include "framework.h"

class World_scene
{
public:
	void set_gdiGraphics(Gdiplus::Graphics* gr);

	Camera get_camera();
	void set_camera(Camera newCamera);

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
	Gdiplus::Graphics* GdiGr;
	std::vector<Object> objects;
	std::vector<bool> updateProjObj;
	bool updateCameraLookat, updateCameraPerspective;

	void update_camera();
};