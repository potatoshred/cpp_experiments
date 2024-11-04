#pragma once
#include "Point.hpp"
namespace adas
{
    class Direction final
    {
    private:
        unsigned index; // 方向索引 0 1 2 3
        char heading;   // 方向字符 E S W N

    public:
        static const Direction &GetDirection(const char heading) noexcept;

        Direction(const unsigned index, const char heading) noexcept;

        const Point &Move() const noexcept;
        const Direction &LeftOne() const noexcept;
        const Direction &RightOne() const noexcept;

        const char GetHeading() const noexcept;
    };
} // namespace adas
