
	.section .data
value1:
	.float 10.923
value2:
	.float 11.5532

	.section .text
	.globl main
main:
	nop
	flds value1
	fcoms value2
	fstsw
	sahf
	ja greater
	jb lessthan
	movl $1,%eax
	movl $0,%ebx
	int $0x80
greater:
	movl $1,%eax
	movl $2,%ebx
	int $0x80
lessthan:
	movl $1,%eax
	movl $2,%ebx
	int $0x80