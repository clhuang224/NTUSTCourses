# 本程式讓使用者輸入身分證字號，並驗證格式是否合法
.data
	askId: .asciiz "Please input an identification number:\n"
	resultP: .asciiz "The number is legal."
	resultN: .asciiz "The number is illegal."
	id: .asciiz ""
.text
main:
	li $v0, 4			# 提示輸入身份證字號
	la $a0, askId
	syscall
	li $v0, 8			# 輸入身分證字號
	la $a0, id
	li $a1, 12
	syscall

	la $t0, id
letter:	lb $t1, 0($t0)			# 處理英文字母部分
	addi $t8, $t1, -87		# ASCII code >= 'W'
	bgez $t8, letterW
	addi $t8, $t1, -80		# ASCII code >= 'P'
	bgez $t8, letterP
	addi $t8, $t1, -79		# ASCII code >= 'O'
	bgez $t8, letterO
	addi $t8, $t1, -76		# ASCII code >= 'L'
	bgez $t8, letterL
	addi $t8, $t1, -74		# ASCII code >= 'J'
	bgez $t8, letterJ
	addi $t8, $t1, -73		# ASCII code >= 'I'
	bgez $t8, letterI
	letterA:	add $t8, $t1, -65
		li $t1, 0x10		# 轉換A~H為題目中的編號
		add $t1, $t1, $t8
		j end
	letterI:	li $t1, 0x34		# 轉換I為題目中的編號
		j end
	letterJ:	li $t1, 0x18		# 轉換J~K為題目中的編號
		add $t1, $t1, $t8
		j end
	letterL:	li $t1, 0x20		# 轉換L~N為題目中的編號
		add $t1, $t1, $t8
		j end
	letterO:	li $t1, 0x35		# 轉換O為題目中的編號
		j end
	letterP:	li $t1, 0x23		# 轉換P~V為題目中的編號
		add $t1, $t1, $t8
		j end
	letterW:	li $t1, 0x32		# 轉換W~Z為題目中的編號
		add $t1, $t1, $t8	
end:	and $t6, $t6, $zero		# sum = 0
	srl $t2, $t1, 4			# sum += 題目中的a0
	add $t6, $t6, $t2
	li $t3, 9			# 權重 = 9
	andi $t2, $t1, 0xF		# sum += 題目中的a1 * 權重
	mul $t4, $t2, $t3
	add $t6, $t6, $t4
	addi $t0, $t0, 1		# index ++
	addi $t3, $t3, -1		# 權重--
	
digit:	lb $t1, 0($t0)			# 處理數字部分
	li $t8, '\n'
	beq $t3, $zero, result		# while (t1 != '\n')
		add $t1, $t1, -48	#	ASCII code 轉換為數字
		mul $t4, $t1, $t3	#	sum += 字元 * 權重
		add $t6, $t6, $t4	
		addi $t3, $t3, -1	#	權重--
		addi $t0, $t0, 1	# 	index++
	j digit

result:
	add $t1, $t1, -48
	add $t6, $t6, $t1		# sum += 題目中的a10
	
	li $t5, 10			# remainder = t6 % t5
	div $t6, $t5
	mfhi $t7
	
	li $v0, 4
	beq $t7, $zero, legal		# if (remainder != 0)
	illegal:	la $a0, resultN		#	 cout << resultN
		syscall
		j exit
	legal:	la $a0, resultP		# else
		syscall			#	cout << resultP
	
exit:	li $v0, 10			# 程式結束
	syscall