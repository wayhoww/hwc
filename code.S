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
	.global	ifElseIf
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	ifElseIf, %function
ifElseIf:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	这儿缺少了下标为0的代码:		=		#5		$0
	这儿缺少了下标为1的代码:		=		#10		$1
	这儿缺少了下标为2的代码:		j==		$0	#6	imcode 6
	这儿缺少了下标为3的代码:		jmp				imcode 4
	这儿缺少了下标为4的代码:		j==		$1	#0	imcode 6
	这儿缺少了下标为5的代码:		jmp				imcode 8
	movs	r3, [r7, #0]
	mov	r0, r3
	这儿缺少了下标为7的代码:		jmp				imcode 21
	这儿缺少了下标为8的代码:		j==		$1	#10	imcode 10
	这儿缺少了下标为9的代码:		jmp				imcode 14
	这儿缺少了下标为10的代码:		j==		$0	#1	imcode 12
	这儿缺少了下标为11的代码:		jmp				imcode 14
	这儿缺少了下标为12的代码:		=		#25		$0
	这儿缺少了下标为13的代码:		jmp				imcode 21
	这儿缺少了下标为14的代码:		j==		$1	#10	imcode 16
	这儿缺少了下标为15的代码:		jmp				imcode 20
	这儿缺少了下标为16的代码:		j==		$0	#-5	imcode 18
	这儿缺少了下标为17的代码:		jmp				imcode 20
	这儿缺少了下标为18的代码:		+		$0	#15	$0
	这儿缺少了下标为19的代码:		jmp				imcode 21
	这儿缺少了下标为20的代码:		-		#0	$0	$0
	movs	r3, [r7, #0]
	mov	r0, r3
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	ifElseIf, .-ifElseIf
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
	bl	ifElseIf
	movs	r0, [r7, #0]
	bl	putint
	str	r0, [r7, #0]
	movs	r3, #0
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
