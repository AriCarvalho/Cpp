
	.section .data
value1:
	.float 20.5
value2:
	.float 10.90
	
	.section .text
	.global main
main:
	nop
	finit
	flds value1
	flds value2
	fcomi %st(1),%st(0)
	fcmovb %st(1),%st(0)

	movl $1,%eax
	movl $0,%ebx
	int $0x80
	