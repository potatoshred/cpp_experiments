#pragma once

#include "CmderOrchestrator.hpp"

namespace adas
{
    class NormalOrchestrator : public CmderOrchestrator
    {
    public:
        ActionGroup Move(const PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            actionGroup.PushAction(GetStepAction(poseHandler));
            return actionGroup;
        }
        ActionGroup TurnLeft(const PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            const auto action = poseHandler.IsReverse()
                                    ? ActionType::REVERSE_TURNLEFT_ACTION
                                    : ActionType::TURNLEFT_ACTION;
            actionGroup.PushAction(action);
            return actionGroup;
        }
        ActionGroup TurnRight(const PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            const auto action = poseHandler.IsReverse()
                                    ? ActionType::REVERSE_TURNRIGHT_ACTION
                                    : ActionType::TURNRIGHT_ACTION;
            actionGroup.PushAction(action);
            return actionGroup;
        }
        ActionGroup TurnRound(const PoseHandler &poseHandler) const noexcept
        {
            ActionGroup actionGroup;
            if (poseHandler.IsReverse()) {
                // do nothing
            } else {
                const auto actionF = ActionType::FORWARD_1_STEP_ACTION;
                const auto actionL = ActionType::TURNLEFT_ACTION;

                actionGroup += OnFast(poseHandler);

                actionGroup.PushAction(actionL);
                actionGroup.PushAction(actionF);
                actionGroup.PushAction(actionL);
            }

            return actionGroup;
        }

    protected:
        ActionType GetStepAction(const PoseHandler &poseHandler) const noexcept
        {
            return poseHandler.IsReverse()
                       ? ActionType::BACKWARD_1_STEP_ACTION
                       : ActionType::FORWARD_1_STEP_ACTION;
        }

        ActionGroup OnFast(const PoseHandler &poseHandler) const noexcept
        {
            return poseHandler.IsFast()
                       ? ActionGroup({GetStepAction(poseHandler)})
                       : ActionGroup();
        }
    };

} // namespace adas
