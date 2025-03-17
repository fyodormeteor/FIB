.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo

	xorl %eax, %eax				# res = 0
	xorl %esi, %esi				# i = 0
for:
	cmpl $3, %esi
	jge	endfor					# si i >= 3, acabar bucle for
	xorl %ebx, %ebx				# j = 0
for2:
	cmpl %esi, %ebx
	jg endfor2					# si j > i, acabar bucle for2
	imul $3, %esi, %ecx 		# ecx <- 3 * i
	addl %ebx, %ecx				# ecx <- 3 * i + j
	movl 8(%ebp), %edx
	addl (%edx, %ecx, 4), %eax	# res += Matriz[i][j]
	incl %ebx					# j++
	jmp for2
endfor2:
	addl 12(%ebp), %esi	# i += salto
	jmp for
endfor:
	movl %eax, -4(%ebp)
# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret