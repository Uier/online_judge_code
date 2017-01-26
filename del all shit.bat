@echo off
del /s /f *.exe
del /s /f *.out
for /f "delims=" %d in <'dir /s /b /ad ^|sort /r'> do rd "%d"
PAUSE