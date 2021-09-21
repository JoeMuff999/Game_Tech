#ifndef Wall_H
#define Wall_H

#include <Godot.hpp>
#include <Area.hpp>

namespace godot
{
    class Wall : public Area
    {
        GODOT_CLASS(Wall, Area)



    private:
        Vector3 normal;

    public:
        static void _register_methods();

        Wall();
        ~Wall();

        void _init(); //required
        void _process(float delta);
        void _ready();
    };
}

#endif