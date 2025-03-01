#include <platform_layer.h>
#include <containers.h>
#include <entitys.h>

void main_loop()
{
//        Object player = create_object("./assets/chars/Characters_128x128/V1.0/40.png");
        start_3d_camera();
        begin_3D_mode();


        while (!should_close()) {
                load_keys();

                begin_rendering();
                
//                display_object(player);
                
                end_rendering();
        }
        end_3D_mode();
}

int main()
{
        init_window("basic game window");
        
        main_loop();
        
        close_window();
        return 0;
}
