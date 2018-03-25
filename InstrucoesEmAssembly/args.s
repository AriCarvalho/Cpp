
	.section .data
data:	
	.asciz " --- %d ---"
a:
	.ascii "a"
A:
	.ascii "A"
Zero:	
	.ascii "0"

	.section .bss

	.section .text

	.globl main

main:
	movl 8(%esp),%eax # args
	movl 4(%eax),%eax # *args
	movl (%eax),%eax  # **args
	movzx %al,%ebx
	movl Zero,%eax
	movzx %al,%ecx
	subl  %ecx,%ebx
	pushl %ebx	
	pushl $data
	call printf
	addl $8,%esp
	pushl $0
	call exit
