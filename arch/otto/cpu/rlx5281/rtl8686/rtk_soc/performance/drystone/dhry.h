/*
 **************************************************************************
 *                       DHRYSTONE 2.1 BENCHMARK PC VERSION
 **************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *                                                                            
 *  Version:    C, Version 2.1
 *                                                                            
 *  File:       dhry.h (part 1 of 3)
 *
 *  Date:       May 25, 1988
 *
 *  Author:     Reinhold P. Weicker
 *                      Siemens AG, AUT E 51
 *                      Postfach 3220
 *                      8520 Erlangen
 *                      Germany (West)
 *                              Phone:  [+49]-9131-7-20330
 *                                      (8-17 Central European Time)
 *                              Usenet: ..!mcsun!unido!estevax!weicker
 *
 *            Original Version (in Ada) published in
 *            "Communications of the ACM" vol. 27., no. 10 (Oct. 1984),
 *            pp. 1013 - 1030, together with the statistics
 *            on which the distribution of statements etc. is based.
 *
 *            In this C version, the following C library functions are used:
 *            - strcpy, strcmp (inside the measurement loop)
 *            - printf, scanf (outside the measurement loop)
 *            In addition, Berkeley UNIX system calls "times ()" or "time ()"
 *            are used for execution time measurement. For measurements
 *            on other systems, these calls have to be changed.
 *
 *  Collection of Results:
 *              Reinhold Weicker (address see above) and
 *              
 *              Rick Richardson
 *              PC Research. Inc.
 *              94 Apple Orchard Drive
 *              Tinton Falls, NJ 07724
 *                      Phone:  (201) 389-8963 (9-17 EST)               
 *                      Usenet: ...!uunet!pcrat!rick
 *
 *      Please send results to Rick Richardson and/or Reinhold Weicker.
 *      Complete information should be given on hardware and software used.
 *      Hardware information includes: Machine type, CPU, type and size
 *      of caches; for microprocessors: clock frequency, memory speed
 *      (number of wait states).
 *      Software information includes: Compiler (and runtime library)
 *      manufacturer and version, compilation switches, OS version.
 *      The Operating System version may give an indication about the
 *      compiler; Dhrystone itself performs no OS calls in the measurement
 *      loop.
 *
 *      The complete output generated by the program should be mailed
 *      such that at least some checks for correctness can be made.
 *
 **************************************************************************
 *
 *  This version has changes made by Roy Longbottom to conform to a common
 *  format for a series of standard benchmarks for PCs:
 *
 *  Running time greater than 5 seconds due to inaccuracy of the PC clock.
 *
 *  Automatic adjustment of run time, no manually inserted parameters.
 *
 *  Initial display of calibration times to confirm linearity.
 *
 *  Display of results within one screen (or at a slow speed as the test
 *  progresses) so that it can be seen to have run successfully. 
 *
 *  Facilities to type in details of system used etc.
 *
 *  All results and details appended to a results file.
 *
 *
 *  Roy Longbottom
 *  101323.2241@compuserve.com
 *
 **************************************************************************
 *
 *  For details of history, changes, other defines, benchmark construction
 *  statistics see official versions from ftp.nosc.mil/pub/aburto where
 *  the latest table of results (dhry.tbl) are available. See also
 *  netlib@ornl.gov
 *
 **************************************************************************
 *
 * Defines:     The following "Defines" are possible:
 *              -DREG=register          (default: Not defined)
 *                      As an approximation to what an average C programmer
 *                      might do, the "register" storage class is applied
 *                      (if enabled by -DREG=register)
 *                      - for local variables, if they are used (dynamically)
 *                        five or more times
 *                      - for parameters if they are used (dynamically)
 *                        six or more times
 *                      Note that an optimal "register" strategy is
 *                      compiler-dependent, and that "register" declarations
 *                      do not necessarily lead to faster execution.
 *              -DNOSTRUCTASSIGN        (default: Not defined)
 *                      Define if the C compiler does not support
 *                      assignment of structures.
 *              -DNOENUMS               (default: Not defined)
 *                      Define if the C compiler does not support
 *                      enumeration types.
 ***************************************************************************
 *
 *  Compilation model and measurement (IMPORTANT):
 *
 *  This C version of Dhrystone consists of three files:
 *  - dhry.h (this file, containing global definitions and comments)
 *  - dhry_1.c (containing the code corresponding to Ada package Pack_1)
 *  - dhry_2.c (containing the code corresponding to Ada package Pack_2)
 *
 *  The following "ground rules" apply for measurements:
 *  - Separate compilation
 *  - No procedure merging
 *  - Otherwise, compiler optimizations are allowed but should be indicated
 *  - Default results are those without register declarations
 *  See the companion paper "Rationale for Dhrystone Version 2" for a more
 *  detailed discussion of these ground rules.
 *
 *  For 16-Bit processors (e.g. 80186, 80286), times for all compilation
 *  models ("small", "medium", "large" etc.) should be given if possible,
 *  together with a definition of these models for the compiler system used.
 *
 **************************************************************************
 *                Examples of Pentium Results
 *
 * Dhrystone Benchmark  Version 2.1 (Language: C)
 *
 * Month run            4/1996
 * PC model             Escom
 * CPU                  Pentium
 * Clock MHz            100
 * Cache                256K
 * Options              Neptune chipset
 * OS/DOS               Windows 95
 * Compiler             Watcom C/ C++ 10.5 Win386 
 * OptLevel             -otexan -zp8 -fp5 -5r
 * Run by               Roy Longbottom
 * From                 UK
 * Mail                 101323.2241@compuserve.com
 * 
 * Final values         (* implementation-dependent):
 *
 * Int_Glob:      O.K.  5
 * Bool_Glob:     O.K.  1
 * Ch_1_Glob:     O.K.  A
 * Ch_2_Glob:     O.K.  B
 * Arr_1_Glob[8]: O.K.  7
 * Arr_2_Glob8/7: O.K.     1600010
 * Ptr_Glob->  
 *   Ptr_Comp:       *  98008
 *   Discr:       O.K.  0
 *   Enum_Comp:   O.K.  2
 *   Int_Comp:    O.K.  17
 *   Str_Comp:    O.K.  DHRYSTONE PROGRAM, SOME STRING
 * Next_Ptr_Glob-> 
 *   Ptr_Comp:       *  98008 same as above
 *   Discr:       O.K.  0
 *   Enum_Comp:   O.K.  1
 *   Int_Comp:    O.K.  18
 *   Str_Comp:    O.K.  DHRYSTONE PROGRAM, SOME STRING
 * Int_1_Loc:     O.K.  5
 * Int_2_Loc:     O.K.  13
 * Int_3_Loc:     O.K.  7
 * Enum_Loc:      O.K.  1
 * Str_1_Loc:     O.K.  DHRYSTONE PROGRAM, 1'ST STRING
 * Str_2_Loc:     O.K.  DHRYSTONE PROGRAM, 2'ND STRING
 *
 * Register option      Selected.
 * 
 * Microseconds 1 loop:          4.53
 * Dhrystones / second:      220690
 * VAX MIPS rating:            125.61
 *
 *
 * Dhrystone Benchmark  Version 2.1 (Language: C)
 *
 * Month run            4/1996
 * PC model             Escom
 * CPU                  Pentium
 * Clock MHz            100
 * Cache                256K
 * Options              Neptune chipset
 * OS/DOS               Windows 95
 * Compiler             Watcom C/ C++ 10.5 Win386 
 * OptLevel                 No optimisation
 * Run by               Roy Longbottom
 * From                 UK
 * Mail                 101323.2241@compuserve.com
 * 
 * Final values         (* implementation-dependent):
 *
 * Int_Glob:      O.K.  5
 * Bool_Glob:     O.K.  1
 * Ch_1_Glob:     O.K.  A
 * Ch_2_Glob:     O.K.  B
 * Arr_1_Glob[8]: O.K.  7
 * Arr_2_Glob8/7: O.K.      320010
 * Ptr_Glob->  
 *   Ptr_Comp:       *  98004
 *   Discr:       O.K.  0
 *   Enum_Comp:   O.K.  2
 *   Int_Comp:    O.K.  17
 *   Str_Comp:    O.K.  DHRYSTONE PROGRAM, SOME STRING
 * Next_Ptr_Glob-> 
 *   Ptr_Comp:       *  98004 same as above
 *   Discr:       O.K.  0
 *   Enum_Comp:   O.K.  1
 *   Int_Comp:    O.K.  18
 *   Str_Comp:    O.K.  DHRYSTONE PROGRAM, SOME STRING
 * Int_1_Loc:     O.K.  5
 * Int_2_Loc:     O.K.  13
 * Int_3_Loc:     O.K.  7
 * Enum_Loc:      O.K.  1
 * Str_1_Loc:     O.K.  DHRYSTONE PROGRAM, 1'ST STRING
 * Str_2_Loc:     O.K.  DHRYSTONE PROGRAM, 2'ND STRING
 *
 * Register option      Not selected.
 *
 * Microseconds 1 loop:         20.06
 * Dhrystones / second:       49844
 * VAX MIPS rating:             28.37
 *
 **************************************************************************
 */

