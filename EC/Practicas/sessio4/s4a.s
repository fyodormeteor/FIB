	.data
signe:		.word 0
exponent:	.word 0
mantissa:	.word 0
cfixa:		.word 0x7fffffff #0x87D18A00
cflotant:	.float 0.0

	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)

	la	$t0, cfixa
	lw	$a0, 0($t0)
	la	$a1, signe
	la	$a2, exponent
	la	$a3, mantissa
	jal	descompon

	la	$a0, signe
	lw	$a0,0($a0)
	la	$a1, exponent
	lw	$a1,0($a1)
	la	$a2, mantissa
	lw	$a2,0($a2)
	jal	compon

	la	$t0, cflotant
	swc1	$f0, 0($t0)

	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr	$ra

descompon:
	slti 	$t0, $a0, 0
	sw 	$t0, 0($a1)
	sll 	$a0, $a0, 1
	
	bne 	$a0, $zero, else
	move 	$t8, $zero		# $t8 <- exp
	b 	endif
else:	
	li 	$t8, 18
while:	blt 	$a0, $zero, endwhile
	sll 	$a0, $a0, 1
	addiu 	$t8, $t8, -1
	b 	while
endwhile:
	srl 	$a0, $a0, 8
	li 	$t0, 0x7FFFFF
	and 	$a0, $a0, $t0
	addiu 	$t8, $t8, 127
endif:
	sw 	$t8, 0($a2)
	sw 	$a0, 0($a3)
	
	jr 	$ra
	
compon:
	sll 	$a0, $a0, 31
	sll 	$a1, $a1, 23
	or 	$t0, $a1, $a2
	or 	$t0, $t0, $a0
	mtc1 	$t0, $f0
	
	jr $ra