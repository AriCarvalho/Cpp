PWD=$(pwd)

rm -fr "build/lin/x86/Release"
mkdir -p "build/lin/x86/Release"
mkdir -p "dist/lin/x86/Release"
#gcc -S asm.c -masm=intel -m32 -o "asm32.s"
g++ -c asm32.s -m32 -o build/lin/x86/Release/asm32.o
g++  main.cpp build/lin/x86/Release/asm32.o -masm=intel -m32 -o "dist/lin/x86/Release/main"
chmod +x dist/lin/x86/Release/main
./dist/lin/x86/Release/main
echo $?

rm -fr "build/lin/amd64/Release"
mkdir -p "build/lin/amd64/Release"
mkdir -p "dist/lin/amd64/Release"
#gcc -S asm.c -masm=intel -m64 -o "asm64.s"
g++ -c asm64.s -m64 -o build/lin/amd64/Release/asm64.o
#g++  main.cpp asm64.o -masm=intel -m64 -o "main64s" -static
g++  main.cpp build/lin/amd64/Release/asm64.o -masm=intel -m64 -o "dist/lin/amd64/Release/main" 
chmod +x dist/lin/amd64/Release/main
./dist/lin/amd64/Release/main
echo $?
