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
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	main, %function
main:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	这儿缺少了下标为0的代码:		j!=		#1	#0	imcode 2
	这儿缺少了下标为1的代码:		jmp				imcode 7
	这儿缺少了下标为2的代码:		j!=		#2	#0	imcode 4
	这儿缺少了下标为3的代码:		jmp				imcode 6
	movs	r3, #1
	mov	r0, r3
	这儿缺少了下标为5的代码:		jmp				imcode 7
	movs	r3, #2
	mov	r0, r3
	movs	r3, #3
	mov	r0, r3
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	main, .-main
	.text
	.align	1
	.global	__hwc_start
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	__hwc_start, %function
__hwc_start:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	bl	main
	movs	r3, [r7, #0]
	mov	r0, r3
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	__hwc_start, .-__hwc_start
