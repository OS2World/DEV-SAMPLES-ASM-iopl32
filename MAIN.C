/***************************************************************************
****  This source demonstrate, how you can access I/O ports with IBM C Set/2.
****
****  The IO.ASM source is 16 bit. If you translate it to 32 bit, I/O will be
****  much faster.
****
****  IO.ASM can also used with Microsoft C 6.0.
****
****  The MAIN.C must be linked with OS2.LIB from Microsoft C 6.0 which
****  includes the 16-bit DosPortAccess() funktion.
****
****  Example:    I 3F8          Read a byte from I/O address 3F8
****              O 3F8 0D       Write byte 0D to I/O address 3F8
****
****  Thomas Gigge, SKY-NET Inc. Germany, CompuServe 100031,470
***************************************************************************/

#include "os2def.h"

#include "stdio.h"

APIRET16 APIENTRY16 RPORT(USHORT);
void APIENTRY16 WPORT(USHORT,USHORT);
APIRET16 APIENTRY16 DosPortAccess(USHORT,USHORT,USHORT,USHORT);

main()
{
   int base,value,rc;
   char str[80];

   setbuf(stdout,NULL);

   /* I/O access from 000h to FFFh */
   rc=DosPortAccess(0,0,0x000,0xFFF);
   if (rc) printf("DosPortAccess()=%d\n",rc);

   for (;;) {
      printf("[I/O] [ADDRESS] [VALUE] ? ");
      gets(str);
      strupr(str);

      switch (str[0]) {
         case 'I':sscanf(&str[1],"%x",&base);
                  value=RPORT(base);
                  printf("%02X\n",value);
                  break;
         case 'O':sscanf(&str[1],"%x %x",&base,&value);
                  WPORT(base,value);
                  break;
         default: printf("What?\n");
                  break;
         }
      }
}
