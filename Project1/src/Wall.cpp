#include "Wall.h"

using namespace godot;


Wall::Wall() {
}

Wall::~Wall() {
    // add your cleanup here
}

void Wall::_register_methods() {
    register_property<Wall, Vector3>("normal", &Wall::normal, Vector3(0,0,0));
    register_method("_process", &Wall::_process);

}

void Wall::_init(){
    normal = Vector3(0,0,0); //hello
}

void Wall::_ready(){
}

void Wall::_process(float delta)
{
    
}