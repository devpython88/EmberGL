#pragma once
#include <raylib.h>
#include <cstdint>

#define EM_COLOR_RED     EmColor(255, 0, 0, 255)
#define EM_COLOR_GREEN   EmColor(0, 255, 0, 255)
#define EM_COLOR_BLUE    EmColor(0, 0, 255, 255)
#define EM_COLOR_YELLOW  EmColor(255, 255, 0, 255)
#define EM_COLOR_CYAN    EmColor(0, 255, 255, 255)
#define EM_COLOR_MAGENTA EmColor(255, 0, 255, 255)
#define EM_COLOR_WHITE   EmColor(255, 255, 255, 255)
#define EM_COLOR_BLACK   EmColor(0, 0, 0, 255)
#define EM_COLOR_GRAY    EmColor(128, 128, 128, 255)
#define EM_COLOR_ORANGE  EmColor(255, 165, 0, 255)
#define EM_COLOR_PURPLE  EmColor(128, 0, 128, 255)
#define EM_COLOR_BROWN   EmColor(165, 42, 42, 255)
#define EM_COLOR_PINK    EmColor(255, 192, 203, 255)
#define EM_COLOR_LIME    EmColor(50, 205, 50, 255)
#define EM_COLOR_NAVY    EmColor(0, 0, 128, 255)
#define EM_COLOR_TEAL    EmColor(0, 128, 128, 255)
#define EM_COLOR_MAROON  EmColor(128, 0, 0, 255)
#define EM_COLOR_OLIVE   EmColor(128, 128, 0, 255)
#define EM_COLOR_SILVER  EmColor(192, 192, 192, 255)
#define EM_COLOR_GOLD    EmColor(255, 215, 0, 255)

/* COLOR CLASS */

class EmColor {
    public:
    std::uint8_t r, g, b, a;

    explicit EmColor() = default;
    explicit EmColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a): r(r), g(g), b(b), a(a){}

    operator Color(){
        return Color{r, g, b, a};
    }
};

/* VECTOR CLASSES  */

class EmVector2 {
    public:
    float x = 0.0f, y = 0.0f;

    explicit EmVector2() = default;
    explicit EmVector2(float x, float y): x(x), y(y){}

    inline float xy(){ return x + y; }
    inline float area(){ return x * y; }

    operator Vector2(){
        return Vector2{x, y};
    }
};


class EmDim2 {
    public:
    float width, height;

    explicit EmDim2() = default;
    explicit EmDim2(float width, float height): width(width), height(height){}

    inline float area(){ return width * height; }

    operator Vector2(){
        return Vector2{width, height};
    }
};

/* EMBER SCENE CLASS */

/* EMBER GRAPHICS CLASS */

class EmGFX {
    public:

    explicit EmGFX() = default;

    void fillRect(float x, float y, float width, float height, EmColor color);
    void fillRect(EmVector2 position, EmDim2 size, EmColor color);
};


class EmScene {
    private:

    EmColor m_BackgroundColor = EmColor(255, 255, 255, 255);
    int m_Fps = 60;
    EmGFX m_Gfx = EmGFX();

    public:

    explicit EmScene(){
        SetTargetFPS(m_Fps);
    }

    virtual void update(float delta) {}
    virtual void draw(EmGFX& gfx) {}
    virtual void dispose() {}

    EmColor backgroundColor() const { return m_BackgroundColor; }
    void setBackgroundColor(const EmColor &backgroundColor_) { m_BackgroundColor = backgroundColor_; }

    int fps() const { return m_Fps; }
    void setFps(int fps_) { m_Fps = fps_; SetTargetFPS(m_Fps); }
    EmGFX& gfx() { return m_Gfx; }
};


/* EMBER MAIN CLASS */

class Ember {
    public:

    static void initialize(const char* title, int width, int height);
    static void run(EmScene& scene);
};