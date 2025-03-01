#include <containers.h>
#include <math.h>
#include <platform_layer.h>
#include <entitys.h>
#include <stdbool.h>
#include <stdio.h>

struct Objects{
        bool set;
        Con_Dynamic_Array object_set;
};

static struct Objects objects = {false};

Object create_object(const char *path)
{
        if (!objects.set) {
                objects.object_set = init_dynamic_array(sizeof(Object),NULL , NULL, NULL);
                objects.set = true;
        }
        Object new_obj = {0, 0, load_texture(path), 0, NULL};
        dynamic_array_insert(&new_obj, sizeof(Object), &objects.object_set);
        new_obj.obj_id = objects.object_set.Cur_Items - 1;
        return new_obj;
}

void display_object(Object obj)
{
        Object *obj_by_ref = get_obj(obj.obj_id);
        if (obj.update != NULL) {
                obj.update(obj_by_ref->obj_id);
        }
        display_texture_with_pos(obj.tex_id, obj_by_ref->y, obj_by_ref->x);
}

void set_obj_postion(Object *obj, int x, int y)
{
        obj->x = x;
        obj->y = y;
}

void move_obj_x(Object *obj, int x)
{
        obj->x += x;
}

void move_obj_y(Object *obj, int y)
{
        obj->y += y;
}

Object create_object_at(const char *path, int x, int y)
{
        Object obj = create_object(path);
        set_obj_postion(&obj, x, y);
        return obj;
}

Object *get_obj(int object_id)
{
        return (Object *)random_access_dynamic_array(object_id, &objects.object_set);
}

void basic_move(int object_id)
{
        Object *obj = get_obj(object_id);
        if (is_pressed('w')) {
                move_obj_x(obj, -5);
        }
        if (is_pressed('s')) {
                move_obj_x(obj, 5);
        }
        if (is_pressed('d')) {
                move_obj_y(obj, 5);
        }
        if (is_pressed('a')) {
                move_obj_y(obj, -5);
        }
}
