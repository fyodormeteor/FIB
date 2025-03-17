.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	# elementos en 12 (ebp)
	# i en -8 (ebp)
	# res en -4 (%ebp)
	# salva registros seguros
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax	# eax <- @Vector
	movl	(%eax), %eax	# eax <- Vector[0]
	movl	%eax, -4(%ebp)	# res = Vector [0]
# Aqui has de introducir el codigo
	movl $1, %esi			# i = 1
for:
	cmpl 12(%ebp), %esi
	jge endfor				# si i >= elementos, acabar bucle
if:	
	movl	4(%ebp, %esi, 4), %eax # eax <- Vector[i-1]
	movl	8(%ebp, %esi, 4), %ebx # ebx <- Vector[i]
	cmpl	%ebx, %eax			
	jne		endif			# si Vector[i] != Vector[i-1], acabar if
then:
	movl	%esi, -4(%ebp)	# res = i
endif:	
	incl %esi				# i++
	jmp for
endfor:
# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret