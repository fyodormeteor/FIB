	# Sessio 3

	.data 
mat:	.word 0,0,2,0,0,0
	.word 0,0,4,0,0,0
	.word 0,0,6,0,0,0
	.word 0,0,8,0,0,0

resultat: 	.word 0
	.text 
	.globl main
main:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)
	la	$a0, mat
	
	jal suma_col
	
	la	$t0, resultat
	sw	$v0, 0($t0)
	lw	$ra, 0($sp)
	
	addiu	$sp, $sp, 4
	jr $ra
suma_col:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	li 	$t0, 0
	li 	$t1, 0 		# i = 0
	li 	$t2, 4
	move 	$t3, $a0
	addiu 	$t3, $t3, 8 	# = *p = @mat[0][2]
	
for: 	lw 	$t4, 0($t3)
	add 	$t0, $t0, $t4 	# suma += mat[i][2]
	addiu 	$t3, $t3, 24	# stride (=6*4 =24)
	addiu 	$t1, $t1, 1 	# ++i
	blt 	$t1, $t2, for
	
	move 	$v0, $t0
	
	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr $ra



