#pragma once

#include "Direction.hpp"
#include "Executor.hpp"

namespace adas
{
    class PoseHandler final
    {
    private:
        Point point;
        bool fast{false};
        const Direction *facing;

    public:
        PoseHandler(const Pose &pose) noexcept;
        PoseHandler(const PoseHandler &) = delete;
        PoseHandler &operator=(const PoseHandler &) = delete;
        ~PoseHandler();

    public:
        bool IsFast() const noexcept;
        void Fast() noexcept;
        void Move() noexcept;
        void TurnLeft() noexcept;
        void TurnRight() noexcept;
        Pose Query() const noexcept;
    };

} // namespace adas
