#include "ember.hpp"

void Ember::setInitializationFlags(int flags)
{
    SetConfigFlags(flags);
}

void Ember::initialize(const char *title, int width, int height)
{
    InitWindow(width, height, title);
    InitAudioDevice();
}

void Ember::run(Scene &scene)
{
    while (!WindowShouldClose()){
        scene.update(GetFrameTime());

        BeginDrawing();
        ClearBackground(scene.getBackgroundColor());
        scene.draw(scene.getGfx());
        EndDrawing();
    }
    
    scene.dispose();
    CloseAudioDevice();
    CloseWindow();
}
