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
	.word	0
	.word	5
	.word	0
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
	.word	4
	.word	5
	.word	6
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
	.global	test
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	test, %function
test:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	str	r0, [r7, #0]
	这儿缺少了下标为1的代码:		=		#1		$11 (tmp)
	movs	r0, [r7, #0]
	bl	fib
	这儿缺少了下标为3的代码:		=		#0		$13 (tmp)
	这儿缺少了下标为4的代码:		+		$13 (tmp)	#2	$13 (tmp)
	这儿缺少了下标为5的代码:		*		$13 (tmp)	#3	$13 (tmp)
	这儿缺少了下标为6的代码:		+		$13 (tmp)	#1	$13 (tmp)
	这儿缺少了下标为7的代码:		*		$13 (tmp)	#4	$13 (tmp)
	这儿缺少了下标为8的代码:		*get		$8	$13 (tmp)	$12 (tmp)
	这儿缺少了下标为9的代码:		+		$12 (tmp)	$10 (tmp)	$9 (tmp)
	movs	r3, [r7, #0]
	mov	r0, r3
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	test, .-test
	.text
	.align	1
	.global	fib
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfp
	.type	fib, %function
fib:
	push	{r4, r5, r7, lr}
	sub	sp, sp, #100
	add	r7, sp, #0
	str	r0, [r7, #0]
	这儿缺少了下标为13的代码:		j<		$8	#2	imcode 15
	这儿缺少了下标为14的代码:		jmp				imcode 17
	movs	r3, [r7, #0]
	mov	r0, r3
	这儿缺少了下标为16的代码:		jmp				imcode 23
	这儿缺少了下标为17的代码:		-		$8	#1	$11 (tmp)
	movs	r0, [r7, #0]
	bl	fib
	这儿缺少了下标为19的代码:		-		$8	#2	$13 (tmp)
	movs	r0, [r7, #0]
	bl	fib
	这儿缺少了下标为21的代码:		+		$12 (tmp)	$10 (tmp)	$9 (tmp)
	movs	r3, [r7, #0]
	mov	r0, r3
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	fib, .-fib
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
	这儿缺少了下标为24的代码:		=		#0		$8
	这儿缺少了下标为25的代码:		j<		$8	#10	imcode 27
	这儿缺少了下标为26的代码:		jmp				imcode 38
	这儿缺少了下标为27的代码:		=		#0		$11 (tmp)
	这儿缺少了下标为28的代码:		+		$11 (tmp)	$8	$11 (tmp)
	这儿缺少了下标为29的代码:		*		$11 (tmp)	#4	$11 (tmp)
	这儿缺少了下标为30的代码:		*get		$6	$11 (tmp)	$10 (tmp)
	movs	r0, [r7, #0]
	bl	fib
	这儿缺少了下标为32的代码:		=		#0		$12 (tmp)
	这儿缺少了下标为33的代码:		+		$12 (tmp)	$8	$12 (tmp)
	这儿缺少了下标为34的代码:		*		$12 (tmp)	#4	$12 (tmp)
	这儿缺少了下标为35的代码:		*set		$7	$12 (tmp)	$9 (tmp)
	这儿缺少了下标为36的代码:		+		$8	#1	$8
	这儿缺少了下标为37的代码:		jmp				imcode 25
	这儿缺少了下标为38的代码:		=		#0		$8
	这儿缺少了下标为39的代码:		=		#10086		$9
	这儿缺少了下标为40的代码:		j!=		#1	#0	imcode 42
	这儿缺少了下标为41的代码:		jmp				imcode 65
	这儿缺少了下标为42的代码:		=		#0		$11 (tmp)
	这儿缺少了下标为43的代码:		+		$11 (tmp)	$8	$11 (tmp)
	这儿缺少了下标为44的代码:		*		$11 (tmp)	#4	$11 (tmp)
	这儿缺少了下标为45的代码:		*get		$6	$11 (tmp)	$10 (tmp)
	这儿缺少了下标为46的代码:		j==		$10 (tmp)	#4	imcode 54
	这儿缺少了下标为47的代码:		jmp				imcode 48
	这儿缺少了下标为48的代码:		=		#0		$13 (tmp)
	这儿缺少了下标为49的代码:		+		$13 (tmp)	$8	$13 (tmp)
	这儿缺少了下标为50的代码:		*		$13 (tmp)	#4	$13 (tmp)
	这儿缺少了下标为51的代码:		*get		$6	$13 (tmp)	$12 (tmp)
	这儿缺少了下标为52的代码:		j==		$12 (tmp)	#5	imcode 54
	这儿缺少了下标为53的代码:		jmp				imcode 55
	这儿缺少了下标为54的代码:		jmp				imcode 0
	这儿缺少了下标为55的代码:		j==		$8	#10	imcode 57
	这儿缺少了下标为56的代码:		jmp				imcode 58
	这儿缺少了下标为57的代码:		jmp				imcode 40
	这儿缺少了下标为58的代码:		=		#0		$15 (tmp)
	这儿缺少了下标为59的代码:		+		$15 (tmp)	$8	$15 (tmp)
	这儿缺少了下标为60的代码:		*		$15 (tmp)	#4	$15 (tmp)
	这儿缺少了下标为61的代码:		*get		$7	$15 (tmp)	$14 (tmp)
	这儿缺少了下标为62的代码:		+		$9	$14 (tmp)	$9
	这儿缺少了下标为63的代码:		+		$8	#1	$8
	这儿缺少了下标为64的代码:		jmp				imcode 40
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
	这儿缺少了下标为67的代码:		alloc		#32		$8
	这儿缺少了下标为68的代码:		=		#0		$9 (tmp)
	这儿缺少了下标为69的代码:		*set		$8	$9 (tmp)	#0
	这儿缺少了下标为70的代码:		+		$9 (tmp)	#4	$9 (tmp)
	这儿缺少了下标为71的代码:		*set		$8	$9 (tmp)	#0
	这儿缺少了下标为72的代码:		+		$9 (tmp)	#4	$9 (tmp)
	这儿缺少了下标为73的代码:		*set		$8	$9 (tmp)	#0
	这儿缺少了下标为74的代码:		+		$9 (tmp)	#4	$9 (tmp)
	这儿缺少了下标为75的代码:		*set		$8	$9 (tmp)	#0
	这儿缺少了下标为76的代码:		+		$9 (tmp)	#4	$9 (tmp)
	这儿缺少了下标为77的代码:		*set		$8	$9 (tmp)	#0
	这儿缺少了下标为78的代码:		+		$9 (tmp)	#4	$9 (tmp)
	这儿缺少了下标为79的代码:		*set		$8	$9 (tmp)	#0
	这儿缺少了下标为80的代码:		+		$9 (tmp)	#4	$9 (tmp)
	这儿缺少了下标为81的代码:		*set		$8	$9 (tmp)	#0
	这儿缺少了下标为82的代码:		+		$9 (tmp)	#4	$9 (tmp)
	这儿缺少了下标为83的代码:		*set		$8	$9 (tmp)	#0
	这儿缺少了下标为84的代码:		alloc		#32		$10
	这儿缺少了下标为85的代码:		=		#0		$11 (tmp)
	这儿缺少了下标为86的代码:		*set		$10	$11 (tmp)	#1
	这儿缺少了下标为87的代码:		+		$11 (tmp)	#4	$11 (tmp)
	这儿缺少了下标为88的代码:		*set		$10	$11 (tmp)	#2
	这儿缺少了下标为89的代码:		+		$11 (tmp)	#4	$11 (tmp)
	这儿缺少了下标为90的代码:		*set		$10	$11 (tmp)	#3
	这儿缺少了下标为91的代码:		+		$11 (tmp)	#4	$11 (tmp)
	这儿缺少了下标为92的代码:		*set		$10	$11 (tmp)	#4
	这儿缺少了下标为93的代码:		+		$11 (tmp)	#4	$11 (tmp)
	这儿缺少了下标为94的代码:		*set		$10	$11 (tmp)	#5
	这儿缺少了下标为95的代码:		+		$11 (tmp)	#4	$11 (tmp)
	这儿缺少了下标为96的代码:		*set		$10	$11 (tmp)	#6
	这儿缺少了下标为97的代码:		+		$11 (tmp)	#4	$11 (tmp)
	这儿缺少了下标为98的代码:		*set		$10	$11 (tmp)	#7
	这儿缺少了下标为99的代码:		+		$11 (tmp)	#4	$11 (tmp)
	这儿缺少了下标为100的代码:		*set		$10	$11 (tmp)	#8
	这儿缺少了下标为101的代码:		alloc		#32		$12
	这儿缺少了下标为102的代码:		=		#0		$13 (tmp)
	这儿缺少了下标为103的代码:		*set		$12	$13 (tmp)	#1
	这儿缺少了下标为104的代码:		+		$13 (tmp)	#4	$13 (tmp)
	这儿缺少了下标为105的代码:		*set		$12	$13 (tmp)	#2
	这儿缺少了下标为106的代码:		+		$13 (tmp)	#4	$13 (tmp)
	这儿缺少了下标为107的代码:		*set		$12	$13 (tmp)	#3
	这儿缺少了下标为108的代码:		+		$13 (tmp)	#4	$13 (tmp)
	这儿缺少了下标为109的代码:		*set		$12	$13 (tmp)	#4
	这儿缺少了下标为110的代码:		+		$13 (tmp)	#4	$13 (tmp)
	这儿缺少了下标为111的代码:		*set		$12	$13 (tmp)	#5
	这儿缺少了下标为112的代码:		+		$13 (tmp)	#4	$13 (tmp)
	这儿缺少了下标为113的代码:		*set		$12	$13 (tmp)	#6
	这儿缺少了下标为114的代码:		+		$13 (tmp)	#4	$13 (tmp)
	这儿缺少了下标为115的代码:		*set		$12	$13 (tmp)	#7
	这儿缺少了下标为116的代码:		+		$13 (tmp)	#4	$13 (tmp)
	这儿缺少了下标为117的代码:		*set		$12	$13 (tmp)	#8
	这儿缺少了下标为118的代码:		alloc		#32		$14
	这儿缺少了下标为119的代码:		=		#0		$15 (tmp)
	这儿缺少了下标为120的代码:		*set		$14	$15 (tmp)	#1
	这儿缺少了下标为121的代码:		+		$15 (tmp)	#4	$15 (tmp)
	这儿缺少了下标为122的代码:		*set		$14	$15 (tmp)	#2
	这儿缺少了下标为123的代码:		+		$15 (tmp)	#4	$15 (tmp)
	这儿缺少了下标为124的代码:		*set		$14	$15 (tmp)	#3
	这儿缺少了下标为125的代码:		+		$15 (tmp)	#4	$15 (tmp)
	这儿缺少了下标为126的代码:		*set		$14	$15 (tmp)	#0
	这儿缺少了下标为127的代码:		+		$15 (tmp)	#4	$15 (tmp)
	这儿缺少了下标为128的代码:		*set		$14	$15 (tmp)	#5
	这儿缺少了下标为129的代码:		+		$15 (tmp)	#4	$15 (tmp)
	这儿缺少了下标为130的代码:		*set		$14	$15 (tmp)	#0
	这儿缺少了下标为131的代码:		+		$15 (tmp)	#4	$15 (tmp)
	这儿缺少了下标为132的代码:		*set		$14	$15 (tmp)	#7
	这儿缺少了下标为133的代码:		+		$15 (tmp)	#4	$15 (tmp)
	这儿缺少了下标为134的代码:		*set		$14	$15 (tmp)	#8
	这儿缺少了下标为135的代码:		alloc		#32		$16
	这儿缺少了下标为136的代码:		=		#0		$17 (tmp)
	这儿缺少了下标为137的代码:		*set		$16	$17 (tmp)	#1
	这儿缺少了下标为138的代码:		+		$17 (tmp)	#4	$17 (tmp)
	这儿缺少了下标为139的代码:		*set		$16	$17 (tmp)	#2
	这儿缺少了下标为140的代码:		+		$17 (tmp)	#4	$17 (tmp)
	这儿缺少了下标为141的代码:		*set		$16	$17 (tmp)	#3
	这儿缺少了下标为142的代码:		+		$17 (tmp)	#4	$17 (tmp)
	这儿缺少了下标为143的代码:		*set		$16	$17 (tmp)	#4
	这儿缺少了下标为144的代码:		+		$17 (tmp)	#4	$17 (tmp)
	这儿缺少了下标为145的代码:		*set		$16	$17 (tmp)	#5
	这儿缺少了下标为146的代码:		+		$17 (tmp)	#4	$17 (tmp)
	这儿缺少了下标为147的代码:		*set		$16	$17 (tmp)	#6
	这儿缺少了下标为148的代码:		+		$17 (tmp)	#4	$17 (tmp)
	这儿缺少了下标为149的代码:		*set		$16	$17 (tmp)	#7
	这儿缺少了下标为150的代码:		+		$17 (tmp)	#4	$17 (tmp)
	这儿缺少了下标为151的代码:		*set		$16	$17 (tmp)	#8
	这儿缺少了下标为152的代码:		=		#12		$18
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #100
	mov	sp, r7
	pop	{r4, r5, r7, pc}
	.size	foo, .-foo
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
