#pragma once

#include "PoseHandler.hpp"

namespace adas
{
    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
    };
    class FastCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            poseHandler.Fast();
        }
    };

    class MoveCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            if (poseHandler.isFast()) {
                poseHandler.Move();
            }
            poseHandler.Move();
        }
    };

    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            if (poseHandler.isFast()) {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        }
    };
    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            if (poseHandler.isFast()) {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        }
    };
}