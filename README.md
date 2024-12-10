1. Disable kernel randomized va
```
su root 
sysctl -w kernel.randomize_va_space=0
```

2. Compile
```
su root 

# -z, makes the stack executable
# -fno-stack-protector, disables the stack protector, allows for illegal memory access, allows the buffer overflow to write into the stack

gcc -o stack -z execstack -fno-stack-protector stack.c
chmod 755 stack 
```