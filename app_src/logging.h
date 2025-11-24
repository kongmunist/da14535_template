#ifndef F92110D7_6762_414E_978F_7DCBDFBE2F0D
#define F92110D7_6762_414E_978F_7DCBDFBE2F0D

#include "lld_evt.h"
#include "SEGGER_SWD_printf.h"

#define __COREDUMP

// Macro to get the current time using lld_evt_time_get()
#define GET_TIMESTAMP() lld_evt_time_get()

// Logging macros
#define LOG_DEBUG(format, ...) SWD_printf("DEBUG (%lu): " format, GET_TIMESTAMP() __VA_OPT__(,) __VA_ARGS__)
#define LOG_INFO(format, ...) SWD_printf("INFO (%lu): " format, GET_TIMESTAMP() __VA_OPT__(,) __VA_ARGS__)
#define LOG_WARNING(format, ...) SWD_printf("WARNING (%lu): " format, GET_TIMESTAMP() __VA_OPT__(,) __VA_ARGS__)
#define LOG_ERROR(format, ...) SWD_printf("ERROR (%lu): " format, GET_TIMESTAMP() __VA_OPT__(,) __VA_ARGS__)

#define LOG_UINT16_RAW(value) SEGGER_RTT_Write(0, (const char*)&(value), sizeof(uint16_t))
#define LOG_UINT32_RAW(value) SEGGER_RTT_Write(0, (const char*)&(value), sizeof(uint32_t))

// Reset macro
#define SYSTEM_RESET() SetWord16(SYS_CTRL_REG, (GetWord16(SYS_CTRL_REG) & ~REMAP_ADR0) | SW_RESET)

// Assertion and precondition macros
#define PRECONDITION(cond, ...) \
    if (!(cond)) { \
        LOG_ERROR("Precondition failed: %s:%d " __VA_ARGS__, __FILE__, __LINE__); \
        SYSTEM_RESET(); \
    }

#ifdef CFG_DEVELOPMENT_DEBUG
    #define ASSERT(cond, ...) \
        if (!(cond)) { \
            LOG_ERROR("Assertion failed: %s:%d " __VA_ARGS__, __FILE__, __LINE__); \
            SYSTEM_RESET(); \
        }
#else
    #define ASSERT(cond, ...) \
        if (!(cond)) { \
            SYSTEM_RESET(); \
        }
#endif // CFG_DEVELOPMENT_DEBUG

#define PRECONDITION_FAILURE(...) PRECONDITION(0, __VA_ARGS__)
#define ASSERTION_FAILURE(...) ASSERT(0, __VA_ARGS__)

#endif /* F92110D7_6762_414E_978F_7DCBDFBE2F0D */
