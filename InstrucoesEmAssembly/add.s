
	.section .data
OK:	
	.asciz "OK"
ERRO:
	.asciz "ERRO"
Zero:	
	.asciz "0"

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

	addb $254,%bl	
	jc over
	pushl $OK
	call printf
	addl $8,%esp
	jmp end
over:
	pushl $ERRO
	call printf
	addl $8 , %esp
end:	

	pushl $0
	call exit
