#pragma once
#include "ImGui/imgui.h"
#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#include <ctime>
#include <random>

#define get_array_size(array)    (sizeof(array) / sizeof(array[0]))

int random_int(int min, int max)
{
    int range = max - min;
    static bool seed = false;
    if (!seed)
    {
        srand((unsigned int)time(0));
        seed = true;
    }
    return rand() % range + min;
}

float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) +
        pow(y2 - y1, 2) * 1.0);
}

struct Point {
    ImVec2 point;
    float speedMod;
};

struct Points {
    Point point1;
    Point point2;
};
// POINTS COUNT
// POINTS COUNT
// POINTS COUNT
// POINTS COUNT

static Point points[100];

// POINTS COUNT -----


void dank_polys() {
    static int windowWidth = 900;
    static int windowHeight = 600;
    static bool init = false;
    if (!init)
        for (int i = 0; i < get_array_size(points); ++i) {
            points[i].point.x = random_int(1, windowWidth);
            points[i].point.y = random_int(1, windowHeight);
            points[i].speedMod = random_int(10, 80) / 100.f;
        }
    init = true;

    static bool aids = false;
    static bool aids2 = false;
    static int hmmmm = 2;
    static clock_t timer = 0;

    if (clock() - timer > 20) {
        for (int i = 0; i < get_array_size(points); ++i) {

            if (points[i].point.x < -10.f || points[i].point.x  > windowWidth + 10.f) {
                points[i].point.x = (random_int(1000, 3000) > 1400) ? -5.f : windowWidth + 5.f;
                points[i].speedMod = random_int(50, 150) / 100.f;
            }

            if (points[i].point.y < -10.f || points[i].point.y > windowHeight + 10.f) {
                points[i].point.y = (random_int(1000, 3000) > 1400) ? 5.f : windowHeight + 5.f;
                points[i].speedMod = random_int(50, 150) / 100.f;
            }

            if (aids2) {
                if (aids) {
                    points[i].point.x += points[i].speedMod;
                    points[i].point.y += points[i].speedMod;
                }
                else if (!aids) {
                    points[i].point.x -= points[i].speedMod;
                    points[i].point.y -= points[i].speedMod;
                }
            }
            else {
                if (aids) {
                    points[i].point.x += points[i].speedMod;
                    points[i].point.y -= points[i].speedMod;
                }
                else if (!aids) {
                    points[i].point.x -= points[i].speedMod;
                    points[i].point.y += points[i].speedMod;
                }
            }
            hmmmm++;
            if (hmmmm > 10)
                hmmmm = 2;
            aids = !aids;
            if (aids)
                aids2 = !aids2;
            timer = clock();
        }
    }
}

void dank_polys2() {
    static int windowWidth = 400;
    static int windowHeight = 400;
    static bool init = false;
    if (!init)
        for (int i = 0; i < get_array_size(points); ++i) {
            points[i].point.x = random_int(1, windowWidth);
            points[i].point.y = random_int(1, windowHeight);
            points[i].speedMod = random_int(10, 80) / 100.f;
        }
    init = true;

    static bool aids = false;
    static bool aids2 = false;
    static int hmmmm = 2;
    static clock_t timer = 0;

    if (clock() - timer > 20) {
        for (int i = 0; i < get_array_size(points); ++i) {

            if (points[i].point.x < -10.f || points[i].point.x  > windowWidth + 10.f) {
                points[i].point.x = (random_int(1000, 3000) > 1400) ? -5.f : windowWidth + 5.f;
                points[i].speedMod = random_int(50, 150) / 100.f;
            }

            if (points[i].point.y < -10.f || points[i].point.y > windowHeight + 10.f) {
                points[i].point.y = (random_int(1000, 3000) > 1400) ? 5.f : windowHeight + 5.f;
                points[i].speedMod = random_int(50, 150) / 100.f;
            }

            if (aids2) {
                if (aids) {
                    points[i].point.x += points[i].speedMod;
                    points[i].point.y += points[i].speedMod;
                }
                else if (!aids) {
                    points[i].point.x -= points[i].speedMod;
                    points[i].point.y -= points[i].speedMod;
                }
            }
            else {
                if (aids) {
                    points[i].point.x += points[i].speedMod;
                    points[i].point.y -= points[i].speedMod;
                }
                else if (!aids) {
                    points[i].point.x -= points[i].speedMod;
                    points[i].point.y += points[i].speedMod;
                }
            }
            hmmmm++;
            if (hmmmm > 10)
                hmmmm = 2;
            aids = !aids;
            if (aids)
                aids2 = !aids2;
            timer = clock();
        }
    }
}