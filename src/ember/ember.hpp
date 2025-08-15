#pragma once
#include <raylib.h>
#include <cstdint>

#define EM_COLOR_RED RGBAColor(255, 0, 0, 255)
#define EM_COLOR_GREEN RGBAColor(0, 255, 0, 255)
#define EM_COLOR_BLUE RGBAColor(0, 0, 255, 255)
#define EM_COLOR_YELLOW RGBAColor(255, 255, 0, 255)
#define EM_COLOR_CYAN RGBAColor(0, 255, 255, 255)
#define EM_COLOR_MAGENTA RGBAColor(255, 0, 255, 255)
#define EM_COLOR_WHITE RGBAColor(255, 255, 255, 255)
#define EM_COLOR_BLACK RGBAColor(0, 0, 0, 255)
#define EM_COLOR_GRAY RGBAColor(128, 128, 128, 255)
#define EM_COLOR_ORANGE RGBAColor(255, 165, 0, 255)
#define EM_COLOR_PURPLE RGBAColor(128, 0, 128, 255)
#define EM_COLOR_BROWN RGBAColor(165, 42, 42, 255)
#define EM_COLOR_PINK RGBAColor(255, 192, 203, 255)
#define EM_COLOR_LIME RGBAColor(50, 205, 50, 255)
#define EM_COLOR_NAVY RGBAColor(0, 0, 128, 255)
#define EM_COLOR_TEAL RGBAColor(0, 128, 128, 255)
#define EM_COLOR_MAROON RGBAColor(128, 0, 0, 255)
#define EM_COLOR_OLIVE RGBAColor(128, 128, 0, 255)
#define EM_COLOR_SILVER RGBAColor(192, 192, 192, 255)
#define EM_COLOR_GOLD RGBAColor(255, 215, 0, 255)

constexpr int AntiAlias = FLAG_MSAA_4X_HINT;

class RGBAColor
{
public:
    std::uint8_t r, g, b, a;

    explicit RGBAColor() = default;
    explicit RGBAColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) : r(r), g(g), b(b), a(a) {}

    operator Color()
    {
        return Color{r, g, b, a};
    }
};











class Vec2
{
public:
    float x = 0.0f, y = 0.0f;

    explicit Vec2() = default;
    explicit Vec2(float x, float y) : x(x), y(y) {}

    inline float xy() { return x + y; }
    inline float area() { return x * y; }

    operator Vector2()
    {
        return Vector2{x, y};
    }

    Vec2 operator+(Vec2 &other)
    {
        return Vec2(x + other.x, y + other.y);
    }
    Vec2 operator-(Vec2 &other)
    {
        return Vec2(x - other.x, y - other.y);
    }
    Vec2 operator*(Vec2 &other)
    {
        return Vec2(x * other.x, y + other.y);
    }
    Vec2 operator/(Vec2 &other)
    {
        return Vec2(x / other.x, y + other.y);
    }

    void operator+=(Vec2 &other)
    {
        x += other.x;
        y += other.y;
    }
    void operator-=(Vec2 &other)
    {
        x -= other.x;
        y -= other.y;
    }
    void operator*=(Vec2 &other)
    {
        x *= other.x;
        y *= other.y;
    }
    void operator/=(Vec2 &other)
    {
        x /= other.x;
        y /= other.y;
    }
};










//   ___  ____      _ _____ ____ _____ ____  
//  / _ \| __ )    | | ____/ ___|_   _/ ___| 
// | | | |  _ \ _  | |  _|| |     | | \___ \ 
// | |_| | |_) | |_| | |__| |___  | |  ___) |
//  \___/|____/ \___/|_____\____| |_| |____/ 


class BaseObject2D
{
protected:
    float x = 0.0f;
    float y = 0.0f;
    float width = 0.0f;
    float height = 0.0f;
    Vec2 velocity = Vec2(0.0f, 0.0f);
    Vec2 origin = Vec2(0.0f, 0.0f);
    float angle = 0;

public:
    explicit BaseObject2D() = default;
    explicit BaseObject2D(float x, float y, float w, float h) : x(x), y(y), width(w), height(h) {}
    explicit BaseObject2D(Vec2 pos, Vec2 size) : BaseObject2D(pos.x, pos.y, size.x, size.y) {}

    float getX() const { return x; }
    void setX(float x_) { x = x_; }

    float getY() const { return y; }
    void setY(float y_) { y = y_; }

    float getWidth() const { return width; }
    void setWidth(float width_) { width = width_; }

    float getHeight() const { return height; }
    void setHeight(float height_) { height = height_; }

    Vec2 getVelocity() const { return velocity; }
    void setVelocity(const Vec2 &velocity_) { velocity = velocity_; }
    void setVelocity(float x, float y) { setVelocity(Vec2(x, y)); }

    Vec2 getOrigin() const { return origin; }
    void setOrigin(const Vec2 &origin_) { origin = origin_; }
    void setOrigin(float x, float y) { setOrigin(Vec2(x, y)); }

    float getAngle() const { return angle; }
    void setAngle(float angle_) { angle = angle_; }

