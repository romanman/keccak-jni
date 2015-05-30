

1. create javah bridge
`javah -d ./jni -cp ./src/main keccak.KeccakJNI`

2. implement the keccak_KeccakJNI.c

3. set compile env
set gcc_run=C:\mingw-w64\mingw64\bin\gcc.exe

set PATH=%PATH%;C:\mingw-w64\i686-4.9.2-posix-dwarf-rt_v4-rev2\mingw32\bin
set PATH=%PATH%;%JAVA_HOME%\bin
set PATH=%PATH%;%JAVA_HOME%\include\win32


4. compile and link the libs
%gcc_run% -m64  -D __int64="long long" -Wl,--add-stdcall-alias -I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32" -shared -o keccak.dll keccak-orig.dll keccak_KeccakJNI.c


