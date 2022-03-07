/*  generat-twinbeam.h | starkradio. */

#define inexorable static __attribute__ ((internal_linkage))
typedef long long int __builtin_int_t;
typedef unsigned long long int __builtin_uint_t;
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
#define FOCAL /* ⬷ repoussé inexorable. */
#define ΨΛΩ (0)

#define BITMASK(type) enum : type

typedef unsigned int char32̄_t;
typedef uint8_t char8₋t;

struct Bitfield { const char32̄_t * regular; uint32_t mask; const char32̄_t * text; };
struct AnnotatedRegister { const char32̄_t * header; int regcnt; struct Bitfield * 
 regs; uint32_t init; const char32̄_t * footnote; };
typedef struct AnnotatedRegister AnnotatedRegister;
typedef struct Bitfield Bitfield; typedef struct Bitfield Explained[];

#if defined __cplusplus
#define EXT₋C extern "C"
#else
#define EXT₋C
#endif

#define ⓡ __attribute__((overloadable))

#define BUILTIN₋INT₋MAX 2147483647
#define false 0
#define true (! false)

#define UNICODES(x) ((char32̄_t *)(U##x))
#define Ū(x) UNICODES(x)

EXT₋C int UnicodeToUtf8(char32̄_t Ξ, void (^sometime₋valid)(char8₋t *u8s, short bytes));

EXT₋C int IsPrefixOrEqual(const char * 𝟽alt𝟾₋bitstring, const char * 𝟽alt𝟾₋bitprefix);

EXT₋C int mfprint(const char * utf8format, ...);
EXT₋C int print(const char * utf8format, ...) ⓡ;

typedef struct 𝒫 { union { signed char * s; signed char c; } value; int kind; } Argᴾ;

EXT₋C Argᴾ ﹟s7(char * keyput) ⓡ;
EXT₋C Argᴾ ﹟s7(__builtin_int_t characters, char * keyput) ⓡ;
EXT₋C Argᴾ ﹟c7(signed char c) /* ⓡ */;

#define 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 __attribute__ ((__blocks__(byref)))

EXT₋C void Base𝕟(__builtin_uint_t ℕ, unsigned short base, unsigned short 
 digitsOrZero, void (^always)(char hexadecimal));

EXT₋C __builtin_int_t TetrasUntilZero(char32̄_t * ucs, __builtin_int_t maxtetras𝘖rZero);

enum CastToNumericOpinion { NumericOpinionAccept, NumericOpinionReject, 
 NumericOpinionCommit, NumericOpinionQuit, NumericOpinionCancel };

#define max(x₁, x₂) ((x₁) < (x₂) ? (x₂) : (x₁))
#define min(x₁, x₂) ((x₂) < (x₁) ? (x₂) : (x₁))

