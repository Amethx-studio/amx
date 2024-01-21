#include "graphicsDevice.desktop.h"

#include <amx/data/color.h>

namespace amx {

    bool DesktopGraphicsDevice::shouldClose() {
        return glfwWindowShouldClose(window);
    }

    bool DesktopGraphicsDevice::init(std::string title) {
        if (!glfwInit()) { return -1; }
        window = glfwCreateWindow(640, 480, title.c_str(), NULL, NULL);
        if (window == nullptr) {
            glfwTerminate();
            return 0;
        }

        if (!centerWindow()) {
            return 0;
        }

        glfwMakeContextCurrent(window);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        return 1;
    }

    void DesktopGraphicsDevice::beginFrame() {
        glClear(GL_COLOR_BUFFER_BIT);
        auto bg = Color(20, 20, 20);
        glClearColor(bg.r(), bg.g(), bg.b(), bg.a());
    }

    void DesktopGraphicsDevice::endFrame() {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void DesktopGraphicsDevice::setViewport(int width, int height) {
        glfwSetWindowSize(window, width, height);
        glViewport(0, 0, width, height);
        centerWindow();
    }

    bool DesktopGraphicsDevice::centerWindow() {
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();

        if (!monitor) {
            glfwTerminate();
            return 0;
        }

        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        if (!mode) {
            glfwTerminate();
            return 0;
        }

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        int xPos = (mode->width - width) / 2;
        int yPos = (mode->height - height) / 2;

        // Set the window position
        glfwSetWindowPos(window, xPos, yPos);

        return 1;
    }

    void DesktopGraphicsDevice::dispose() {
        if (window != nullptr) {
            glfwDestroyWindow(window);
        }
        glfwTerminate();
    }

    DesktopGraphicsDevice::~DesktopGraphicsDevice() {
        dispose();
    }
}
