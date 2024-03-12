# Exercici 2.2
# 12.03.2024
#
# https://github.com/fyodormeteor

	.data
result: .word 0
num:	.byte '7'

	.text
	.globl main
main:

	la 	$t0, num
	lb 	$t0, 0($t0)
	
	slti 	$t1, $t0, 'a'
	slti 	$t1, $t1, 1
	
	li 	$t2, 'z'
	slt 	$t2, $t2, $t0
	slti 	$t2, $t2, 1
	and 	$t1, $t1, $t2
	
	slti 	$t2, $t0, 'A'
	slti 	$t2, $t2, 1
	
	li	$t3, 'Z'
	slt 	$t3, $t3, $t0
	slti 	$t3, $t3, 1
	and	$t2, $t2, $t3
	
	or	$t1, $t1, $t2
	
	li	$t2, 1
	blt	$t1, $t2, else1
	
	move 	$s0, $t0
	b 	endif1
else1:	
	slti 	$t1, $t0, '0'
	slti 	$t1, $t1, 1
	
	li 	$t2, '9'
	slt 	$t2, $t2, $t0
	slti 	$t2, $t2, 1
	
	and 	$t1, $t1, $t2
	
	li 	$t2, 1
	blt 	$t1, $t2, else2
	
	addiu 	$s0, $t0, -48
	b 	endif1
else2:	
	li 	$s0, -1
endif1:
	la 	$t0, result
	sw 	$s0, 0($t0)
	
	jr $ra
