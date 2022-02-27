/*  Present-reg.cpp | similar to 'Present' but via stdout. */

#include <Twinbeam.h>
#include <Additions/Additions.h> /* ⬷ import Twinbeam. */
#include <stdio.h>

const char *bright="\x1B[1m", *dim="\x1B[2m", *fgBlue="\x1B[34m", 
  *fgRed="\x1B[31m", *reset="\x1B[0m", *reverse="\x1B[7m";

inexorable void EmitUnicodesUntil𝟶𝚡𝟶𝟶𝟶𝟶(const char32_t * unicodes)
{
  int i=0;
again:
    char32_t uc = *(unicodes + i);
    if (uc == 0x0000) { return; }
    if (UnicodeToUtf8(uc, ^(char8_t * ξ, short bytes) {
      if (bytes >= 1) fprintf(stderr, "%c", (char)*(ξ + 0));
      if (bytes >= 2) fprintf(stderr, "%c", (char)*(ξ + 1));
      if (bytes >= 3) fprintf(stderr, "%c", (char)*(ξ + 2));
      if (bytes >= 4) fprintf(stderr, "%c", (char)*(ξ + 3));
   } )) { /* empty */ }
   i++; goto again;
}

inexorable
void
Output(
  const Bitfield& field,
  uint32_t value,
  uint32_t init,
  bool 𝟷𝟼bits,
  __builtin_int_t maxwidth
)
{
    unsigned spaces = maxwidth - TetrasUntilNull(Critic(field.ident), BUILTIN₋INT₋MAX);
    while (spaces--) { fprintf(stderr, " "); }
    
    EmitUnicodesUntil𝟶𝚡𝟶𝟶𝟶𝟶(field.ident);
    fprintf(stderr, " ");
    
    bool 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 masking=false; unsigned 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 pos=31;
    Base𝕟((__builtin_uint_t)(field.mask), 2, 32, ^(char 𝟶to𝟿) {
        
        if (𝟷𝟼bits && pos > 15) { fprintf(stderr, "﹟"); }
        
        if (!𝟷𝟼bits && 𝟶to𝟿 == '1' && !masking) { masking = true; }
        
        if (!𝟷𝟼bits && masking && 𝟶to𝟿 == '0') { masking = false; }
        
        if (!𝟷𝟼bits && masking) { fprintf(stderr, value & (0b1<<pos) ? "1" : "0"); }
        
        if (!𝟷𝟼bits && !masking) { fprintf(stderr, "␣"); }
        
        if (pos % 4 == 0) fprintf(stderr, "|"); --pos;
        
    });
    
    EmitUnicodesUntil𝟶𝚡𝟶𝟶𝟶𝟶(field.text);
    fprintf(stderr, "\n");
}

FOCAL
void
Output(
  const AnnotatedRegister& ar,
  uint32_t value,
  bool 𝟷𝟼bits
)
{
    auto present = ^(int count, const Bitfield * regs, 
     uint32_t value, uint32_t init) { __builtin_int_t maxwidth=0;
      for (int i=0; i<count; ++i) { const Bitfield * reg = regs + i; 
       maxwidth = max(maxwidth, TetrasUntilNull(Critic(reg->ident), 
        BUILTIN₋INT₋MAX));
      }
      for (int i=0; i<count; ++i) {
       Output(*(regs + i), value, init, 𝟷𝟼bits, maxwidth);
      } };
    fprintf(stderr, "%s\n", bright);
    EmitUnicodesUntil𝟶𝚡𝟶𝟶𝟶𝟶(ar.header);
    fprintf(stderr, "%s = %s 0x", reset, reverse);
    Base𝕟(__builtin_uint_t(value), 16, 8, ^(char 𝟶to𝟿) { fprintf(stderr, "%c", 𝟶to𝟿); });
    fprintf(stderr, "%s\n\n", reset);
    present(ar.regcnt, ar.regs, value, ar.init);
    EmitUnicodesUntil𝟶𝚡𝟶𝟶𝟶𝟶(ar.footnote);
    fprintf(stderr, "\n\n");
}
