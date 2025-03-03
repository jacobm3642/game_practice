#include <platform_layer.h>
#include <containers.h>
#include <entitys.h>

void main_loop()
{
//        Object player = create_object("./assets/chars/Characters_128x128/V1.0/40.png");
        start_3d_camera();

        while (!should_close()) {
                load_keys();

                begin_rendering();
                
                begin_3D_mode();

//                display_object(player);
                
                end_3D_mode();
                
                end_rendering();
        }
}

int main()
{
        init_window("basic game window");
        
        main_loop();
        
        close_window();
        return 0;
}
