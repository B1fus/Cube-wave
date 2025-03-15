#include "World scene.h"

World_scene::World_scene()
{
	updateCameraLookat = 0;
	updateCameraPerspective = 0;
	objects = std::vector<Object>();
	updateProjObj = std::vector<bool>();
	canvas = nullptr;
	camera = Camera();
}

World_scene::~World_scene()
{

}

void World_scene::set_canvas(Canvas* canvas) {
	this->canvas = canvas;
}

Camera World_scene::get_camera()
{
	return camera;
}

void World_scene::add_position_camera(Vec3<float> pos)
{
	camera.position += pos;
	updateCameraLookat = 1;
}

Vec3<float> World_scene::get_direction_camera()
{
	return camera.direction;
}

void World_scene::set_direction_camera(Vec3<float> dir)
{
	camera.direction = dir;
	updateCameraLookat = 1;
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
		//iter->draw_polygons(*canvas, camera.direction * -1);
		iter->draw_polygons(*canvas, camera);
		//iter->draw_edges(*canvas);
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
	if (updateCameraLookat) {
		camera.update_lookat_mat();
	}
	if (updateCameraPerspective) {
		camera.update_perspective_mat();
	}
	if (updateCameraLookat || updateCameraPerspective) {
		for (int i = 0; i < updateProjObj.size(); i++) {
			objects[i].update_mat_transform(camera);
			updateProjObj[i] = 0;
		}
	}
	else {
		for (int i = 0; i < updateProjObj.size(); i++) {
			if (updateProjObj[i]) {
				objects[i].update_mat_transform(camera);
				updateProjObj[i] = 0;
			}
		}
	}
	updateCameraLookat = 0;
	updateCameraPerspective = 0;
}
