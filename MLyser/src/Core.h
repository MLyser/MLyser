#pragma once

#ifdef MLZ_PLATFORM_WINDOWS
    #define MLZ_WINDOWS
#elif MLZ_PLATFORM_MACOSX
    #define MLZ_MACOSX
#endif

#define BIT(x) (1 << x)
