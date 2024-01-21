#include "amx/interfaces/ITransform.h"

namespace amx {
    vec3 ITransform::position() const {
        return _position;
    }

    vec3 ITransform::rotation() const {
        return _rotation;
    }

    vec3 ITransform::scale() const {
        return _scale;
    }

    void ITransform::setPosition(float x, float y) {
        _position.x = x;
        _position.y = y;
    }

    void ITransform::move(float x, float y) {
        _position.x += x;
        _position.y += y;
    }

    void ITransform::setDepth(float depth) {
        _position.z = depth;
    }

    void ITransform::setScale(float scale) {
        _scale = {scale, scale, scale};
    }

    void ITransform::setScale(float scaleX, float scaleY, float scaleZ) {
        _scale = {scaleX, scaleY, scaleZ};
    }

    void ITransform::increaseScale(float scale) {
        _scale.x += scale;
        _scale.y += scale;
        _scale.z += scale;
    }

    void ITransform::increaseScale(float scaleX, float scaleY, float scaleZ) {
        _scale.x += scaleX;
        _scale.y += scaleY;
        _scale.z += scaleZ;
    }

    void ITransform::rotatePitch(float pitch) {
        _rotation.x += degToRad(pitch);
    }

    void ITransform::rotateYaw(float yaw) {
        _rotation.y += degToRad(yaw);
    }

    void ITransform::rotateRoll(float roll) {
        _rotation.z += degToRad(roll);
    }

    void ITransform::rotate(float pitch, float yaw, float roll) {
        _rotation.x += degToRad(pitch);
        _rotation.y += degToRad(yaw);
        _rotation.z += degToRad(roll);
    }
}