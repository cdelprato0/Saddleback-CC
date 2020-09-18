set projectName=masm3
\masm32\bin\ml /c /coff /Zi /Fl %projectName%.asm
\masm32\bin\ml /c /coff /Zi /Fl StringFunctions.asm
\masm32\bin\Link /SUBSYSTEM:CONSOLE %projectName%.obj StringFunctions.obj ..\macros\kernel32.lib ..\macros\convutil201604.obj ..\macros\utility201609.obj ..\..\Irvine\Kernel32.lib ..\..\Irvine\Irvine32.lib ..\..\Irvine\User32.lib