#pragma once

#include "Executor.hpp"
#include <string>

namespace adas
{
    /* Executor的具体实现 */
    class ExecutorImpl : public Executor
    {
    private:
        Pose pose;
        bool isFast;

    private:
        void Move() noexcept;
        void TurnLeft() noexcept;
        void TurnRight() noexcept;

    public:
        // 构造函数
        explicit ExecutorImpl(const Pose &pose) noexcept;
        // 默认析构函数
        ~ExecutorImpl() noexcept = default;

        // 禁用拷贝
        ExecutorImpl(const ExecutorImpl &) = delete;
        // 禁用赋值
        ExecutorImpl &operator=(const ExecutorImpl &) = delete;

    public:
        // 查询当前汽车姿态，是父类抽象方法Query的具体实现
        Pose Query() const noexcept override;
        // 第二阶段新增加的虚函数，执行用字符串表示的指令
        virtual void Execute(const std::string &commands) noexcept override;
    };

} // namespace adas
