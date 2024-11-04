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
        std::unordered_map<char, std::unique_ptr<ICommand>> cmdMap;
        cmdMap.emplace('M', std::make_unique<MoveCommand>());
        cmdMap.emplace('L', std::make_unique<TurnLeftCommand>());
        cmdMap.emplace('R', std::make_unique<TurnRightCommand>());
        cmdMap.emplace('F', std::make_unique<FastCommand>());

        for (const auto cmd : commands) {
            const auto it = cmdMap.find(cmd);

            if (it != cmdMap.end()) {
                it->second->DoOperate(poseHandler);
            }
        }
    };

} // namespace adas
