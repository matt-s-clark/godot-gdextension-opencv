#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/texture_rect.hpp>
#include <godot_cpp/classes/image_texture.hpp>

namespace godot
{

    class GDExample : public TextureRect
    {
        GDCLASS(GDExample, TextureRect)

    private:
        double time_passed;
        Ref<Image> godotImg;

    protected:
        static void _bind_methods();

    public:
        GDExample();
        ~GDExample();

        void _process(double delta) override;

        Ref<Image> get_godot_image();
    };

}

#endif