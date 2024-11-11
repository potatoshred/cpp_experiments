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
        bool reverse{false};
        const Direction *facing;

    public:
        PoseHandler(const Pose &pose) noexcept;
        PoseHandler(const PoseHandler &) = delete;
        PoseHandler &operator=(const PoseHandler &) = delete;
        ~PoseHandler();

    public:
        bool IsReverse() const noexcept;
        bool IsFast() const noexcept;
        void Reverse() noexcept;
        void Fast() noexcept;

        void Forward() noexcept;
        void Backward() noexcept;
        void TurnLeft() noexcept;
        void TurnRight() noexcept;
        Pose Query() const noexcept;
    };

} // namespace adas
