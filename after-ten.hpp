/*  after-ten.hpp | abbreviations. */

#if defined __cplusplus
struct SharedOptional { int populated=false; 
 operator int() const { return populated; } };
typedef unsigned long size_t;
void * operator new(size_t size, void * here) noexcept;
template <typename I> struct Opt : public SharedOptional {
 Opt() = default;
 template <typename...A> constexpr Opt(A&&... args) {
   new (element) I(args...); populated=true; }
 Opt(const Opt<I>& other) { populated=other.populated; 
  if (populated) { new (element) I((const I&)(other.element)); } }
 ~Opt() { ((I *)element)->~I(); }
 I& operator*() const { return (I&)element; }
 static Opt no() { return Opt(); }
 alignas(I) uint8_t element[sizeof(I)]; };
template <typename I> struct Opt<I&> : public SharedOptional {
 Opt() { element = ΨΛΩ; }
 template <typename...A> constexpr Opt(A&&...args) {
   new (element) I(args ...); populated=true; }
  Opt(const Opt<I&>& other) { }
  ~Opt() { /* does nothing */ }
  I& operator*() const { return (I&)element; }
 I * element; };

Opt<__builtin_int_t> CastTextToNumeric(CastToNumericOpinion (^feeder)(unsigned 
 short * digit));
#define WHEN_COMPILING constexpr static
#define 🥈 WHEN_COMPILING
template <typename Y> Y * Critic(const Y * x) { return (Y *)x; }
template <typename X> X& Critic(const X& y) { return (X&)y; }
#endif

