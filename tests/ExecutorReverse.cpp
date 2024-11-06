#include "Executor.hpp"
#include "PoseEq.hpp"
#include <gtest/gtest.h>

namespace adas
{
    // 测试用例1：当未传入指令时，返回原来的姿态
    TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_back_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BM");
        // then
        const Pose target({-1, 0, 'E'});
        ASSERT_EQ(executor->Query(), target);
    }

    TEST(ExecutorReverseTest, should_return_S_given_status_is_back_command_is_L_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BL");
        // then
        const Pose target({0, 0, 'S'});
        ASSERT_EQ(executor->Query(), target);
    }

    TEST(ExecutorReverseTest, should_return_N_given_status_is_back_command_is_R_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BR");
        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(executor->Query(), target);
    }

    TEST(ExecutorReverseTest, should_return_y_plus_1_given_command_is_BBM_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor()); // 默认起始状态是 {0,0,'N'}

        // when
        executor->Execute("BBM");
        // then
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(executor->Query(), target);
    }
}