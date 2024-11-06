#pragma once

#include "PoseHandler.hpp"
#include <functional>

namespace adas
{
    class ReverseCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Reverse();
        };
    };

    class FastCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Fast();
        };
    };

    class MoveCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast()) {
                if (poseHandler.IsReverse()) {
                    poseHandler.Backward();
                } else {
                    poseHandler.Forward();
                }
            }

            if (poseHandler.IsReverse()) {
                poseHandler.Backward();
            } else {
                poseHandler.Forward();
            }
        };
    };

    class TurnLeftCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast()) {
                if (poseHandler.IsReverse()) {
                    poseHandler.Backward();
                } else {
                    poseHandler.Forward();
                }
            }

            if (poseHandler.IsReverse()) {
                poseHandler.TurnRight();
            } else {
                poseHandler.TurnLeft();
            }
        };
    };
    class TurnRightCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast()) {
                if (poseHandler.IsReverse()) {
                    poseHandler.Backward();
                } else {
                    poseHandler.Forward();
                }
            }

            if (poseHandler.IsReverse()) {
                poseHandler.TurnLeft();
            } else {
                poseHandler.TurnRight();
            }
        };
    };
}