#include "main_lib.h"
#include "platform.h"

#define APIENTRY
#include "glcorearb.h"

#ifdef _WIN32
#include "win32_platform.cpp"
#endif

#include "gl_renderer.cpp"


int main() 
{
    BumpAllocator transientStorage = make_bump_allocator(MB(50));
    platform_create_window(1200, 720, "Test");

    gl_init(&transientStorage);

    while (running)
    {
        // Update
        platform_update_window();

    }
    return 0;
}