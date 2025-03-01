#include <containers.h>
#include <raylib.h>

struct key_input_state {
        char key_pressed[32];
};

static struct key_input_state key_input;

bool is_pressed(char key)
{
        int byte = key/8;
        char index = key%8;
        char char_mask = 0b0000001;
        char_mask = char_mask << index;
        if ((key_input.key_pressed[byte] & char_mask) != 0){
                return true;
        }
        return false;
}

void clear_key_state()
{
        for (int i = 0; i < 32; i++) {
                key_input.key_pressed[i] = 0;
        }
}

void set_key_true(int key)
{
        int byte = key/8;
        char index = key%8;
        char char_mask = 0b0000001;
        char_mask = char_mask << index;
        key_input.key_pressed[byte] = key_input.key_pressed[byte] | char_mask;
}

void set_key_false(int key)
{
        int byte = key/8;
        char index = key%8;
        char char_mask = 0b0000001;
        char_mask = char_mask << index;
        key_input.key_pressed[byte] = key_input.key_pressed[byte] & ~char_mask;
}

void load_keys()
{
        int key;

        clear_key_state();

        while ((key = GetCharPressed()) != 0) {
                if (key > 256) {
                        continue;
                }
                set_key_true(key);
        }
}
