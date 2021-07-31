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
	.comm	var0,4,4
	.text
	.align	1
	.global	func
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	func, %function
func:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	str	r0, [r7, #0]
	这儿缺少了下标为1的代码:		-		$1	#1	$1
	movs	r3, [r7, #0]
	mov	r0, r3
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	func, .-func
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
	这儿缺少了下标为4的代码:		=		#10		$0
	movs	r0, a
	bl	func
	movs	r3, [r7, #0]
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