    void rotate(float deg) { angle += deg; }
    void move(float x, float y)
    {
        velocity.x += x;
        velocity.y += y;
    }
    void move(Vec2 delta) { velocity += delta; }
};

class RectObject2D : public BaseObject2D
{
private:
    RGBAColor color = EM_COLOR_BLACK;

public:
    explicit RectObject2D() = default;
    explicit RectObject2D(float x, float y, float w, float h, RGBAColor color) : BaseObject2D(x, y, w, h), color(color) {}
    explicit RectObject2D(Vec2 pos, Vec2 size, RGBAColor color_) : RectObject2D(pos.x, pos.y, size.x, size.y, color_) {}

    RGBAColor getColor() const { return color; }
    void setColor(const RGBAColor &color_) { color = color_; }

    operator Rectangle()
    {
        return Rectangle{x, y, width, height};
    }
};









//  ___ _   _ ____  _   _ _____ 
// |_ _| \ | |  _ \| | | |_   _|
//  | ||  \| | |_) | | | | | |  
//  | || |\  |  __/| |_| | | |  
// |___|_| \_|_|    \___/  |_|  




class Input {
public:
    static const int NoKey = KEY_NULL;
    static const int Apostrophe = KEY_APOSTROPHE;
    static const int Comma = KEY_COMMA;
    static const int Minus = KEY_MINUS;
    static const int Period = KEY_PERIOD;
    static const int Slash = KEY_SLASH;
    static const int Zero = KEY_ZERO;
    static const int One = KEY_ONE;
    static const int Two = KEY_TWO;
    static const int Three = KEY_THREE;
    static const int Four = KEY_FOUR;
    static const int Five = KEY_FIVE;
    static const int Six = KEY_SIX;
    static const int Seven = KEY_SEVEN;
    static const int Eight = KEY_EIGHT;
    static const int Nine = KEY_NINE;
    static const int Semicolon = KEY_SEMICOLON;
    static const int Equal = KEY_EQUAL;
    static const int A = KEY_A;
    static const int B = KEY_B;
    static const int C = KEY_C;
    static const int D = KEY_D;
    static const int E = KEY_E;
    static const int F = KEY_F;
    static const int G = KEY_G;
    static const int H = KEY_H;
    static const int I = KEY_I;
    static const int J = KEY_J;
    static const int K = KEY_K;
    static const int L = KEY_L;
    static const int M = KEY_M;
    static const int N = KEY_N;
    static const int O = KEY_O;
    static const int P = KEY_P;
    static const int Q = KEY_Q;
    static const int R = KEY_R;
    static const int S = KEY_S;
    static const int T = KEY_T;
    static const int U = KEY_U;
    static const int V = KEY_V;
    static const int W = KEY_W;
    static const int X = KEY_X;
    static const int Y = KEY_Y;
    static const int Z = KEY_Z;
    static const int LeftBracket = KEY_LEFT_BRACKET;
    static const int Backslash = KEY_BACKSLASH;
    static const int RightBracket = KEY_RIGHT_BRACKET;
    static const int Grave = KEY_GRAVE;
    static const int Space = KEY_SPACE;
    static const int Escape = KEY_ESCAPE;
    static const int Enter = KEY_ENTER;
    static const int Tab = KEY_TAB;
    static const int Backspace = KEY_BACKSPACE;
    static const int Insert = KEY_INSERT;
    static const int Delete = KEY_DELETE;
    static const int Right = KEY_RIGHT;
    static const int Left = KEY_LEFT;
    static const int Down = KEY_DOWN;
    static const int Up = KEY_UP;
    static const int PageUp = KEY_PAGE_UP;
    static const int PageDown = KEY_PAGE_DOWN;
    static const int Home = KEY_HOME;
    static const int End = KEY_END;
    static const int CapsLock = KEY_CAPS_LOCK;
    static const int ScrollLock = KEY_SCROLL_LOCK;
    static const int NumLock = KEY_NUM_LOCK;
    static const int PrintScreen = KEY_PRINT_SCREEN;
    static const int Pause = KEY_PAUSE;
    static const int FunctionKey1 = KEY_F1;
    static const int FunctionKey2 = KEY_F2;
    static const int FunctionKey3 = KEY_F3;
    static const int FunctionKey4 = KEY_F4;
    static const int FunctionKey5 = KEY_F5;
    static const int FunctionKey6 = KEY_F6;
    static const int FunctionKey7 = KEY_F7;
    static const int FunctionKey8 = KEY_F8;
    static const int FunctionKey9 = KEY_F9;
    static const int FunctionKey10 = KEY_F10;
    static const int FunctionKey11 = KEY_F11;
    static const int FunctionKey12 = KEY_F12;
    static const int LeftShift = KEY_LEFT_SHIFT;
    static const int LeftControl = KEY_LEFT_CONTROL;
    static const int LeftAlt = KEY_LEFT_ALT;
    static const int LeftSuper = KEY_LEFT_SUPER;
    static const int LeftWin = KEY_LEFT_SUPER;
    static const int RightShift = KEY_RIGHT_SHIFT;
    static const int RightControl = KEY_RIGHT_CONTROL;
    static const int RightAlt = KEY_RIGHT_ALT;
    static const int RightSuper = KEY_RIGHT_SUPER;
    static const int RightWin = KEY_RIGHT_SUPER;
    static const int KbMenu = KEY_KB_MENU;
    static const int Kp0 = KEY_KP_0;
    static const int Kp1 = KEY_KP_1;
    static const int Kp2 = KEY_KP_2;
    static const int Kp3 = KEY_KP_3;
    static const int Kp4 = KEY_KP_4;
    static const int Kp5 = KEY_KP_5;
    static const int Kp6 = KEY_KP_6;
    static const int Kp7 = KEY_KP_7;
    static const int Kp8 = KEY_KP_8;
    static const int Kp9 = KEY_KP_9;
    static const int KpDecimal = KEY_KP_DECIMAL;
    static const int KpDivide = KEY_KP_DIVIDE;
    static const int KpMultiply = KEY_KP_MULTIPLY;
    static const int KpSubtract = KEY_KP_SUBTRACT;
    static const int KpAdd = KEY_KP_ADD;
    static const int KpEnter = KEY_KP_ENTER;
    static const int KpEqual = KEY_KP_EQUAL;
    static const int Back = KEY_BACK;
    static const int Menu = KEY_MENU;
    static const int VolumeUp = KEY_VOLUME_UP;
    static const int VolumeDown = KEY_VOLUME_DOWN;

