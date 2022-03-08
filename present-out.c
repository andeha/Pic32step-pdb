/*  output-present.c | similar to the 'Present' function and via stderr. */

import litenbeam;

#define bright "\x1B[1m"
#define dim "\x1B[2m"
#define fgBlue "\x1B[34m"
#define fgRed "\x1B[31m"
#define reset "\x1B[0m"
#define reverse "\x1B[7m"

inexorable void EmitUnicodesUntil𝟶𝚡𝟶𝟶𝟶𝟶(const char32̄_t * unicodes)
{ int i=0; char32̄_t uc;
again:
    uc = *(unicodes + i);
    if (uc == 0x0000) { return; }
    if (UnicodeToUtf8(uc, ^(char8₋t * ξ, short bytes) {
      if (bytes >= 1) mfprint("⬚", ﹟c7((char)*(ξ + 0)));
      if (bytes >= 2) mfprint("⬚", ﹟c7((char)*(ξ + 1)));
      if (bytes >= 3) mfprint("⬚", ﹟c7((char)*(ξ + 2)));
      if (bytes >= 4) mfprint("⬚", ﹟c7((char)*(ξ + 3)));
   } )) { /* empty */ }
   i+=1; goto again;
}

inexorable
void
Output(
  const Bitfield * field, 
  uint32_t value, 
  uint32_t init, 
  int is₋sixteen, 
  __builtin_int_t maxwidth
) ⓡ
{
    unsigned spaces = maxwidth - TetrasUntilZero(/*Critic*/(char32̄_t *)(field->regular), BUILTIN₋INT₋MAX);
    while (spaces--) { mfprint(" "); }
    
    EmitUnicodesUntil𝟶𝚡𝟶𝟶𝟶𝟶(field->regular);
    mfprint(" ");
    int 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 masking=false; unsigned 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 pos=31;
    Base𝕟((__builtin_uint_t)(field->mask), 2, 32, ^(char digit) {
        
        if (is₋sixteen && pos > 15) { mfprint("﹟"); }
        
        if (!is₋sixteen && digit == '1' && !masking) { masking = true; }
        
        if (!is₋sixteen && masking && digit == '0') { masking = false; }
        
        if (!is₋sixteen && masking) { mfprint(value & (0b1<<pos) ? "1" : "0"); }
        
        if (!is₋sixteen && !masking) { mfprint("␣"); }
        
        if (pos % 4 == 0) mfprint("|"); --pos;
        
    });
    
    EmitUnicodesUntil𝟶𝚡𝟶𝟶𝟶𝟶(field->text);
    mfprint("\n");
}

FOCAL
void
Output(
  const AnnotatedRegister * ar, 
  uint32_t value, 
  int is₋sixteen
) ⓡ
{ typedef void (^Present)(int,const Bitfield *,uint32_t,uint32_t);
    Present present = ^(int count, const Bitfield * regs, 
     uint32_t value, uint32_t init) { __builtin_int_t maxwidth=0;
      for (int i=0; i<count; i+=1) { const Bitfield * reg = regs + i; 
       maxwidth = max(maxwidth, TetrasUntilZero(/*Critic*/(char32̄_t *)(reg->regular), 
        BUILTIN₋INT₋MAX));
      }
      for (int i=0; i<count; i+=1) {
       Output(regs + i, value, init, is₋sixteen, maxwidth);
      } };
    mfprint("⬚\n", ﹟s7(bright));
    EmitUnicodesUntil𝟶𝚡𝟶𝟶𝟶𝟶(ar->header);
    mfprint("⬚ = %s 0x", ﹟s7(reset), ﹟s7(reverse));
    Base𝕟((__builtin_uint_t)value, 16, 8, ^(char digits) { mfprint("⬚", ﹟c7(digits)); });
    mfprint("⬚\n\n", ﹟s7(reset));
    present(ar->regcnt, ar->regs, value, ar->init);
    EmitUnicodesUntil𝟶𝚡𝟶𝟶𝟶𝟶(ar->footnote);
    mfprint("\n\n");
}

