#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::~PoseHandler() {}
    PoseHandler::PoseHandler(const Pose &pose) noexcept : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)) {}

    bool PoseHandler::IsReverse() const noexcept
    {
        return reverse;
    }
    void PoseHandler::Reverse() noexcept
    {
        reverse = !reverse;
    }
    bool PoseHandler::IsFast() const noexcept
    {
        return fast;
    }
    void PoseHandler::Fast() noexcept
    {
        fast = !fast;
    }

    Pose PoseHandler::Query() const noexcept
    {
        return {point.GetX(), point.GetY(), facing->GetHeading()};
    }

    void PoseHandler::Forward() noexcept
    {
        point += facing->Move();
    }

    void PoseHandler::Backward() noexcept
    {
        point -= facing->Move();
    }

    void PoseHandler::TurnLeft() noexcept
    {
        facing = &(facing->LeftOne());
    }

    void PoseHandler::TurnRight() noexcept
    {
        facing = &(facing->RightOne());
    }
} // namespace adas