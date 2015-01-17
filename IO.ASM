          .286

IO_TEXT   segment   word public 'CODE'
          assume    cs:IO_TEXT

          public    WPORT
WPORT     proc      far

          push bp
          mov  bp,sp
          push ax
          push dx

          mov  ax,[bp+6]
          mov  dx,[bp+8]
          out  dx,al

          pop  dx
          pop  ax
          pop  bp

          ret  4

WPORT     endp

          public    RPORT
RPORT     proc      far

          push bp
          mov  bp,sp
          push dx

          mov  dx,[bp+6]
          in   al,dx
          xor  ah,ah

          pop  dx
          pop  bp

          ret  2

RPORT     endp


IO_TEXT   ends

          end
