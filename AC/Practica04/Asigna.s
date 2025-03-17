 .text
	.align 4
	.globl Asignar
	.type Asignar,@function
Asignar:
	pushl	%ebp
	movl	%esp, %ebp
	
	imul	$12,24(%ebp), %eax		# eax = 12*pos
	addl	8(%ebp), %eax			# eax = v + 12*pos

	movb	12(%ebp), %cl
	movb	%cl, (%eax)

	movl	16(%ebp), %ecx
	movl	%ecx, 4(%eax)

	movl	20(%ebp), %ecx
	movl	%ecx, 8(%eax)

	movl	%ebp, %esp
	popl	%ebp
	ret

