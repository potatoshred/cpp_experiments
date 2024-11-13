#pragma once

#include "CmderOrchestrator.hpp"
#include "core/PoseHandler.hpp"
#include <functional>

namespace adas
{
    class ReverseCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = ActionType::BE_REVERSE_ACTION;
            actionGroup.PushAction(action);

            return actionGroup;
        };
    };

    class FastCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = ActionType::BE_FAST_ACTION;
            actionGroup.PushAction(action);

            return actionGroup;
        };
    };

    class MoveCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            return orchestrator.Move(poseHandler);
        };
    };

    class TurnLeftCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            return orchestrator.TurnLeft(poseHandler);
        };
    };
    class TurnRightCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            return orchestrator.TurnRight(poseHandler);
        };
    };

    class TurnRoundCommand final
    {
    public:
        ActionGroup operator()(const PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) const noexcept
        {
            return orchestrator.TurnRound(poseHandler);
        };
    };
}