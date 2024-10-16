#include "Executor.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <tuple>

namespace adas
{
    bool operator==(const Pose &lhs, const Pose &rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }

    // 测试用例1：当未传入指令时，返回原来的姿态
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // given 给定测试条件
        // 给定了初始姿势
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when

        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(executor->Query(), target); // 调用重载的operator==
    }

    // 测试用例2：当未初始化且为传入命令时，返回默认姿态
    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
    {
        // given nothing
        std::unique_ptr<Executor> executor(Executor::NewExecutor());

        // when

        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(executor->Query(), target); // 调用重载的operator==
    }

    // 测试用例3：移动指令M：当面向E时，x++
    TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->Execute("M");
        // then
        const Pose target = {1, 0, 'E'};
        ASSERT_EQ(executor->Query(), target);
    }
    // 测试用例4：移动指令M：当面向W时，x--
    TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
        // when
        executor->Execute("M");
        // then
        const Pose target = {-1, 0, 'W'};
        ASSERT_EQ(executor->Query(), target);
    }
    // 测试用例5：移动指令M：当面向N时，y++
    TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
        // when
        executor->Execute("M");
        // then
        const Pose target = {0, 1, 'N'};
        ASSERT_EQ(executor->Query(), target);
    }
    // 测试用例6：移动指令M：当面向S时，y--
    TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
        // when
        executor->Execute("M");
        // then
        const Pose target = {0, -1, 'S'};
        ASSERT_EQ(executor->Query(), target);
    }

    // 测试用例7：左转指令L：当面向E时，返回N
    TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->Execute("L");
        // then
        const Pose target = {0, 0, 'N'};
        ASSERT_EQ(executor->Query(), target);
    }
    // 测试用例8：左转指令L：当面向N时，返回W
    TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
        // when
        executor->Execute("L");
        // then
        const Pose target = {0, 0, 'W'};
        ASSERT_EQ(executor->Query(), target);
    }
    // 测试用例9：左转指令L：当面向W时，返回S
    TEST(ExecutorTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
        // when
        executor->Execute("L");
        // then
        const Pose target = {0, 0, 'S'};
        ASSERT_EQ(executor->Query(), target);
    }
    // 测试用例10：左转指令L：当面向S时，返回E
    TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
        // when
        executor->Execute("L");
        // then
        const Pose target = {0, 0, 'E'};
        ASSERT_EQ(executor->Query(), target);
    }

    // 测试用例11：右转指令R：当面向E时，返回S
    TEST(ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
        // when
        executor->Execute("R");
        // then
        const Pose target = {0, 0, 'S'};
        ASSERT_EQ(executor->Query(), target);
    }
    // 测试用例12：右转指令R：当面向S时，返回W
    TEST(ExecutorTest, should_return_facing_W_given_command_is_R_and_facing_is_S)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
        // when
        executor->Execute("R");
        // then
        const Pose target = {0, 0, 'W'};
        ASSERT_EQ(executor->Query(), target);
    }
    // 测试用例13：右转指令R：当面向W时，返回N
    TEST(ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_W)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
        // when
        executor->Execute("R");
        // then
        const Pose target = {0, 0, 'N'};
        ASSERT_EQ(executor->Query(), target);
    }
    // 测试用例14：右转指令R：当面向N时，返回E
    TEST(ExecutorTest, should_return_facing_E_given_command_is_R_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
        // when
        executor->Execute("R");
        // then
        const Pose target = {0, 0, 'E'};
        ASSERT_EQ(executor->Query(), target);
    }
} // namespace adas
