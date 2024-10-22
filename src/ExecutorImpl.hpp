#pragma once

#include "Executor.hpp"
#include <string>

namespace adas
{
    /* Executor的具体实现 */
    class ExecutorImpl final : public Executor
    {

    private:
        class MoveCommand final
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept
            {
                executor.Move();
            }
        };

        class TurnLeftCommand final
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept
            {
                executor.TurnLeft();
            }
        };
        class TurnRightCommand final
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept
            {
                executor.TurnRight();
            }
        };

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
