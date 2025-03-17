 .text
	.align 4
	.globl Insertar
	.type Insertar,@function
Insertar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp 

	movl	$0, -12(%ebp)
	movl	$-1, -4(%ebp)
do1:	
if1:
	imul	$12, -12(%ebp), %eax 	# eax = 12i
	addl	8(%ebp), %eax			# eax = v + 12i
	movl	16(%ebp), %ecx			# ecx = X.k
	cmpl	4(%eax), %ecx
	jge		else1					# jump si (X.k >= v[i].k)
	movl	-12(%ebp), %eax			# eax = i
	movl	%eax, -4(%ebp)			# lug = i
	jmp		enddo1					# break
else1:
	incl	-12(%ebp)
	imul	$12, -12(%ebp), %eax 	# eax = 12i
	addl	8(%ebp), %eax			# eax = v + 12i
	cmpl	$0x80000000, 4(%eax)
	jne		do1						# jump si (v[i].k != 0x8..)
enddo1:
if2:
	imul	$12, -12(%ebp), %eax 	# eax = 12i
	addl	8(%ebp), %eax			# eax = v + 12i
	cmpl	$0x80000000, 4(%eax)
	jne		else2					# jump si (v[i].k != 0x8..)
	movl	-12(%ebp), %eax			# eax = i
	movl	%eax, -4(%ebp)			# lug = i
else2:
while1:
	imul	$12, -12(%ebp), %eax 	# eax = 12i
	addl	8(%ebp), %eax			# eax = v + 12i
	cmpl	$0x80000000, 4(%eax)
	je		endwhile1				# jump si (v[i].k == 0x8..)
	incl	-12(%ebp)				# i++
	jmp		while1
endwhile1:
	movl	-12(%ebp), %eax			# eax = i
	movl	%eax, -8(%ebp)			# j = i
for1:
	movl	-8(%ebp), %eax			# eax = j
	cmpl	-4(%ebp), %eax
	jl		endfor1					# jump si (j < lug)
	imul	$12, -8(%ebp), %eax 	# eax = 12j
	addl	8(%ebp), %eax			# eax = v + 12j

	movb	(%eax), %cl
	movb	%cl, 12(%eax)

	movl	4(%eax), %ecx
	movl	%ecx, 16(%eax)

	movl	8(%eax), %ecx
	movl	%ecx, 20(%eax)

	subl	$1, -8(%ebp)			# j--
	jmp		for1
endfor1:
	pushl	-4(%ebp)				# "pos"
	pushl	20(%ebp)
	pushl	16(%ebp)
	pushl	12(%ebp)				# "X"
	pushl	8(%ebp)					# "v"
	call	Asignar
	subl	$20, %esp
	movl	-12(%ebp), %eax
	incl	%eax
	
	movl	%ebp, %esp
	popl	%ebp
	ret