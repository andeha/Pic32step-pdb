/*  main.cpp | explaining one debugger. */

import litenbeam;

/* code below assumes 'stdout' and 'stderr'. */

/* To compile enter 'prompt% ninja'. */

struct Prefix {
const char * prefix;
const AnnotatedRegister& reg;
};

enum class Registerset { pic32mzda, pic32mm };

struct {
 Registerset registers;
 const char *device, *mdbpath;
} defaults {
 Registerset::pic32mzda, /* ⬷ note multiple images via 'fork'. */
 "PIC32MZ2064DAB288", /* PIC32MZ2064DAH169, PIC32MM0064GPL036 */ 
 "/Applications/microchip/mplabx/v5.50/mplab_platform/bin/mdb.sh"
};

const char * hexfile=ΨΛΩ, *cmdfile=ΨΛΩ; bool hw=true;

char8₋t * stpcpy(char8₋t * dst, const char * src) { while ((*dst++ = *src++)) {
} return --dst; }

inexorable Registerset Selected()
{
  Registerset regset = defaults.registers;
  const char * device = getenv("__PDB_CURRDEV");
  if (device == ΨΛΩ) { mfprint("pdb: environment error\n"); }
  if (IsPrefixOrEqual(device,"PIC32MZ")) { regset = Registerset::pic32mzda; }
  if (IsPrefixOrEqual(device,"PIC32MM")) { regset = Registerset::pic32mm; }
  return regset;
}

inexorable const char * Device()
{
   const char * device = defaults.device, *device₋env = getenv("PDBDEVICE");
   if (device₋env) device = device₋env;
   if (setenv("__PDB_CURRDEV",device,1)) {
     mfprint("pdb: environment error\n"); exit(1); }
   return device;
}

inexorable
void
UserkeyedToMdb(
  char * pdb, /* ⬷ text entered by the user. */
  char8₋t * mdb
)
{
    if (IsPrefixOrEqual(pdb,"init")) { const char * device = Device(); 
      mfprint("pdb: starts initing device ⬚\n", ﹟s7((char *)device));
      char8₋t * end=stpcpy(mdb,"device "); end=stpcpy(end,device); 
      end=stpcpy(end,"\n"); mfprint("pdb: selecting ⬚\n", 
      ﹟s7((char *)(hw ? "hardware target" : "software simulator")));
      if (hw) { end=stpcpy(end,"hwtool SK\n"); }
      else { end=stpcpy(end,"hwtool SIM\n"); }
      if (hexfile) {
        mfprint("Programming ⬚\n",﹟s7((char *)hexfile)); end=stpcpy(end,"sleep 9000\n");
        end=stpcpy(end,"program '"); end=stpcpy(end,hexfile); end=stpcpy(end,"'\n");
      }
      if (hw) { mfprint("Resetting\n"); end=stpcpy(end,"reset MCLR\n"); }
      return;
    } /* to reprogram, enter 'init' at pdb prompt. */
    Registerset regset = Selected();
    switch (regset) {
    case Registerset::pic32mm:
      if (IsPrefixOrEqual(pdb, "userlocal")) stpcpy(mdb, "print /d UserLocal\n");
#include "input-mm.cxx"
      else if (IsPrefixOrEqual(pdb, "ancfg")) stpcpy(mdb, "print /d Ancfg\n");
      else stpcpy(mdb,pdb);
    break; case Registerset::pic32mzda:
      if (IsPrefixOrEqual(pdb, "index")) stpcpy(mdb, "print /d Index\n");
#include "input-mz.cxx"
      else if (IsPrefixOrEqual(pdb, "cfgmpll")) stpcpy(mdb, "print /d cfgmpll\n");
      else stpcpy(mdb,pdb);
    }
}

AnnotatedRegister AR_MipsOrMicrochip_LAST;

Prefix mm_prefixes[] = {
  { "Compare=", AR_MipsMM_Compare },
#include "parse-mm.cxx"
  { ΨΛΩ, AR_MipsOrMicrochip_LAST }
};

Prefix mz_prefixes[] = {
  { "Index=", AR_Mips_Index },
  { "Random=", AR_Mips_Random },
#include "parse-mz.cxx"
  { "devid=", AR_Microchip_DEVID },
  { ΨΛΩ, AR_MipsOrMicrochip_LAST }
};

inexorable
void
MdbToUserscreen(
  char * mdb /* ⬷ text emitted from mdb. */
)
{ 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 char *text=mdb; 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 int virgin=true; 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 int si=0;
    auto feeder = ^(unsigned short * digit) {
      auto utf8byte = (unsigned short)*(text + si++);
      if (utf8byte == '\n') return virgin ? NumericOpinionCancel : 
        NumericOpinionCommit;
      auto asciidigit = ^(char32̄_t u) { return 0x30 <= u && u < 0x40; };
      if (asciidigit(utf8byte)) { *digit = (unsigned short)(utf8byte - '0');
        virgin = false; return NumericOpinionAccept; }
      if (utf8byte == U'-') return NumericOpinionNegate;
      if (utf8byte == 1) return virgin ? NumericOpinionReject :
        NumericOpinionCommit;
      return NumericOpinionReject;
    };
    
    auto strlen = ^(const char *s) { const char *p=s; while (*s) ++s; return s-p; };
    
    auto out = ^(const char * prefix, const AnnotatedRegister& reg) {
      int len = strlen(prefix); text += len;
      Opt<__builtin_int_t> regOpt = CastTextToNumeric(feeder);
      __builtin_int_t regval = *regOpt;
      extern void Output(const AnnotatedRegister * ar, uint32_t value, int is₋sixteen);
      if (regval) { Output(&reg,regval,false); }
      else { mfprint("Error presenting `⬚`\n", ﹟s7((char *)prefix)); }
    };
    
    Registerset regset = Selected();
    
    Prefix * transl = ΨΛΩ; switch (regset) {
    case Registerset::pic32mm: transl=mm_prefixes; break;
    case Registerset::pic32mzda: transl=mz_prefixes; break;
    }
    
    for (int i=0; ; i+=1) { if (transl[i].prefix == ΨΛΩ) { mfprint(
   "⬚", ﹟s7(text)); return; } if (IsPrefixOrEqual(text,transl[i].prefix)) { 
      out(transl[i].prefix,transl[i].reg); }
    }
}

