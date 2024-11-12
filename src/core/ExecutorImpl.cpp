#include "ExecutorImpl.hpp"
// #include "Command.hpp"
// #include <memory>
// #include <new>
// #include <unordered_map>
#include "Singleton.hpp"
#include "cmder/CmderFactory.hpp"
#include <algorithm>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {};

    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }

    Executor *Executor::NewExecutor(const Pose &pose, const ExecutorType executorType) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose); // 需要c++17
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
        std::for_each(cmders.begin(), cmders.end(),
                      [this](const Cmder &cmder) noexcept { cmder(poseHandler).DoOperate(poseHandler); });
    };

} // namespace adas
