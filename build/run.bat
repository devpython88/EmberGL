cd build
ninja -j4
if errorlevel 0 (
    .\test.exe
)
cd..