	.arch armv7
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"test.c"
	.text
	.global	var0
	.align	2
	.type	var0, %object
	.size	var0, 32
var0:
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.global	var1
	.align	2
	.type	var1, %object
	.size	var1, 32
var1:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.word	7
	.word	8
	.global	var2
	.align	2
	.type	var2, %object
	.size	var2, 32
var2:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.word	7
	.word	8
	.global	var3
	.align	2
	.type	var3, %object
	.size	var3, 32
var3:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.word	7
	.word	8
	.global	var4
	.align	2
	.type	var4, %object
	.size	var4, 32
var4:
	.word	1
	.word	2
	.word	3
	.word	0
	.word	5
	.word	0
	.word	7
	.word	8
	.global	var5
	.data
	.align	2
	.type	var5, %object
	.size	var5, 4
var5:
	.word	10
	.global	var6
	.align	2
	.type	var6, %object
	.size	var6, 40
var6:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	5
	.word	4
	.word	3
	.word	2
	.word	1
	.comm	var7,40,4
	.text
	.align	1
	.global	getint
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	getint, %function
getint:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