#define ⁺⁼ProcessCommandline()                                              \
auto process_commandline = ^{ int j;                                        \
  for (j=1; j<argc && (argv[j][0] == '-' || argv[j][0] == '@'); j+=1) {     \
    if (argv[j][0] == '@' && argv[j][1] != '\x0') { cmdfile=&(argv[j][1]);  \
     continue; }                                                            \
    switch (argv[j][1]) {                                                   \
    case 'h': print("Usage: ⬚ [ -s ] [ ⬚ ] ⬚\n", ﹟s7((char *)argv[0]),     \
    ﹟s7((char *)"@commandfile"),﹟s7((char *)"[ program.hex ]")); exit(1); \
    case 's': hw=false; break;                                              \
    default: print("Unknown command-line argument\n"); exit(2);             \
    }                                                                       \
  }                                                                         \
  if (j == argc - 1) { hexfile = argv[j]; }                                 \
}; process_commandline();

int
main(
  int argc,
  const char * argv[]
)
{ /* stdin=0 (mdb output), stdout=1 () and stderr=2 (output to user) */
    int status=0; int fd_p2c[2], fd_c2p[2]; int 🥈 maxline=4096; 
    ⁺⁼ProcessCommandline(); const char * device = Device();
    print("pdb (⬚), revision ⬚ (^-c to quit.)\n\n", ﹟s7((char *)device), ﹟s7((char *)SHA1GIT));
    if (pipe(fd_p2c) == -1 || pipe(fd_c2p) == -1) {
      mfprint("pdb: Error when pipe\n"); exit(1); }
    pid_t pid = fork();
    if (pid == -1) { mfprint("pdb: Error when fork\n"); exit(1); }
    if (pid) { int len; /* Parent ⤐ */ 
        close(fd_p2c[0 /* ⬷ not STDIN_FILENO! */]);
        close(fd_c2p[1 /* ⬷ not STDOUT_FILENO! */]);
        /* when 'left is fd_p2c STDOUT_FILENO, fd_p2c STDERR_FILENO, 
          fd_c2p STDIN_FILENO and fd_c2p STDERR_FILENO': */
   // close(fd_p2c[2]); close(fd_c2p[2]);
        pid_t pid₂ = fork();
        if (pid₂ == -1) { mfprint("pdb: Error when child forks\n"); exit(1); }
/* parent */ if (pid₂) { char output[maxline]; /* ⬷ reading text emitted on mdb's stdout */ 
          for (;;) {
            if ((len = read(fd_c2p[0],output,maxline)) < 0) {
             mfprint("pdb: Error when reading mdb\n"); exit(1); }
            output[len] = '\x0'; MdbToUserscreen(output);
          }
/* child */ } else { char keytext[maxline]; /* ⬷ collecting keyputs on stdin. */
          char8₋t mdbline[maxline];
          auto send = ^(int fd, char8₋t * s) {
           int len = Utf8BytesUntilZero(s,BUILTIN₋INT₋MAX);
           if (write(fd,s,len) != len) {
             mfprint("pdb: Error when writing to mdb\n");
             exit(1);
           } };
          const char * startup = "init\n"; int stdout₋term = fd_p2c[1];
          UserkeyedToMdb((char *)startup,mdbline); send(stdout₋term,mdbline);
          while ((len = read(STDIN_FILENO,&keytext,maxline)) > 0) {
            keytext[len] = '\x0'; 
            UserkeyedToMdb(keytext,mdbline);
            send(stdout₋term,mdbline);
          }
       }
       
       close(fd_c2p[0]); close(fd_p2c[1]);
       /* waitpid(pid, &status, 0); */
       
    } else { /* Child ⤐ */
       if (dup2(fd_p2c[0], 0) != 0 ||
           close(fd_p2c[0])   != 0 ||
           close(fd_p2c[1])   != 0)
       {
         mfprint("pdb: Error when setting up childs' standard input\n");
         exit(1);
       }
       if (dup2(fd_c2p[1], 1) != 1 ||
           close(fd_c2p[1])   != 0 ||
           close(fd_c2p[0])   != 0)
       {
         mfprint("pdb: Error when setting up childs' standard output\n");
         exit(1);
       }
       const char * mdbpath = defaults.mdbpath;
       const char * mdbpath₋env = getenv("MDBPATH");
       if (mdbpath₋env) mdbpath = mdbpath₋env;
       mfprint("pdb: Starting ⬚\n", ﹟s7((char *)mdbpath));
       /* if (cmdfile) { "loadscript ./target_mz" } */
       status = execlp(mdbpath, "", (char *)ΨΛΩ);
       if (status == -1) { mfprint("pdb: Error when execlp\n"); exit(1); }
       fflush(stdout);
    }
    
    return status;
}

/*
 
 To view a man page, write 'nroff -man pdb.1'
 …and 'groff -man  pdb.1 > pdb.ps' to generate a printable.
 
 */

/* ~/Projects/Monitor/Apps/bin/mdb.sh setup_mzda_simulator 2>/dev/null
~/Projects/Monitor/Apps/bin/mdb.sh setup_mzda_target 2>/dev/null */


