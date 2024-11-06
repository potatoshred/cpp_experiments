#include "ExecutorImpl.hpp"
#include "Command.hpp"
#include <memory>
#include <new>
#include <unordered_map>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {};

    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose); // 需要c++17
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        std::unordered_map<char, std::function<void(PoseHandler & PoseHandler)>> cmdMap{
            {'M', MoveCommand()},
            {'L', TurnLeftCommand()},
            {'R', TurnRightCommand()},
            {'F', FastCommand()},
        };

        for (const auto cmd : commands) {
            const auto it = cmdMap.find(cmd);

            if (it != cmdMap.end()) {
                it->second(poseHandler);
            }
        }
    };

} // namespace adas
