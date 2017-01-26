@echo off
del /p /s /f *.exe
del /p /s /f *.out
for /f "delims=" %d in <'dir /s /b /ad ^|sort /r'> do rd "%d"
PAUSE