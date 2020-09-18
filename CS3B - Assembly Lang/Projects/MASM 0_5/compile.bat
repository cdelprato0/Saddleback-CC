set projectName=masm0_5
\masm32\bin\ml /c /Zd /coff %projectName%.asm
\masm32\bin\Link /SUBSYSTEM:CONSOLE %projectName%.obj
%projectName%.exe