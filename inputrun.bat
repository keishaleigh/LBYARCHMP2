nasm -f win64 MP_asm.asm
gcc -c inputC.c -o inputC.obj -m64
gcc inputC.obj MP_asm.obj -o inputC.exe -m64
inputC.exe