
/*                                                                              
 * CS:APP Data Lab                                                              
 *                                                                              
 * <Please put your name and userid here>                                      
 *                                                                              
 * bits.c - Source file with your solutions to the Lab.                        
 *          This is the file you will hand in to your instructor.              
 *                                                                              
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc            
 * compiler. You can still use printf for debugging without including          
 * <stdio.h>, although you might get a compiler warning. In general,            
 * it's not good practice to ignore compiler warnings, but in this              
 * case it's OK.                                                                
 */

#if 0
/*                                                                              
 * Instructions to Students:                                                    
 *                                                                              
 * STEP 1: Read the following instructions carefully.                          
 */
You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }
  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

 You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*                                                                            
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31                            
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*                                                                            
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31                            
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
* STEP 2: Modify the following functions according the coding rules.          
 *                                                                              
 *   IMPORTANT. TO AVOID GRADING SURPRISES:                                    
 *   1. Use the dlc compiler to check that your solutions conform              
 *      to the coding rules.                                                    
 *   2. Use the BDD checker to formally verify that your solutions produce      
 *      the correct answers.                                                    
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.                      
   This file is part of the GNU C Library.                                      
                                                                               
   The GNU C Library is free software; you can redistribute it and/or          
   modify it under the terms of the GNU Lesser General Public                  
   License as published by the Free Software Foundation; either                
   version 2.1 of the License, or (at your option) any later version.          
                                                                               
   The GNU C Library is distributed in the hope that it will be useful,        
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU            
   Lesser General Public License for more details.                              
                                                                               
   You should have received a copy of the GNU Lesser General Public            
   License along with the GNU C Library; if not, see                            
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can            
   include it implicitly at the start of every compilation.  It must            
   not itself include <features.h> or any other header that includes            
   <features.h> because the implicit include comes before any feature          
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this            
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real            
   and complex.  If the GCC (4.9 and later) predefined macros                  
   specifying compiler intent are available, use them to determine              
   whether the overall intent is to support these features; otherwise,          
   presume an older compiler has intent to support these features and          
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is        
   synchronized with ISO/IEC 10646:2017, fifth edition, plus                    
   the following additions from Amendment 1 to the fifth edition:
      - 56 emoji characters                                                        
   - 285 hentaigana                                                            
   - 3 additional Zanabazar Square characters */
/*                                                                              
 * bitOr - x|y using only ~ and &                                              
 *   Example: bitOr(6, 5) = 7                                                  
 *   Legal ops: ~ &                                                            
 *   Max ops: 8                                                                
 *   Rating: 1                                                                  
 */
int bitOr(int x, int y) {
// all logic gates possible from NAND gates
 return ~((~x)&(~y));
}
/*                                                                              
 * bitXor - x^y using only ~ and &                                              
 *   Example: bitXor(4, 5) = 1                                                  
 *   Legal ops: ~ &                                                            
 *   Max ops: 14                                                                
 *   Rating: 1                                                                  
 */
int bitXor(int x, int y) {
// all logic gates possible from NAND gates
  return (~(x & y)) & (~((~x) & (~y)));
}
/*                                                                              
 * firstN - returns value with n upper bits set to 1                            
 *            and 32-n lower bits set to 0                                      
 *  You may assume 0 <= n <= 32                                                
 *  Example: firstN(4) = 0xF0000000                                            
 *  Legal ops: ! ~ & ^ | + << >>                                                
 *  Max ops: 10                                                                
 *  Rating: 2                                                                  
 */
int firstN(int n) {
    int setBits = (1 << n) + ~0;    // Set `n` most significant bits to 1
    int result = setBits << (32 + ~n + 1);  // Shift the set bits to their appropriate position
    return result;
}


/*                                                                              
 * fourthBits - return word with every fourth bit (starting from the LSB) set t\
o 1                                                                            
 *   Legal ops: ! ~ & ^ | + << >>                                              
 *   Max ops: 8                                                                
 *   Rating: 1                                                                  
 */
/*                                                                              
 * fourthBits - return word with every fourth bit (starting from the LSB) set t\
o 1                                                                            
 *   Legal ops: ! ~ & ^ | + << >>                                              
 *   Max ops: 8                                                                
 *   Rating: 1                                                                  
 */
int fourthBits(void) {
  int result = 0x11;  // Start with the binary number 00000000000000000000000000010001
  result = result | (result << 8);  // Set every fourth bit in the next 8 bits
  result = result | (result << 16);  // Set every fourth bit in the next 16 bits
  return result;
}
/*                                                                              
 * rotate4 - Rotate x to the right by 4                                        
 *   Examples: rotate4(0x87654321) = 0x18765432                                
 *   Legal ops: ~ & ^ | + << >> !                                              
 *   Max ops: 12                                                                
 *   Rating: 3                                                                  
 */
