#include "ExecutorImpl.hpp"
// #include "Command.hpp"
// #include <memory>
// #include <new>
// #include <unordered_map>
#include "Singleton.hpp"
#include "cmder/BusOrchestrator.hpp"
#include "cmder/CmderFactory.hpp"
#include "cmder/NormalOrchestrator.hpp"
#include "cmder/SportsCarOrchestrator.hpp"

#include <algorithm>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose, CmderOrchestrator *orchestrator) noexcept : poseHandler(pose), orchestrator(orchestrator) {};

    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }

    Executor *Executor::NewExecutor(const Pose &pose, const ExecutorType executorType) noexcept
    {
        CmderOrchestrator *orchestrator = nullptr;
        switch (executorType) {
        case ExecutorType::NORMAL: {
            orchestrator = new (std::nothrow) NormalOrchestrator();
            break;
        }
        case ExecutorType::SPORTS_CAR: {
            orchestrator = new (std::nothrow) SportsCarOrchestrator();
            break;
        }
        case ExecutorType::BUS: {
            orchestrator = new (std::nothrow) BusOrchestrator();
            break;
        }
        default:
            break;
        }
        return new (std::nothrow) ExecutorImpl(pose, orchestrator); // 需要c++17
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
        std::for_each(cmders.begin(), cmders.end(),
                      [this](const Cmder &cmder) noexcept { cmder(poseHandler, *orchestrator).DoOperate(poseHandler); });
    };

} // namespace adas
