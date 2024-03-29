#pragma once

enum class Color
{
    BG_Black = 40,
    BG_Red,
    BG_Green,
    BG_Yellow,
    BG_Blue,
    BG_Magenta,
    BG_Cyan,
    BG_White,

    FG_Black = 30,
    FG_Red,
    FG_Green,
    FG_Yellow,
    FG_Blue,
    FG_Magenta,
    FG_Cyan,
    FG_White,

    Reset = 0
};

class Console
{
public:
    static void init(int start_row, int start_col);

    static void hide_cursor();
    static void show_cursor();

    static void set_cursor(int row, int col);

    static void set_color(Color color);
    static void set_color_fg256(int color);
    static void set_color_bg256(int color);
    static void reset_color();

    static void clear_screen();
};
