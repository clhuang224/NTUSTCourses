# 本程式讓使用者輸入兩個整數，並計算組合數
.data
	InputN: .asciiz "Please input first positive integer n:\n"
	InputK: .asciiz "Please input second positive integer k:\n"
	OutputC: .asciiz "The binomial coefficient C("
	OutputC2: .asciiz ", "
	OutputC3: .asciiz ") = "
.text
main:
	li $v0, 4		# 提示輸入n
	la $a0, InputN
	syscall
	li $v0, 5		# 輸入n
	syscall
	add $t0, $v0, $zero
	li $v0, 4		# 提示輸入k
	la $a0, InputK
	syscall
	li $v0, 5		# 輸入k
	syscall
	add $t1, $v0, $zero
	
	add $a0, $t0, $zero
	add $a1, $t1, $zero
	jal combination		# 計算C(n, k)
	add $t2, $v0, $zero
	
	li $v0, 4		# 輸出結果
	la $a0, OutputC			# "The binomial coefficient C("
	syscall
	li $v0, 1
	add $a0, $t0, $zero		# n
	syscall
	li $v0, 4
	la $a0, OutputC2		# ", "
	syscall
	li $v0, 1
	add $a0, $t1, $zero		# k
	syscall
	li $v0, 4
	la $a0, OutputC3		# ") = "
	syscall
	li $v0, 1
	add $a0, $t2, $zero		# 結果
	syscall
	li $v0, 11
	la $a0, '\n'
	syscall
	li $v0, 10		# 程式結束
	syscall

combination:	
	addi $sp, $sp, -16
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $ra, 12($sp)
	
	add $s0, $a0, $zero
	add $s1, $a1, $zero
	
	beq $s0, $s1, return1			# if(k != 0 && n!=k)
	beq $s1, $zero, return1	
	return: # C(n-1,k) + C(n-1,k-1)
		addi $a0, $s0, -1
		add $a1, $s1, $zero
		jal combination
		add $s2, $v0, $zero			# s2 = C(n-1, k)
		
		addi $a0, $s0, -1
		addi $a1, $s1, -1
		jal combination
		add $v0, $v0, $s2			# return C(n-1, k-1) + s2
		
		lw $s0, 0($sp)
		lw $s1, 4($sp)
		lw $s2, 8($sp)
		lw $ra, 12($sp)
		addi $sp, $sp, 16
		jr $ra
	return1:					# else
		li $v0, 1				# return 1
		
		lw $s0, 0($sp)
		lw $s1, 4($sp)
		lw $s2, 8($sp)
		lw $ra, 12($sp)
		addi $sp, $sp, 16
		jr $ra
