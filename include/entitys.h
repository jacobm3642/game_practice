#ifndef ENTITYS_H
#define ENTITYS_H

typedef void Object_func(int object_id);

typedef struct Object {
        int x;
        int y;
        unsigned int tex_id;
        unsigned int obj_id;
        Object_func *update;
} Object;

void display_object(Object obj);
Object create_object(const char *path);
Object create_object_at(const char *path, int x, int y);
void set_obj_postion(Object *obj, int x, int y);
void move_obj_x(Object *obj, int x);
void move_obj_y(Object *obj, int y);
Object *get_obj(int object_id);
void basic_move(int object_id);

#endif // !ENTITYS_H
