@echo off
cls
echo Setting up Ducktape for compiling...
echo Choose your generator:
echo 1) Borland Makefiles
echo 2) MSYS Makefiles
echo 3) MinGW Makefiles (Default for Windows)
echo 4) NMake Makefiles
echo 5) NMake Makefiles JOM
echo 6) Unix Makefiles (Default for Linux)
echo 7) Watcom WMake
set /P idx=Enter your option (1,2,3,4,5,6,7):
if %idx%==1 set generator=Borland Makefiles
if %idx%==2 set generator=MSYS Makefiles
if %idx%==3 set generator=MinGW Makefiles
if %idx%==4 set generator=NMake Makefiles
if %idx%==5 set generator=NMake Makefiles JOM
if %idx%==6 set generator=Unix Makefiles
if %idx%==7 set generator=Watcom WMake
cls

echo Specify your compiler:
echo (You may enter a path to your compiler or just the compiler's command name if the compiler path is already in your PATH environment variable)
set /P compiler=""
cls

mkdir build
cls
cd build
cmake -G "%generator%" -D CMAKE_CXX_COMPILER=%compiler% ..
make