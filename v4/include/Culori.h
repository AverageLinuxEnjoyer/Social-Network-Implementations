#ifndef CULORI_H
#define CULORI_H

#include <ostream>

/**
 * @brief Clasa pentru schimbarea culorilor din consola.
 * 
 */
namespace Color {
    enum Code {
        FG_GREEN    = 32,
        FG_RED      = 31,
        BG_GREEN    = 42,
        BG_DEFAULT  = 49,
        FG_DEFAULT  = 39,
        BG_BLUE     = 44,
        FG_BLUE     = 34,
        BG_RED      = 41,
    };
    
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

/**
 * @brief Sterge tot din consola.
 */
inline void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

#endif // CULORI_H
