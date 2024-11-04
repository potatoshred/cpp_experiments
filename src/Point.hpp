#pragma once

namespace adas
{
    class Point final
    {
    private:
        int x;
        int y;

    public:
        Point(const int x, const int y) noexcept;
        Point(const Point &rhs) noexcept;
        Point &operator=(const Point &rhs) noexcept;
        Point &operator+=(const Point &rhs) noexcept;

    public:
        int GetX() const noexcept;
        int GetY() const noexcept;
    };
} // namespace adas
