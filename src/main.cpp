#include "ember/ember.hpp"

class MyScene : public EmScene {
    public:

    MyScene(): EmScene(){
        setBackgroundColor(EM_COLOR_PINK);
    }

    void draw(EmGFX& gfx) override {
        gfx.fillRect(20, 20, 30, 30, EM_COLOR_RED);
    }
};

int main(int argc, char const *argv[])
{
    Ember::initialize("Hello", 640, 480);
    MyScene s;
    Ember::run(s);
    return 0;
}
