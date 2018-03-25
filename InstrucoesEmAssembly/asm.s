

	.section .data

me:
	.asciz "me %x"
mydata:
	.int 0x12345678
	
	.section .bss
	
	
	.section .text

	.globl main

main:

	movl $mydata,%eax
	
	pushl (%eax)
	pushl $me
	call printf
	addl $8,%esp

	pushl $0
	call exit