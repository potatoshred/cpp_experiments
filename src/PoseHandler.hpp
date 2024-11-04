#pragma once

#include "Executor.hpp"

namespace adas
{
    class PoseHandler final
    {
    private:
        Pose pose;
        bool fast{false};

    public:
        PoseHandler(const Pose &pose) noexcept;
        PoseHandler(const PoseHandler &) = delete;
        PoseHandler &operator=(const PoseHandler &) = delete;
        ~PoseHandler();

    public:
        bool isFast() const noexcept;
        void Fast() noexcept;
        void Move() noexcept;
        void TurnLeft() noexcept;
        void TurnRight() noexcept;
        Pose Query() const noexcept;
    };

} // namespace adas
