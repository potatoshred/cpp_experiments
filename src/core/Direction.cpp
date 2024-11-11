#include "Direction.hpp"

namespace adas
{
    static const Direction directions[4] = {
        {0, 'E'},
        {1, 'S'},
        {2, 'W'},
        {3, 'N'},
    };
    // 4种qianjin
    static const Point points[4] = {
        {1, 0},  // E
        {0, -1}, // S
        {-1, 0}, // W
        {0, 1},  // N
    };
    const Direction &Direction::GetDirection(const char heading) noexcept
    {
        for (const auto &direction : directions) {
            if (direction.heading == heading) {
                return direction;
            }
        }
        return directions[3];
    }
    Direction::Direction(const unsigned index, const char heading) noexcept : index(index), heading(heading) {}

    const Point &Direction::Move() const noexcept
    {
        return points[index];
    }

    const Direction &Direction::LeftOne() const noexcept
    {
        return directions[(index + 3) % 4];
    }
    const Direction &Direction::RightOne() const noexcept
    {
        return directions[(index + 1) % 4];
    }
    const char Direction::GetHeading() const noexcept
    {
        return heading;
    }
} // namespace adas
