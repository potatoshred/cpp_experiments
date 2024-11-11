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
        std::string ParseCommandString(std::string_view commands) const noexcept;
        void ReplaceAll(std::string &inout, std::string_view what, std::string_view with) const noexcept;

        std::unordered_map<char, Cmder> cmderMap{
            {'M', MoveCommand()},
            {'L', TurnLeftCommand()},
            {'R', TurnRightCommand()},
            {'F', FastCommand()},
            {'B', ReverseCommand()},
            {'Z', TurnRoundCommand()},
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
