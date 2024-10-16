#pragma once
#include <string>
namespace adas
{
    /* 汽车姿态 */
    struct Pose {
        int x;
        int y;
        char heading;
    };

    /* 驾驶动作执行接口 */
    class Executor
    {
    public:
        static Executor *NewExecutor(const Pose &pose = {0, 0, 'N'}) noexcept;

    public:
        Executor() = default;
        virtual ~Executor() = default;

        Executor(const Executor &) = delete;
        Executor &operator=(const Executor &) = delete;

    public:
        // 查询当前汽车姿态，纯虚函数，留给子类具体实现
        virtual Pose Query() const noexcept = 0;
        virtual void Execute(const std::string &commands) noexcept = 0;
    };
} // namespace adas