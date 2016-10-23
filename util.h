#ifndef _UTIL_H_
#define _UTIL_H_

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define BUILD_BUG_ON(e) ((void)sizeof(char[1 - 2*!!(e)]))
#define BUILD_BUG_ON_ZERO(e) (sizeof(struct { int:-!!(e); }))
#define ASSERT(e) static char __attribute__((unused)) _compile_time_assert_ ## __COUNTER__[(e) ? 0 : -1]

#define STR(x) _STR(x)
#define _STR(x) #x

#ifndef MIN
#define MIN(x, y) (x) <  (y) ? (x) : (y)
#endif

#ifndef MAX
#define MAX(x, y) (x) <= (y) ? (y) : (x)
#endif

#endif /* _UTIL_H_ */
