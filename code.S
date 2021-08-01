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
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	getint, .-getint
	.text
	.align	1
	.global	getch
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	getch, %function
getch:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	getch, .-getch
	.text
	.align	1
	.global	getarray
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	getarray, %function
getarray:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	getarray, .-getarray
	.text
	.align	1
	.global	putint
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	putint, %function
putint:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	putint, .-putint
	.text
	.align	1
	.global	putch
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	putch, %function
putch:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	putch, .-putch
	.text
	.align	1
	.global	putarray
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	putarray, %function
putarray:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	putarray, .-putarray
	.text
	.align	1
	.global	foo
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	foo, %function
foo:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	str	r0, [r7, #0]
	这儿缺少了下标为1的代码:		=		#0		$2 (tmp)
	这儿缺少了下标为2的代码:		+		$2 (tmp)	#0	$2 (tmp)
	这儿缺少了下标为3的代码:		*		$2 (tmp)	#4	$2 (tmp)
	这儿缺少了下标为4的代码:		*get		$0	$2 (tmp)	$1 (tmp)
	movs	r3, [r7, #0]
	mov	r0, r3
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	foo, .-foo
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
	这儿缺少了下标为7的代码:		alloc		#0		$0
	这儿缺少了下标为8的代码:		alloc		#0		$1
	这儿缺少了下标为9的代码:		=		#0		$4 (tmp)
	这儿缺少了下标为10的代码:		*		$4 (tmp)	#4	$4 (tmp)
	这儿缺少了下标为11的代码:		*get		$0	$4 (tmp)	$3 (tmp)
	movs	r0, [r7, #0]
	bl	foo
	这儿缺少了下标为13的代码:		=		#0		$7 (tmp)
	这儿缺少了下标为14的代码:		*		$7 (tmp)	#4	$7 (tmp)
	这儿缺少了下标为15的代码:		*get		$1	$7 (tmp)	$6 (tmp)
	movs	r0, [r7, #0]
	bl	foo
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
