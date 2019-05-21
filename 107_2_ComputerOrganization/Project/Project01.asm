# 此程式讓使用者輸入大寫英文字母字串及參數，並將字串轉換成相應的結果
.data
	askText: .asciiz "Please input the plain-text:\n"
	askParameter: .asciiz "Please input the shift parameter:\n"
	answer: .asciiz "The cipher-text is: "
	text: .asciiz ""
.text
main:
	li $v0, 4				# 提示輸入字串
	la $a0, askText
	syscall
	li $v0, 8				# 輸入字串
	la $a0, text
	li $a1, 22
	syscall
	li $v0, 4				# 提示輸入參數
	la $a0, askParameter
	syscall
	li $v0, 5				# 輸入參數
	syscall
	
	la $t0, text				# Caesar's Cipher
	li $t1, '\n'
	li $t2, ' '
loop:	lb $t3, 0($t0)				# for(int i=0; text[i] != '\n'; i++)			迴圈在遇到換行符號時結束
	beq $t3, $t1, result				# t3 = text[i]
		beq $t3, $t2, next			# if (t3 != ' ')			不處理空白鍵
			add $t3, $t3, $v0			# t3 += parameter
			add $t4, $t3, -90			# if (t3 > 90)
			bgez $t4, else
				sb $t3, 0($t0)				# text[i] = t3
				j next				# else
			else:	add $t3, $t3, -26			# t3 -= 26	
				sb $t3, 0($t0)				# text[i] = t3
	next:	addi $t0, $t0, 1
	j loop

result:
	li $v0, 4				# 印出結果
	la $a0, answer
	syscall
	la $a0, text
	syscall
	li $v0, 10				# 結束程式
	syscall
