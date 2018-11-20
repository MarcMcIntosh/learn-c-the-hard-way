+ gbd
+ lldb
+ valgrind
+ AddressSanitizer
+ [splint](https://www.splint.org/)

using gdb
```sh
gdb appname
r
#(wait for segfault)
bt full
```

using the compiler
```sh
CFLAGS="$CFLAGS -O0 -fbuiltin -g"
```
finding what libaries are in use
```
strace -eopen appname
```
