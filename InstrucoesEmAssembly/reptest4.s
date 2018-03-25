
	.section .data
value1:
	.asciz "This is a test string. \n"
	.section .bss
	.lcomm output,24
	
	.section .text
	.global main
main:
	nop
	leal value1+22,%esi
	leal output +22,%edi
	movl $23,%ecx
	std
	rep movsb

	movl $1,%eax
	movl $0,%ebx
	int $0x80