#ifndef CameraController_H
#define CameraController_H

#include <Godot.hpp>
#include <Camera.hpp>
#include <Input.hpp>


namespace godot
{

    class CameraController : public Camera
    {
        GODOT_CLASS(CameraController, Camera)

    private:
        Vector3 move_speed;
        Vector3 rotation_speed;

    public:
        static void _register_methods();

        CameraController();
        ~CameraController();

        

        void _init(); // our initializer called by Godot

        void _physics_process(float delta);
    };

}

#endif