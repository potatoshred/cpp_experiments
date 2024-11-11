#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "Command.hpp"

namespace adas
{
    using Cmder = std::function<ActionGroup(PoseHandler &poseHandler)>;
    using CmderList = std::list<Cmder>;

    class CmderFactory
    {
    private:
        std::unordered_map<char, Cmder> cmderMap{
            {'M', MoveCommand()},
            {'L', TurnLeftCommand()},
            {'R', TurnRightCommand()},
            {'F', FastCommand()},
            {'B', ReverseCommand()},
        };

    public:
        CmderList GetCmders(const std::string &commands) const noexcept;

    public:
        CmderFactory() = default;
        ~CmderFactory() = default;
        CmderFactory(const CmderFactory &) = delete;
        CmderFactory &operator=(const CmderFactory &) = delete;
    };

} // namespace adas
