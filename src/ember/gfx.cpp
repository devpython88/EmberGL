#include "ember.hpp"

void EmGFX::fillRect(float x, float y, float width, float height, EmColor color)
{
    DrawRectangle(x, y, width, height, color);
}



void EmGFX::fillRect(EmVector2 position, EmDim2 size, EmColor color)
{
    fillRect(position.x, position.y, size.width, size.height, color);
}
