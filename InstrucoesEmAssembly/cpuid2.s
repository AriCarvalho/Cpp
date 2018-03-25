# ----------------------------------------------------------------------------------------
# Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
# To assemble and run:
#
#     gcc -c hello.s && ld hello.o && ./a.out
#
# or
#
#     gcc -nostdlib hello.s && ./a.out
# ----------------------------------------------------------------------------------------

	.section .data

output:
	.asciz "The processor Vendor ID is '%s' \n"
      
.section .bss
	.lcomm buffer,12
	
       .section .text
        .globl main 
main:
	movl $0, %eax
	cpuid
	movl $buffer,%edi
	movl %ebx,(%edi)
	movl %edx,4(%edi)
	movl %ecx,8(%edi)
	push $buffer
	push $output
	call printf
	add $8, %esp
	push $0
	call exit