    static bool isKeyHeld(int key);
    static bool isKeyPressed(int key);
    static bool isKeyUp(int key);
    static bool isKeyReleased(int key);

    static bool isButtonHeld(int button);
    static bool isButtonPressed(int button);
    static bool isButtonUp(int button);
    static bool isButtonReleased(int button);

    static Vec2 getPosition();
    static Vec2 getScrollXY();
    static float getScroll();

    static void hideCursor();
    static void showCursor();
    static void isCursorHidden();
};
















//   ____ ____      _    ____  _   _ ___ ____ ____  
//  / ___|  _ \    / \  |  _ \| | | |_ _/ ___/ ___| 
// | |  _| |_) |  / _ \ | |_) | |_| || | |   \___ \ 
// | |_| |  _ <  / ___ \|  __/|  _  || | |___ ___) |
//  \____|_| \_\/_/   \_\_|   |_| |_|___\____|____/ 



class GFX
{
public:
    explicit GFX() = default;

    void fillRect(float x, float y, float width, float height, RGBAColor color);
    void fillRect(const Vec2& position, const Vec2& size, RGBAColor color);
    void fillRect(RectObject2D &rect);

    void strokeRect(float x, float y, float width, float height, float thickness, RGBAColor color, RGBAColor fillColor);
    void strokeRect(const Vec2& position, const Vec2& size, float thickness, RGBAColor color, RGBAColor fillColor);

    void lineRect(float x, float y, float width, float height, RGBAColor color);
    void lineRect(const Vec2& position, const Vec2& size, RGBAColor color);

    void fillCircle(float x, float y, float radius, RGBAColor color);
    void fillCircle(const Vec2& position, float radius, RGBAColor color);

    void strokeCircle(float x, float y, float radius, float thickness, RGBAColor strokeColor, RGBAColor fillColor);
    void strokeCircle(const Vec2& position, float radius, float thickness, RGBAColor strokeColor, RGBAColor fillColor);

    void lineCircle(float x, float y, float radius, RGBAColor color);
    void lineCircle(const Vec2& position, float radius, RGBAColor color);
};















//  ____   ____ _____ _   _ _____ 
// / ___| / ___| ____| \ | | ____|
// \___ \| |   |  _| |  \| |  _|  
//  ___) | |___| |___| |\  | |___ 
// |____/ \____|_____|_| \_|_____|

class Scene
{
private:
    RGBAColor backgroundColor = RGBAColor(255, 255, 255, 255);
    int fps = 60;
    GFX gfx = GFX();

public:
    explicit Scene()
    {
        SetTargetFPS(fps);
    }

    virtual void update(float delta) {}
    virtual void draw(GFX &gfx) {}
    virtual void dispose() {}

    RGBAColor getBackgroundColor() const { return backgroundColor; }
    void setBackgroundColor(const RGBAColor &backgroundColor_) { backgroundColor = backgroundColor_; }

    int getFps() const { return fps; }
    void setFps(int fps_)
    {
        fps = fps_;
        SetTargetFPS(fps);
    }
    GFX &getGfx() { return gfx; }
};













//  __  __    _    ___ _   _ 
// |  \/  |  / \  |_ _| \ | |
// | |\/| | / _ \  | ||  \| |
// | |  | |/ ___ \ | || |\  |
// |_|  |_/_/   \_\___|_| \_|


class Ember
{
public:
    static void setInitializationFlags(int flags);
    static void initialize(const char *title, int width, int height);
    static void run(Scene &scene);
};