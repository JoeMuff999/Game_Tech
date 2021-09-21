#include "BallController.h"

using namespace godot;

void BallController::_register_methods() {
    register_method("_process", &BallController::_process);
    register_method("on_collision", &BallController::on_collision);
    register_property<BallController, Vector3>("velocity", &BallController::velocity, Vector3(10,0,0));
    // register_signal<BallController>((char *)"area_entered", "node", GODOT_VARIANT_TYPE_OBJECT, "new_pos", GODOT_VARIANT_TYPE_VECTOR2);
}

BallController::BallController() {
}

BallController::~BallController() {
    // add your cleanup here
}

void BallController::_init() {
    // initialize any variables here
    time_passed = 0.0;
    collision_cooldown = .05;
    velocity = Vector3(10,0,0);
    connect("area_entered", this, "on_collision"); //connect to the node who is emitting the signal (myself)
}


void BallController::on_collision(Variant area){

    // if(time_passed - begin_time < collision_cooldown)
    //     return;
    String name = Object::cast_to<Area>(area)->get_name();
    Node collided_with = *(get_parent()->get_node(name));
    Vector3 normal = collided_with.get("normal");
    Vector3 rhs = (2 * normal * normal.dot(velocity));
    // Godot::print(rhs);

    velocity = velocity - rhs;
    Godot::print(time_passed);
    Godot::print(name);
    Godot::print(velocity);
    begin_time = time_passed;
}


void BallController::_process(float delta) {
    time_passed += delta;
    // Array collisions = get_overlapping_areas();
    // for(int i = 0; i < collisions.size(); ++i)
    // {
    // }
    // Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));
    
    Vector3 translation = Vector3(velocity.x * delta, velocity.y * delta, velocity.z * delta);

    translate(translation);
}