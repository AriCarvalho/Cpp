
	.section .data
value1:
	.ascii "This is a test string.\n"

	.section .bss
	.lcomm output,23

	.section .text
	.global main
main:
	nop
	leal value1,%esi
	leal output,%edi
	movsb
	movsw
	movsl

	movl $1,%eax
	movl $0,%ebx
	int $0x80