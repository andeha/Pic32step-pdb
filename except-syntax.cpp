/*  except-language.cpp | du-ni-to-rx and CastTxtToInt. */

import litenbeam;

Opt<__builtin_int_t>
CastTextToNumeric(
  CastToNumericOpinion (^feeder)(unsigned short * digit)
)
{ __builtin_int_t val=0; unsigned short zero_to_nine; int sgn=1;
   while (1) {
      CastToNumericOpinion opinion = feeder(&zero_to_nine);
      /* C++20 syntax: 'using enum CastToIntOpinion;' */
      switch (opinion) {
       case NumericOpinionAccept: val *= 10; val += sgn*zero_to_nine; break;
       case NumericOpinionReject: continue;
       case NumericOpinionNegate: sgn *= -1; break;
       case NumericOpinionCommit: return Opt<__builtin_int_t>(val);
       case NumericOpinionCancel: return Opt<__builtin_int_t>::no();
      }
   }
}

EXT₋C
FOCAL
int
UnicodeToUtf8(
  char32̄_t Ξ, 
  void (^sometime₋valid)(char8₋t *u8s, short bytes)
)
{
    unsigned char 🥈 firstByteMark[7] = { 0x00, 0x00, 0xC0, 0xE0, 0xF0, 
      0xF8, 0xFC };
    
    char32̄_t 🥈 bytemask=0xBF, bytemark=0x80;
    
    short bytesToWrite=0;
    
    if (Ξ < 0x80L) { bytesToWrite=1; }
    else if (Ξ < 0x800L) { bytesToWrite=2; }
    else if (Ξ < 0x10000L) { bytesToWrite=3; }
    else if (Ξ <= 0x0010FFFFL) { bytesToWrite=4; }
    else { return 1; }
    
    char8₋t target[4];
    
    switch (bytesToWrite) {
    case 4: target[3] = (char8₋t)((Ξ | bytemark) & bytemask); Ξ >>= 6;
    case 3: target[2] = (char8₋t)((Ξ | bytemark) & bytemask); Ξ >>= 6;
    case 2: target[1] = (char8₋t)((Ξ | bytemark) & bytemask); Ξ >>= 6;
    case 1: target[0] = (char8₋t) (Ξ | firstByteMark[bytesToWrite]);
    }
    
    sometime₋valid(target,bytesToWrite);
    
    return 0;
}
