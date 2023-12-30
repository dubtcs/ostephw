
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VEC_MIN_SIZE 5
#define VEC_DOWNSIZE_TOLERANCE 0.25f
#define VEC_UPSIZE_VALUE 2

struct vect
{
    int length;
    int max;
    int* data;
};
typedef struct vect vect;

vect* vect_create()
{
    vect* v = (vect*)malloc(sizeof(vect));
    v->data = (int*)calloc(VEC_MIN_SIZE, sizeof(int)); // init to 0
    v->max = VEC_MIN_SIZE;
    v->length = 0;
    return v;
}

bool vec_push(vect* v, int val)
{
    if(v->length >= v->max)
    {
        v->max *= VEC_UPSIZE_VALUE;
        v->data = (int*)realloc(v->data, (v->max * sizeof(int)));
    }
    v->data[v->length++] = val;
    return true;
}

bool vec_pop(vect* v)
{
    if(v->length > 0)
    {
        v->length--;
        if(v->length <= ((float)(v->max) * VEC_DOWNSIZE_TOLERANCE))
        {
            if(v->length >= VEC_MIN_SIZE) // keep it minimum
            {
                v->max = (int)((float)(v->max) * 0.5f);
                v->data = (int*)realloc(v->data, v->max * sizeof(int));
            }
        }
        return true;
    }
    return false;
}

int vec_at(vect* v, int index)
{
    if(index < (v->length))
    {
        return v->data[index];
    }
    return 0;
}

bool vec_free(vect* v)
{
    free(v->data);
    free(v);
    return true;
}

int main(int argc, char* argv[])
{
    vect* v = vect_create();
    printf("Length: %d, Max: %d\n", v->length, v->max);

    // pushing values
    for(int i = 0; i < 25; i++)
    {
        vec_push(v, (i * 2));
        printf("Append: %d\n", vec_at(v, i));
    }
    printf("Length: %d, Max: %d\n", v->length, v->max);

    // pop and check resizing
    for(int i = 0; i < 30; i++)
    {
        vec_pop(v);
    }
    printf("Length: %d, Max: %d\n", v->length, v->max);

    vec_free(v);
    return EXIT_SUCCESS;
}
