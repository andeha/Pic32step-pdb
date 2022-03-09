/*  print-present.c | sevenbit, utf8 and Unicode output from program text. */

import litenbeam;

EXT₋C Argᴾ ﹟s7(char * keyput) ⓡ { Argᴾ y = { .value.s=(char8₋t *)keyput, .kind=4 }; return y; }
EXT₋C Argᴾ ﹟c7(char c) { Argᴾ y = { .value.c=c, .kind=6 }; return y; }

EXT₋C
int 
print﹟(
  void (^out)(char8₋t * u8s, __builtin_int_t bytes),
  const char * format,
  __builtin_va_list argument
)
{ __builtin_int_t i=0,incr; char8₋t *leadOr8Bit, byte; short followers; char32̄_t uc;
   typedef void (^Unicode₋symbol)(char32̄_t uc);
   typedef void (^Utf8₋symbol)(char8₋t u8);
   typedef void (^Utf8₋sequence)(char8₋t * u8s);
   Unicode₋symbol unicode₋symbol = ^(char32̄_t uc) {
    UnicodeToUtf8(uc, ^(char8₋t * u8s, short bytes) { out(u8s,(__builtin_int_t)bytes); }); };
   Utf8₋symbol utf8₋symbol = ^(char8₋t u8) { out(&u8,1); };
   Utf8₋sequence utf8₋sequence = ^(char8₋t * u8s) { char8₋t *p=u8s; 
    while (*p) { out(p,1); p+=1; } };
again:
   leadOr8Bit = i + (char8₋t *)format;
   byte = *leadOr8Bit;
   if (byte == 0x0) { goto unagain; }
   followers = Utf8Followers(byte);
   if (followers < 0) { return -1; }
   incr = followers + 1;
   uc = Utf8ToUnicode(leadOr8Bit,incr);
   if (uc == 0xfffe || uc == 0xffff) { return -2; }
   else if (uc != U'⬚') { unicode₋symbol(uc); }
   else {
     const Argᴾ a = __builtin_va_arg(argument,Argᴾ);
     switch (a.kind) {
     case 4: utf8₋sequence(a.value.s); break;
     case 6: utf8₋symbol(a.value.c); break;
     default: unicode₋symbol(U'?');
     }
   }
   i+=incr; goto again;
unagain:
   return 0;
}

EXT₋C long write(int fd, const void * s, long unsigned nbyte);

EXT₋C int mfprint(const /* unsigned */ char * format, ...)
{ int y; va_prologue(format)
   typedef void (^Out)(char8₋t *, __builtin_int_t);
#if defined __armv8a__ || defined __x86_64__
   Out out = ^(char8₋t * u8s, __builtin_int_t bytes) { write(2,(const void *)u8s,bytes); };
#elif defined __mips__ || defined espressif || defined __armv6__
   Out out = ^(char8₋t * u8s, __builtin_int_t bytes) { Trace₁(u8s,bytes); };
#endif
   y = print﹟(out,format,__various);
   va_epilogue; return y;
}

EXT₋C int print(const /* unsigned */ char * format, ...) ⓡ /* ⬷ all variable arguments are of the type Argᴾ. */
{ int y; va_prologue(format)
   typedef void (^Out)(char8₋t *, __builtin_int_t);
#if defined __armv8a__ || defined __x86_64__
   Out out = ^(char8₋t * u8s, __builtin_int_t bytes) { write(1,(const void *)u8s,bytes); };
#elif defined __mips__ || defined espressif || defined __armv6__
   Out out = ^(char8₋t * u8s, __builtin_int_t bytes) { Putₒ(u8s,bytes); }
#endif
   y = print﹟(out,format,__various);
   va_epilogue; return y;
}

