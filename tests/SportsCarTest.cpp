#include "Executor.hpp"
#include "PoseEq.hpp"
#include <gtest/gtest.h>

namespace adas
{
    class SportsCarTest : public ::testing::Test
    {
    protected:
        void SetUp() override
        {
            executor.reset(Executor ::NewExecutor({0, 0, 'E'}, ExecutorType::SPORTS_CAR));
        }

        void TearDown() override {};
        std::unique_ptr<Executor> executor;
    };

    // M
    TEST_F(SportsCarTest, should_return_x_plus_2_given_command_is_M_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("M");
        // then
        const Pose target({2, 0, 'E'});
        ASSERT_EQ(executor->Query(), target);
    }
    // BM
    TEST_F(SportsCarTest, should_return_x_minus_2_given_command_is_BM_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("BM");
        // then
        const Pose target({-2, 0, 'E'});
        ASSERT_EQ(executor->Query(), target);
    }
    // FM
    TEST_F(SportsCarTest, should_return_x_plus_4_given_command_is_FM_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("FM");
        // then
        const Pose target({4, 0, 'E'});
        ASSERT_EQ(executor->Query(), target);
    }
    // FBM
    TEST_F(SportsCarTest, should_return_x_minus_4_given_command_is_M_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("FBM");
        // then
        const Pose target({-4, 0, 'E'});
        ASSERT_EQ(executor->Query(), target);
    }

    // L
    TEST_F(SportsCarTest, should_return_y_plus_1_and_facing_N_given_command_is_L_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("L");
        // then
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(executor->Query(), target);
    }
    // BL
    TEST_F(SportsCarTest, should_return_y_plus_1_and_facing_S_given_command_is_BL_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("BL");
        // then
        const Pose target({0, 1, 'S'});
        ASSERT_EQ(executor->Query(), target);
    }
    // FL
    TEST_F(SportsCarTest, should_return_x_plus_1_y_plus_1_and_facing_N_given_command_is_FL_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("FL");
        // then
        const Pose target({1, 1, 'N'});
        ASSERT_EQ(executor->Query(), target);
    }
    // FBL
    TEST_F(SportsCarTest, should_return_x_minus_1_y_plus_1_and_facing_S_given_command_is_FBL_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("FBL");
        // then
        const Pose target({-1, 1, 'N'});
        ASSERT_EQ(executor->Query(), target);
    }

    // R
    TEST_F(SportsCarTest, should_return_y_minus_1_and_facing_S_given_command_is_R_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("R");
        // then
        const Pose target({0, -1, 'S'});
        ASSERT_EQ(executor->Query(), target);
    }
    // BR
    TEST_F(SportsCarTest, should_return_y_minus_1_and_facing_N_given_command_is_BR_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("BR");
        // then
        const Pose target({0, -1, 'N'});
        ASSERT_EQ(executor->Query(), target);
    }
    // FR
    TEST_F(SportsCarTest, should_return_x_plus_1_y_minus_1_and_facing_S_given_command_is_FR_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("FR");
        // then
        const Pose target({1, -1, 'S'});
        ASSERT_EQ(executor->Query(), target);
    }
    // FBR
    TEST_F(SportsCarTest, should_return_x_minus_1_y_minus_1_and_facing_N_given_command_is_FBR_and_facing_is_E)
    {
        // given

        // when
        executor->Execute("FBR");
        // then
        const Pose target({-1, -1, 'N'});
        ASSERT_EQ(executor->Query(), target);
    }
}