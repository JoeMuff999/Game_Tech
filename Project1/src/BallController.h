#ifndef BallController_H
#define BallController_H

#include <Godot.hpp>
#include <Spatial.hpp>
#include <Area.hpp>

namespace godot
{

    class BallController : public Area
    {
        GODOT_CLASS(BallController, Area)

    private:
        float time_passed;
        float collision_cooldown;
        float begin_time;
        Vector3 velocity;

    public:
        static void _register_methods();

        BallController();
        ~BallController();

        void on_collision(Variant area);


        void _init(); // our initializer called by Godot

        void _process(float delta);
    };

}

#endif