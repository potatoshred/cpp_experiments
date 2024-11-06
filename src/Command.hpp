#pragma once

#include "PoseHandler.hpp"
#include <functional>

namespace adas
{
    class FastCommand final
    {
    public:
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept {
            poseHandler.Fast();
        };
    };

    class MoveCommand final
    {
    public:
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept {
            if (poseHandler.IsFast()) {
                poseHandler.Move();
            }
            poseHandler.Move();
        };
    };

    class TurnLeftCommand final
    {
    public:
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept {
            if (poseHandler.IsFast()) {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        };
    };
    class TurnRightCommand final
    {
    public:
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept {
            if (poseHandler.IsFast()) {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        };
    };
}