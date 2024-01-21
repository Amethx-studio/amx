#include "amx/graphics/graphicsDevice.h"

#ifdef WINDOWS
    #include "platforms/desktop/graphics/graphicsDevice.desktop.h"
#endif

namespace amx {

    GraphicsDevice::GraphicsDevice() {
#ifdef WINDOWS
        _internal = std::make_unique<DesktopGraphicsDevice>();
#endif
    }

    void GraphicsDevice::setViewport(int width, int height) {
        _internal->setViewport(width, height);
    }

    GraphicsDevice::~GraphicsDevice() {
        _internal->dispose();
    }
}