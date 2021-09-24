#include "CameraController.h"


using namespace godot;

void CameraController::_register_methods() {
    register_method("_physics_process", &CameraController::_physics_process);
    register_property<CameraController, Vector3>("velocity", &CameraController::move_speed, Vector3(10,0,0));
    register_property<CameraController, Vector3>("angular velocity", &CameraController::rotation_speed, Vector3(M_PI,M_PI,M_PI));

}

CameraController::CameraController() {
}

CameraController::~CameraController() {
    // add your cleanup here
}

void CameraController::_init()
{
    move_speed = Vector3(10,0,0);
    rotation_speed = Vector3(M_PI,M_PI,M_PI);
}

void CameraController::_physics_process(float delta)
{
    Input* input = Input::get_singleton(); 
    Vector3 to_translate(0,0,0);
    if (input->is_action_pressed("move_right"))
    {
        to_translate += move_speed * Vector3::RIGHT * delta;
    }
    if (input->is_action_pressed("move_left"))
    {
        to_translate += move_speed * Vector3::LEFT * delta;
    }
    if (input->is_action_pressed("move_forward"))
    {
        to_translate += move_speed * Vector3::FORWARD* delta;
    }
    if (input->is_action_pressed("move_back"))
    {
        to_translate += move_speed * Vector3::BACK * delta;
    }
    if (input->is_action_pressed("move_forward"))
    {
        to_translate += move_speed * Vector3::UP* delta;
    }
    if (input->is_action_pressed("move_back"))
    {
        to_translate += move_speed * Vector3::DOWN * delta;
    }

    Vector3 to_rotate(0,0,0);
    if (input->is_action_pressed("rotate_left"))
    {
        to_rotate += rotation_speed * Vector3::RIGHT* delta; 
    }
    if (input->is_action_pressed("rotate_right"))
    {
       to_rotate += rotation_speed * Vector3::LEFT * delta;
    }
    if (input->is_action_pressed("rotate_up"))
    {
        to_rotate += rotation_speed * Vector3::UP* delta;
    }
    if (input->is_action_pressed("rotate_down"))
    {
        to_rotate += rotation_speed * Vector3::DOWN * delta;
    }
    rotate_object_local(Vector3(0,1,0), to_rotate.x);
    rotate_object_local(Vector3(1,0,0), to_rotate.y);
    // rotate_object_local(Vector3(0,1,0), to_rotate.z);



    // if (input->is_action_pressed("move_right"))
    // {
    //     to_translate += move_speed * Vector3::RIGHT * delta;
    // }
    to_translate = to_global(to_translate);
    Vector3 new_position = to_translate;
    if(new_position.x > 7.5 || new_position.x < -7.5)
    {
        to_translate.x = get_translation().x;
    }
    if(new_position.y > 7.5 || new_position.y < -7.5)
    {
        to_translate.y = get_translation().y;
    }
    if(new_position.z < -7.5 || new_position.z > 7.5)
    {
        to_translate.z = get_translation().z;
    }
    // Godot::print(to_global(Vector3(0,0,1)));
    global_translate(to_translate - get_translation());
    // Godot::print(get_translation());
    
}