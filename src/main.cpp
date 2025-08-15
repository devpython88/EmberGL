#include "ember/ember.hpp"

class MyScene : public Scene {
    public:

    RectObject2D rect = RectObject2D(10, 10, 50, 50, EM_COLOR_BLUE);

    MyScene(): Scene(){
        setBackgroundColor(EM_COLOR_WHITE);
        setFps(60);
    }

    void update(float dt) override {
        rect.rotate(5);
    }

    void draw(GFX& gfx) override {
        gfx.fillRect(rect);
    }
};

int main(int argc, char const *argv[])
{
    Ember::setInitializationFlags(AntiAlias);
    Ember::initialize("Hello", 640, 480);
    MyScene s;
    Ember::run(s);
    return 0;
}
