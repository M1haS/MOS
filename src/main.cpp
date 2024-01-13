#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

int main()
{
    glfwInit();

    /* Window config */
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(
        800, 600, "My Vulkan App", nullptr, nullptr
    );

    /* Main loop */
    while (!glfwWindowShouldClose(window))
        glfwPollEvents();

    /* Clean up */
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}