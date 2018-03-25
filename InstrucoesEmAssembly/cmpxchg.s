	.section .data

data:
	.int 10

	.section .text
	.globl main
main:
	nop
	movl $10,%eax
	movl $5, %ebx
	cmpxchg %ebx,data
	movl $1,%eax
	int $0x80