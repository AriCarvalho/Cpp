
	.section .data
	
	.section .bss

	.section .text

	.global main

main:
	mov $0x01,%eax
	mov $0x03,%ebx
	int $0x80