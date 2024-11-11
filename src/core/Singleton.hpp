#pragma once

namespace adas
{
    template <typename T>
    class Singleton final
    {
    private:
        Singleton();
        ~Singleton();

    public:
        static T &Instance()
        {
            static T instance;
            return instance;
        }

        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton &) = delete;
    };
} // namespace adas
