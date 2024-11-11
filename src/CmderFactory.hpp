#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "Command.hpp"

namespace adas
{
    class CmderFactory
    {
    private:
        std::unordered_map<char, std::function<void(PoseHandler &poseHandler)>> cmderMap{
            {'M', MoveCommand()},
            {'L', TurnLeftCommand()},
            {'R', TurnRightCommand()},
            {'F', FastCommand()},
            {'B', ReverseCommand()},
        };

    public:
        std::list<std::function<void(PoseHandler &poseHandler)>> GetCmders(const std::string &commands) const noexcept;

    public:
        CmderFactory() = default;
        ~CmderFactory() = default;
        CmderFactory(const CmderFactory &) = delete;
        CmderFactory &operator=(const CmderFactory &) = delete;
    };

} // namespace adas
