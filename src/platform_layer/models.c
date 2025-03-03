#include <raylib.h>
#include <containers.h>
#include <stdbool.h>

typedef struct Model_Metadata {
        Model model;
        Vector3 position;
        Vector3 rotationAxis;
        Vector3 scale;
        float rotationAngle;
        Color color;
} Model_Metadata;

struct Models{
        bool init;
        Con_Dynamic_Array models;
};

static struct Models model_store = {false};

void init_model_store()
{
        model_store.models = init_dynamic_array(sizeof(Model_Metadata), NULL, NULL, NULL);
        model_store.init = true;
}

void draw_model(Model model, Vector3 position, Vector3 scale, Vector3 rotationAxis, float rotationAngle, Color tint)
{
        DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
}

Model load_model(const char *path)
{
        if (!model_store.init) init_model_store();
        return LoadModel(path);
}

Model load_model_with_texture(const char *modelPath, const char *texturePath)
{
        if (!model_store.init) init_model_store();
        Model model = LoadModel(modelPath);
        Texture2D texture = LoadTexture(texturePath);
        SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
        return model;
}

Model create_cube(float width, float height, float length, Color color)
{
        if (!model_store.init) init_model_store();
        Model cube = LoadModelFromMesh(GenMeshCube(width, height, length));
        cube.materials[0].maps[MATERIAL_MAP_DIFFUSE].color = color;
        return cube;
}

