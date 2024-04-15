# Yosif Yosif
# 04/14/2024
# Lab 8
# Familiarizing myself with MIPS assembly in order to prepare for Lab 9


#  this program calculates the sum of squares up to and including 100
           

 .text  # directive that we are in the code segment

main:
        subu $a0, $sp, 12 # We want 4 mem locations for main SP, RA, i , s
        sw $ra, 4($a0)  # we need to store the RA in the Activation record
        sw $sp, ($a0) # store SP
        move $sp, $a0  # adjust SP

        sw $0, 8($sp)  # store 0 into memory -- counting variable 
        sw $0, 12($sp)  # store 0 into memory -- accumulating variable

        li $v0, 4
        la $a0, L5 # print the prompt
        syscall

        li $v0, 5 # take the input
        syscall

        move $t5, $v0 # store the input in register $t5
 
       
loop:
        lw $t6, 8($sp)  #   
        mul $t7, $t6, $t6  #  i * i
        lw $t8, 12($sp)   #  s
        addu $t9, $t8, $t7  #  s + i*i
        sw $t9, 12($sp)  #   s= s + i*i 
        lw $t6, 8($sp)   # i 
        addu $t0, $t6, 1  # i+1
        sw $t0, 8($sp)  #  i = i + 1
        ble $t0, $t5, loop  #   keep doing it for 100 times
        nop   # 
        
        la $a0, str1
        li $v0 4  #   print first part of string
        syscall # 
        nop   # 

        move $a0, $t5
        li $v0 1 #   Print the number
        syscall

        la $a0, str2
        li $v0 4  #   print second part of string
        syscall # 
        
        lw $a0, 12($sp)
        li $v0 1 #   Print the sum
        syscall
        
       
        lw $ra, 4($sp)
        lw $sp , ($sp)  # put backl Ra and SP
        
        li $v0, 10 
        syscall     #  exit for MAIN only
        
  .data
        .align 0

str1: .asciiz "The sum from 0 .. "
str2: .asciiz " is \n"
        
L5: .asciiz "Please enter a number: "
