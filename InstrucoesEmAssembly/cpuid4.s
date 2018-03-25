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
	.ascii "The processor Vendor ID is 'xxxxxxxxxxxx' \n"
      

       .section .text
        .global _start 
_start:
	movl $0, %eax
	cpuid
	movl $output,%edi
	movl %ebx,28(%edi)
	movl %edx,32(%edi)
	movl %ecx,36(%edi)
	movl $4,%eax
	movl $1,%ebx
	cpuid
	movl $output,%edi
	movl %ebx,28(%edi)
	movl %edx,32(%edi)
	movl %ecx,36(%edi)
	movl $4,%eax
	movl $1,%ebx
	movl $output,%ecx
	movl $42,%edx
	int $0x80
	movl $1,%eax
	movl $0,%ebx
	int $0x80

