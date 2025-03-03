#include <containers.h>
#include <raylib.h>
#include <raymath.h>

struct window{
        int window_width;        
        int window_hight;

        Camera3D camera;
        Con_Dynamic_Array textures;
};

static struct window window_state;

void start_3d_camera()
{
        Camera3D camera = { 0 };
        camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };    
        camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };         
        camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };             
        camera.fovy = 45.0f;
        camera.projection = CAMERA_PERSPECTIVE;
        window_state.camera = camera;
}

void init_window(const char *title)
{
        window_state.window_width = 1080;
        window_state.window_hight = 720;
        window_state.textures = init_dynamic_array(sizeof(Texture2D), NULL, NULL, NULL);

        InitWindow(window_state.window_width, window_state.window_hight, title);
}

void change_window_size(int width, int hight)
{
        window_state.window_width = width;
        window_state.window_hight = hight;

        SetWindowSize(window_state.window_width, window_state.window_hight);
}

int get_window_hight()
{
        return window_state.window_hight;
}

int get_window_width()
{
        return window_state.window_width;
}

void close_window()
{
        CloseWindow();
}

bool should_close()
{
        return WindowShouldClose();
}

void begin_rendering()
{
        BeginDrawing();
        ClearBackground(SKYBLUE);
}

void end_rendering()
{
        EndDrawing();
}

void begin_3D_mode()
{
        BeginMode3D(window_state.camera);
}

void end_3D_mode()
{
        EndMode3D();
}

unsigned int load_texture(const char *path)
{
        Texture2D texture = LoadTexture(path);
        dynamic_array_insert(&texture, sizeof(Texture2D), &window_state.textures);
        return window_state.textures.Cur_Items - 1;
}

void display_texture(unsigned int texture_id)
{
        DrawTexture(*(Texture2D *)random_access_dynamic_array(texture_id, &window_state.textures), 100, 100, RAYWHITE);
}

void display_texture_with_pos(unsigned int texture_id, int x, int y)
{
        DrawTexture(*(Texture2D *)random_access_dynamic_array(texture_id, &window_state.textures), x, y, RAYWHITE);
}

void update_camera_controls()
{
    if (IsKeyDown(KEY_W)) window_state.camera.position.z -= 0.1f;
    if (IsKeyDown(KEY_S)) window_state.camera.position.z += 0.1f;
    if (IsKeyDown(KEY_A)) window_state.camera.position.x -= 0.1f;
    if (IsKeyDown(KEY_D)) window_state.camera.position.x += 0.1f;
    if (IsKeyDown(KEY_E)) window_state.camera.position.y += 0.1f;
    if (IsKeyDown(KEY_Q)) window_state.camera.position.y -= 0.1f;
    
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        Vector2 mouseDelta = GetMouseDelta();
        float cameraRotX = mouseDelta.x * 0.003f;
        float cameraRotY = mouseDelta.y * 0.003f;
        
        Vector3 direction = Vector3Subtract(window_state.camera.target, window_state.camera.position);
        
        direction = Vector3RotateByAxisAngle(direction, (Vector3){0, 1, 0}, cameraRotX);
        
        Vector3 right = Vector3CrossProduct(direction, window_state.camera.up);
        direction = Vector3RotateByAxisAngle(direction, right, cameraRotY);
        
        window_state.camera.target = Vector3Add(window_state.camera.position, direction);
    }
}
