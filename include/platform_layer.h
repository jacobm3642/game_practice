#ifndef PLATFORM_LAYER_H
#define PLATFORM_LAYER_H
#include <stdbool.h>

// window.c 
// these are the window related funtions
void init_window(const char *title);
bool should_close();
void close_window();
void display_texture(unsigned int texture_id);
void display_texture_with_pos(unsigned int texture_id, int x, int y);
void begin_rendering();
void end_rendering();
unsigned int load_texture(const char *path);
void change_window_size(int width, int hight);
void begin_3D_mode();
void end_3D_mode();
int get_window_width();
int get_window_hight();
void start_3d_camera();

// inputs.c
// these are the input related funtions
void load_keys(); 
bool is_pressed(char key);

#endif // !PLATFORM_LAYER_H
