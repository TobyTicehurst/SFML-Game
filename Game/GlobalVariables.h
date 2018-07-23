#pragma once
#include <math.h> 

static const float INITIAL_CAMERA_HEIGHT = 1024.0f;
static const int INITIAL_WINDOW_HEIGHT = 1024;
static const int PIXELS_PER_TILE = 256;
// world size is 16 as this will be the chunk size if chunks are used
static const int WORLD_SIZE = 16;
//1.73205080756888
static const double ROOT3 = (round(1.73205080756888 * PIXELS_PER_TILE * WORLD_SIZE) / (PIXELS_PER_TILE * WORLD_SIZE));
static const int SCROLL_SPEED = 10;
