main:
	gcc -m32 -o exploit exploit.c macros.h
	gcc -m32 -fno-stack-protector -z execstack -o stack stack.c macros.h
	chmod 755 stack 

shellcode:
	gcc -m32 -fno-stack-protector -z execstack -o test_shellcode test_shellcode.c