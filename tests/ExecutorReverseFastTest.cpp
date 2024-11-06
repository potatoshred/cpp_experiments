#include "Executor.hpp"
#include "PoseEq.hpp"
#include <gtest/gtest.h>
namespace adas
{
    TEST(ExecutorReverseFastTest, should_return_x_minus_2_given_status_is_reverse_and_fast_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BFM");
        // then
        const Pose target({-2, 0, 'E'});
        ASSERT_EQ(executor->Query(), target);
    }

    TEST(ExecutorReverseFastTest, should_return_S_and_x_minus_1_given_status_is_reverse_and_fast_command_is_L_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BFL");
        // then
        const Pose target({-1, 0, 'S'});
        ASSERT_EQ(executor->Query(), target);
    }

    TEST(ExecutorReverseFastTest, should_return_N_and_x_minus_1_given_status_is_reverse_and_fast_given_command_is_R_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BFR");
        // then
        const Pose target({-1, 0, 'N'});
        ASSERT_EQ(executor->Query(), target);
    }
} // namespace adas