/* Compiler and system dependent definitions: */

#ifndef TIME
#define TIMES
#endif
                /* Use times(2) time function unless    */
                /* explicitly defined otherwise         */

#ifdef TIMES
/* #include <sys/types.h> 
   #include <sys/times.h> */
                /* for "times" */
#endif

#define Mic_secs_Per_Second     1000000.0
                /* Berkeley UNIX C returns process times in seconds/HZ */

#ifdef  NOSTRUCTASSIGN
#define structassign(d, s)      memcpy(&(d), &(s), sizeof(d))
#else
#define structassign(d, s)      d = s
#endif

#ifdef  NOENUM
#define Ident_1 0
#define Ident_2 1
#define Ident_3 2
#define Ident_4 3
#define Ident_5 4
  typedef int   Enumeration;
#else
  typedef       enum    {Ident_1, Ident_2, Ident_3, Ident_4, Ident_5}
                Enumeration;
#endif
        /* for boolean and enumeration types in Ada, Pascal */

/* General definitions: */
/*
#include <stdio.h>
#include <string.h>*/
 #include <common.h>
 #include <exports.h>

                /* for strcpy, strcmp */

#define Null 0 
                /* Value of a Null pointer */
#define true  1
#define false 0

typedef int     One_Thirty;
typedef int     One_Fifty;
typedef char    Capital_Letter;
typedef int     Boolean;
typedef char    Str_30 [31];
typedef int     Arr_1_Dim [50];
typedef int     Arr_2_Dim [50] [50];

typedef struct record 
    {
    struct record *Ptr_Comp;
    Enumeration    Discr;
    union {
          struct {
                  Enumeration Enum_Comp;
                  int         Int_Comp;
                  char        Str_Comp [31];
                  } var_1;
          struct {
                  Enumeration E_Comp_2;
                  char        Str_2_Comp [31];
                  } var_2;
          struct {
                  char        Ch_1_Comp;
                  char        Ch_2_Comp;
                  } var_3;
          } variant;
      } Rec_Type;

typedef Rec_Type *Rec_Pointer;

