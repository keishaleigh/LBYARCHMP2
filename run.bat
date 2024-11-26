nasm -f win64 MP_asm.asm
gcc -c MP_C.c -o MP_C.obj -m64
gcc MP_C.obj MP_asm.obj -o MP_C.exe -m64
MP_C.exe