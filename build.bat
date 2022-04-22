@echo Compile programm...
@echo off
g++ -g .\List.cpp .\Stack.cpp .\Queue.cpp -g .\main.cpp -o .\main.exe
if %errorlevel% == 0 (@echo Run application... && @echo off && .\main.exe)