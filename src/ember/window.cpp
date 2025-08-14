#include "ember.hpp"

void Ember::initialize(const char *title, int width, int height)
{
    InitWindow(width, height, title);
    InitAudioDevice();
}

void Ember::run(EmScene &scene)
{
    while (!WindowShouldClose()){
        scene.update(GetFrameTime());

        BeginDrawing();
        ClearBackground(scene.backgroundColor());
        scene.draw(scene.gfx());
        EndDrawing();
    }
    
    scene.dispose();
    CloseWindow();
}
