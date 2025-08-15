#include "ember.hpp"

void GFX::fillRect(float x, float y, float width, float height, RGBAColor color)
{
    DrawRectangle(x, y, width, height, color);
}



void GFX::fillRect(const Vec2& position, const Vec2& size, RGBAColor color)
{
    fillRect(position.x, position.y, size.x, size.y, color);
}

void GFX::strokeRect(float x, float y, float width, float height, float thickness, RGBAColor color, RGBAColor fillColor)
{
    float finalThickness = thickness / 2;
    fillRect(x - finalThickness, y - finalThickness, width + thickness, height + thickness, color);
    fillRect(x, y, width, height, fillColor);
}

void GFX::strokeRect(const Vec2& position, const Vec2& size, float thickness, RGBAColor color, RGBAColor fillColor)
{
    strokeRect(position.x, position.y, size.x, size.y, thickness, color, fillColor);
}

void GFX::lineRect(float x, float y, float width, float height, RGBAColor color)
{
    DrawRectangleLines(x, y, width, height, color);
}

void GFX::lineRect(const Vec2& position, const Vec2& size, RGBAColor color)
{
    lineRect(position.x, position.y, size.x, size.y, color);
}

void GFX::fillRect(RectObject2D& rect){
    DrawRectanglePro(
        rect,
        rect.getOrigin(), rect.getAngle(), rect.getColor()
    );
}

void GFX::fillCircle(float x, float y, float radius, RGBAColor color){
    DrawCircle(x, y, radius, color);
}

void GFX::fillCircle(const Vec2& position, float radius, RGBAColor color){
    fillCircle(position.x, position.y, radius, color);
}

void GFX::strokeCircle(float x, float y, float radius, float thickness, RGBAColor strokeColor, RGBAColor fillColor){
    fillCircle(x, y, radius + thickness, strokeColor);
    fillCircle(x, y, radius, fillColor);
}

void GFX::strokeCircle(const Vec2& position, float radius, float thickness, RGBAColor strokeColor, RGBAColor fillColor){
    strokeCircle(position.x, position.y, radius, thickness, strokeColor, fillColor);
}

void GFX::lineCircle(float x, float y, float radius, RGBAColor color){
    DrawCircleLines(x, y, radius, color);
}

void GFX::lineCircle(const Vec2& position, float radius, RGBAColor color){
    lineCircle(position.x, position.y, radius, color);
}
