#pragma once

#include "ActionGroup.hpp"
#include "PoseHandler.hpp"
#include <functional>

namespace adas
{
    class ReverseCommand final
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
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
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
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
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            const auto action = poseHandler.IsReverse()
                                    ? ActionType::BACKWARD_1_STEP_ACTION
                                    : ActionType::FORWARD_1_STEP_ACTION;
            if (poseHandler.IsFast()) {
                actionGroup.PushAction(action);
            }
            actionGroup.PushAction(action);

            return actionGroup;
        };
    };

    class TurnLeftCommand final
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;

            if (poseHandler.IsFast()) {
                const auto action = poseHandler.IsReverse()
                                        ? ActionType::BACKWARD_1_STEP_ACTION
                                        : ActionType::FORWARD_1_STEP_ACTION;
                actionGroup.PushAction(action);
            }
            const auto action = poseHandler.IsReverse()
                                    ? ActionType::REVERSE_TURNLEFT_ACTION
                                    : ActionType::TURNLEFT_ACTION;
            actionGroup.PushAction(action);

            return actionGroup;
        };
    };
    class TurnRightCommand final
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;

            if (poseHandler.IsFast()) {
                const auto action = poseHandler.IsReverse()
                                        ? ActionType::BACKWARD_1_STEP_ACTION
                                        : ActionType::FORWARD_1_STEP_ACTION;
                actionGroup.PushAction(action);
            }
            const auto action = poseHandler.IsReverse()
                                    ? ActionType::REVERSE_TURNRIGHT_ACTION
                                    : ActionType::TURNRIGHT_ACTION;
            actionGroup.PushAction(action);

            return actionGroup;
        };
    };

    class TurnRoundCommand final
    {
    public:
        ActionGroup operator()(PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            if (poseHandler.IsReverse()) {
                // do nothing
            } else {
                const auto actionF = ActionType::FORWARD_1_STEP_ACTION;
                const auto actionL = ActionType::TURNLEFT_ACTION;
                if (poseHandler.IsFast()) {
                    actionGroup.PushAction(actionF);
                }
                actionGroup.PushAction(actionL);
                actionGroup.PushAction(actionF);
                actionGroup.PushAction(actionL);
            }

            return actionGroup;
        };
    };
}