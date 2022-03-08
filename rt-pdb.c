/*  rt-pdb.cpp | miscellaneous functions. */

import litenbeam;

void
Base𝕟( /* TeX §64, §65 and §67. */
  __builtin_uint_t ℕ, 
  unsigned short base, 
  unsigned short digitsOr0, /* ⬷ not more than 32 or 64 digits depending on 
    your machines' word size! (Or set to `0` to skip leading zeros.) */
  void (^output)(char hex)
)
{
    typedef void (^Out)(unsigned short, void (^out)(char));
    Out 𝟬to𝗙 = ^(unsigned short r, void (^out)(char hex)) { r < 10 ? 
      out('0' + r) : out('a' - 10 + r); };
    
    unsigned short cycle[64] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0 }; short k = 0;
    
    do { cycle[k] = ℕ % base; ℕ /= base; k++; } while (ℕ);
    
    if (digitsOr0) { for (k = digitsOr0-1; k>=0; k-=1) { 𝟬to𝗙(cycle[k], 
      output); } } else { k = 63; while (cycle[k] == 0 && k > 0) { k--; }
       for (; k >= 0; k--) { 𝟬to𝗙(cycle[k], output); }
    }
} /*  ⬷ note 128-bit duplicate in --<🥽 𝙋𝙧𝙞𝙣𝙩⁺.cpp> and --<present-print.c> 
 here 'serial and occasionally balanced'. */

int
IsPrefixOrEqual(
  const char * 𝟽alt𝟾₋bitstring, /* ⬷ possibly 'normalizedUtf8' */
  const char * 𝟽alt𝟾₋bitprefix  /* ⬷ smiley appears when 'prompt> nm'! */
) /* ⬷ consider changing dwarf-'.elf' to 'trie' instead of 'table'. */
{  const char *s=𝟽alt𝟾₋bitstring, *p=𝟽alt𝟾₋bitprefix;
    if (*s == 0 && *p == 0) { return -1; }  /* Parameters `string` and `prefix` are both empty therefore equal. */
    if (!*s) { return 0; } /* Non-equal since the string is empty and a prefix exists. */
    if (!*p) { return *s; } /* The prefix is empty but not the string, return dist(0, non-end). */
again:
    if (*s == 0 && *p == 0) { return -1; }  /* Parameters 'string' and 'prefix' are non-empty and equal. */
    if (*s == 0 && *p != 0) { return 0; }   /* The prefix continues after string. */
    if (*s != 0 && *p == 0) { return *s; }  /* All characters in 'prefix' equal to 'string'. Return first character following 'eightbitPrefix'. */
    /* *p != 0 && *s != 0 */
    char diff = *s - *p;
    if (diff) { return 0; }
    s++, p++;
    goto again;
}

short
Utf8Followers(char8₋t leadOr8Bit)
{
    if (leadOr8Bit < 128) { return 0; }
    if (128 <= leadOr8Bit && leadOr8Bit < 192) return -1;
    if (248 <= leadOr8Bit) return -1;
    
#if defined __mips__ || defined __armv6__ || defined __armv8a__
    /* Mips: clz $a0, $v0, Arm: clz r0, r14. */
    __builtin_int_t onesUntilZero = __builtin_clz(~((uint32_t)leadOr8Bit<<24));
#elif defined __x86_64__ /* BSF, BSR, LZCNT, TZCNT, __lzcnt64 on Win64. */
    __builtin_int_t onesUntilZero = __builtin_clzll(~((uint64_t)leadOr8Bit<<56));
#else
    auto clz = ^(uint8_t x) {
      uint8_t 🥈ᵢ lookup[16] = { 4, 3, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 
        0, 0, 0 }, upper = x >> 4, lower = x & 0x0F;
      return upper ? lookup[upper] : 4 + lookup[lower];
    };
    __builtin_int_t onesUntilZero = clz(~leadOr8Bit);
#endif
    
    return (short)onesUntilZero - 1;
}

char32̄_t
Utf8ToUnicode(char8₋t *ξ, __builtin_int_t bytes)
{
   char8₋t first = *ξ;
   if (248 <= first || (128 <= first && first < 192)) { return 0x0000ffff; }
   switch (bytes) {
   case 1: return (char32̄_t)first;
   case 2: return (0b11111 & first)<<6 | (0x3d & *(ξ+1));
   case 3: return (0b1111 & first)<<12 | (0x3f & *(ξ+1))<<6 | (0x3f & *(ξ+2));
   case 4: return (0b111 & first)<<18 | (0x3f & *(ξ+1))<<12 | (0x3f & *(ξ+2))<<6 | (0x3f & *(ξ+3));
   }
   return 0x0000fffe;
}

__builtin_int_t
Utf8BytesUntilZero(
  char8₋t * u8s, 
  __builtin_int_t maxbytes𝘖rZero
)
{ __builtin_int_t i=0;
again:
   if (i >= maxbytes𝘖rZero && maxbytes𝘖rZero != 0) { return maxbytes𝘖rZero; }
   char8₋t * leadOr8Bit = u8s + i;
   if (*leadOr8Bit == 0x0) { return i; }
   __builtin_int_t followers = Utf8Followers(*leadOr8Bit);
   if (followers < 0) { return -1; }
   i += followers + 1;
   goto again;
}

__builtin_int_t TetrasUntilZero(char32̄_t * ucs, __builtin_int_t maxtetras𝘖rZero)
{ __builtin_int_t i=0;
again:
   if (i >= maxtetras𝘖rZero && maxtetras𝘖rZero != 0) { return maxtetras𝘖rZero; }
   char32̄_t * uc = ucs + i;
   if (*uc == 0x0000) { return i; }
   i+=1; goto again;
}


