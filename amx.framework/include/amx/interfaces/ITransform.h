#pragma once

#include "../core.h"
#include "../data/math.h"

namespace amx {
    class AMX_API ITransform {
        public:
            /// @brief Constructor for the ITransform interface
            ITransform() {
                _scale = {1, 1, 1};
            }
            /// @brief Position values
            /// @return Position as a vector 3
            vec3 position() const;
            /// @brief Rotation values
            /// @return Rotation as vector 3 in degrees
            vec3 rotation() const;
            /// @brief Scale values
            /// @return Scale as vector 3
            vec3 scale() const;
            /// @brief Set the position of the entity
            /// @param x X position
            /// @param y Y position
            void setPosition(float x, float y);
            /// @brief Move the entity
            /// @param x X translation value
            /// @param y Y translation value
            void move(float x, float y);
            /// @brief Set the depth of the entity
            /// @param z Depth value
            void setDepth(float depth);
            /// @brief Set the scale of the entity
            /// @param scale Scale value where 1 is the default
            void setScale(float scale);
            /// @brief Set the scale of the entity
            /// @param scaleX X scale value where 1 is the default
            /// @param scaleY Y scale value where 1 is the default
            /// @param scaleZ Z scale value where 1 is the default
            void setScale(float scaleX, float scaleY, float scaleZ);
            /// @brief Increase the scale of the entity
            /// @param scale Scale value to icrease by
            void increaseScale(float scale);
            /// @brief Increase the scale of the entity
            /// @param scaleX X scale to increase by
            /// @param scaleY Y scale to increase by
            /// @param scaleZ Z scale to increase by
            void increaseScale(float scaleX, float scaleY, float scaleZ);
            /// @brief Modify the pitch value
            /// @param pitch Angle in degrees to rotate X axis
            void rotatePitch(float pitch);
            /// @brief Modify the yaw value
            /// @param yaw Angle in degrees to rotate Y axis
            void rotateYaw(float yaw);
            /// @brief Modify the roll value
            /// @param roll Angle in degrees to rotate Z axis
            void rotateRoll(float roll);
            /// @brief Modify the rotation values
            /// @param pitch Angle in degrees to rotate on the X axis
            /// @param yaw Angle in degrees to rotate on the Y axis
            /// @param roll Angle in degrees to rotate on the Z axis
            void rotate(float pitch, float yaw, float roll);

        protected:
            /// @brief Position of the entity
            vec3 _position;
            /// @brief Rotation in radians of the entity
            vec3 _rotation;
            /// @brief Scale of the entity
            vec3 _scale;
    };
}