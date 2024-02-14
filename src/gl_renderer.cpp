#include "gl_renderer.h"

// #############################################################################
//                           OpenGL Structs
// #############################################################################
struct GLContext
{
    GLuint programID;
};

// #############################################################################
//                           OpenGL Globals
// #############################################################################
static GLContext glContext;

// #############################################################################
//                           OpenGL Functions
// #############################################################################
static void APIENTRY gl_debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                        GLsizei lenght, const GLchar* message, const void* user)
{
    if (severity == GL_DEBUG_SEVERITY_LOW || 
        severity == GL_DEBUG_SEVERITY_MEDIUM ||
        severity == GL_DEBUG_SEVERITY_HIGH)
    {
        SM_ASSERT(false, "OpenGL Error %s", message);
    }
    else
    {
        SM_TRACE((char*)message);
    }
}

bool gl_init(BumpAllocator* transientStorage)
{
    load_gl_functions();

    glDebugMessageCallback(&gl_debug_callback, nullptr);

    return true;
}