int rotate4(int x) {
  int rightShift = x >> 4;               // Right shift x by 4 bits
  int preservedBits = x & 0xF;           // Preserve the 4 rightmost bits of x
  int leftShift = (preservedBits << 28) & (0xF << 28); // Left shift the preserved bits by 28 bits and mask the result
  return rightShift | leftShift;         // Combine the shifted values using bitwise OR
}
/*                                                                              
 * bitParity - returns 1 if x contains an odd number of 0's                    
 *   Examples: bitParity(5) = 0, bitParity(7) = 1                              
 *   Legal ops: ! ~ & ^ | + << >>                                              
 *   Max ops: 20                                                                
 *   Rating: 4                                                                  
 */
int bitParity(int x) {
  x = x ^ (x >> 16);  // Bitwise XOR of x and x right-shifted by 16 bits
  x = x ^ (x >> 8);   // Bitwise XOR of x and x right-shifted by 8 bits
  x = x ^ (x >> 4);   // Bitwise XOR of x and x right-shifted by 4 bits
  x = x ^ (x >> 2);   // Bitwise XOR of x and x right-shifted by 2 bits
  x = x ^ (x >> 1);   // Bitwise XOR of x and x right-shifted by 1 bit
  return x & 1;      // Return the least significant bit of x
}
/*                                                                              
 * tmin2 - return second smallest two's complement integer                      
 *   Legal ops: ! ~ & ^ | + << >>                                              
 *   Max ops: 6                                                                
 *   Rating: 2                                                                  
 */
int tmin2(void) {
  return ~(1 << 30);  // Left shift 1 by 30 bits and negate to obtain the second smallest two's complement integer
}

/*                                                                              
 * isZero - returns 1 if x == 0, and 0 otherwise                                
 *   Examples: isZero(5) = 0, isZero(0) = 1                                    
 *   Legal ops: ! ~ & ^ | + << >>                                              
 *   Max ops: 2                                                                
 *   Rating: 1                                                                  
 */
int isZero(int x) {
  return !x;  // Use the logical negation operator "!" to check if x is equal to zero
}
/*                                                                              
 * is0orMore - return 1 if x >= 0, return 0 otherwise                          
 *   Example: is0orMore(-1) = 0.  is0orMore(0) = 1.                            
 *   Legal ops: ! ~ & ^ | + << >>                                              
 *   Max ops: 6                                                                
 *   Rating: 3                                                                  
 */
int is0orMore(int x) {
  return !(x >> 31);  // Right shift x by 31 bits and negate the result
}
/*                                                                              
 * isNotEqual - return 0 if x == y, and 1 otherwise                            
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1                        
 *   Legal ops: ! ~ & ^ | + << >>                                              
 *   Max ops: 6                                                                
 *   Rating: 2                                                                  
 */
int isNotEqual(int x, int y) {
    return !!(x ^ y);  // Return 0 if x and y are equal, 1 otherwise
}
/*                                                                              
 * conditional - same as x ? y : z                                              
 *   Example: conditional(2,4,5) = 4                                            
 *   Legal ops: ! ~ & ^ | + << >>                                              
 *   Max ops: 16                                                                
 *   Rating: 3                                                                  
 */
int conditional(int x, int y, int z) {
  int condition = !!x;               // Convert x to 0 or 1 using the logical negation operator "!"
  int mask = ~condition + 1;        // Create an mask with all bits set to 1 or 0 depending on the condition

  return (mask & y) | (~mask & z);  // Use bitwise AND and OR operations combined with the mask to select y or z based on the condition
}
/*                                                                              
 * isSmaller - if x < y  then return 1, else return 0                         
 *   Example: isSmaller(4,5) = 1.                                               
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isSmaller(int x, int y) {
  // Get sign bits
  int x_sign = x >> 31;
  int y_sign = y >> 31;
  // Calculate y - x
  int diff = y + (~x + 1);
  // Get sign bit of diff
  int diff_sign = diff >> 31;
  // Handle x = INT_MIN edge case
  int x_min = !x;
  // Handle y = INT_MAX edge case
  int y_max = !(y + 1);
  // Calculate cases
  int case1 = x_sign & !y_sign;
  int case2 = !x_sign & !y_sign & diff_sign;
  // Additional check for x == y
  int x_equals_y = !(x ^ y);
  // Fix for INT_MIN edge case
  int min_min = !x & !y;
  return (case1 | case2 | x_min | !y_max | !x_equals_y) & !min_min;
}






/*                                                                              
 * subOK - Determine if can compute x-y without overflow                        
 *   Example: subOK(0x80000000,0x80000000) = 1,                                
 *            subOK(0x80000000,0x70000000) = 0,                                
 *   Legal ops: ! ~ & ^ | + << >>                                              
 *   Max ops: 20                                                                
 *   Rating: 3                                                                  
 */
int subOK(int x, int y) {
  int diff = x + (~y + 1);  // Subtract y from x using 2's complement representation

  int signX = x >> 31;      // Get the sign bit of x
  int signY = y >> 31;      // Get the sign bit of y
  int signDiff = diff >> 31;  // Get the sign bit of the difference

  int overflow = (signX ^ signDiff) & (signX ^ signY);  // Check if overflow has occurred

  return !overflow;  // Return 1 if there is no overflow, and 0 if there is overflow
}



