#include "World scene.h"

World_scene::World_scene()
{
	updateCameraLookat = 0;
	updateCameraPerspective = 0;
	objects = std::vector<Object>();
	updateProjObj = std::vector<bool>();
	GdiGr = nullptr;
	camera = Camera();
}

World_scene::~World_scene()
{

}

void World_scene::set_gdiGraphics(Gdiplus::Graphics* gr)
{
	GdiGr = gr;
}

void World_scene::add_object(Object obj)
{
	obj.update_mat_transform(camera);
	updateProjObj.push_back(0);
	objects.push_back(obj);
}

void World_scene::draw_objects()
{
	std::vector<Object>::iterator iter;
	for (iter = objects.begin(); iter != objects.end(); iter++) {
		iter->draw_polygons(*GdiGr);
	}
}

int World_scene::get_count_objects() {
	return objects.size();
}

Object& World_scene::edit_object(int num)
{
	updateProjObj[num] = 1;
	return objects[num];
}

void World_scene::update_world()
{
	for (int i = 0; i < updateProjObj.size(); i++) {
		if (updateProjObj[i]) {
			objects[i].update_mat_transform(camera);
			updateProjObj[i] = 0;
		}
	}
}
