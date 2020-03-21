@echo off  
:loop  
    rand.exe > data.txt
    mycode.exe < data.txt > myout.txt
    std.exe < data.txt > stdout.txt
    fc myout.txt stdout.txt
if not errorlevel 1 goto loop  
pause
goto loop