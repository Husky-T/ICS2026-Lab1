/* 
 * CS:APP Data Lab 
 * 
 * <唐笑添25803020032>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  return 1 << 31;
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
	return ~(~x & ~y) & ~(x & y);
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  return (x >> 31) & (~x + 1);
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  return ((x >> (src << 3)) & 0xFF) << (dst << 3) | (x & ~(0xFF << (dst << 3)));
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  return (x >> n) & ~(((1 << 31) >> n) << 1);
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x) {
  int maskA = 0x0F | (0x0F << 8) | (0x0F << 16) | (0x0F << 24);
  int maskB = maskA << 4;
  return ((x & maskA) << 4) | (((x & maskB) >> 4) & maskA);
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
  int lowest_zero = ~x & (x + 1);
  int x2 = x | lowest_zero;
  return ~x2 & (x2 + 1);
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
  x = x ^ (x >> 16);
  x = x ^ (x >> 8);
  x = x ^ (x >> 4);
  x = x ^ (x >> 2);
  x = x ^ (x >> 1);
  return (x & 1) ^ 1;
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
  n = (n & 31);
  int logical_right = ( (x >> n) & (~( (((1 << 31) >> n) << 1) )) );
  int wrap_left = ( x << ( ((~n) + 1) & 31 ) );
  return (logical_right | wrap_left);
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
  int bias = ((1 << n) >> 1) + ~0;
  x = x + bias;
  x = x + ((x >> n) & 1);
  return (x >> n) << n;
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
  int and_val = x & y;
  int xor_val = x ^ y;
  int base = and_val + (xor_val >> 1);

  int is_odd = xor_val & 1;

  int sign_x = x >> 31;
  int sign_y = y >> 31;
  int diff_sign = sign_x ^ sign_y;

  int x_gt_y_diff = 1 + sign_x;

  int diff_same = x + ~y + 1; 
  int x_gt_y_same = 1 + (diff_same >> 31); 

  int x_gt_y = (diff_sign & x_gt_y_diff) | (~diff_sign & x_gt_y_same);
  
  int adjustment = is_odd & x_gt_y;
  
  return base + adjustment;
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {
  int sign_x = x >> 31;
  int sign_a = a >> 31;
  int sign_b = b >> 31;

  int diff_xa = x + ~a + 1;
  int diff_ax = ~diff_xa + 1;
  int diff_bx = b + ~x + 1;
  int diff_xb = ~diff_bx + 1;

  int diff_sign_xa = sign_x ^ sign_a;
  int diff_sign_bx = sign_b ^ sign_x;

  int less_xa = (diff_sign_xa & sign_x) | (~diff_sign_xa & (diff_xa >> 31));
  int ge_xa = !less_xa;

  int less_bx = (diff_sign_bx & sign_b) | (~diff_sign_bx & (diff_bx >> 31));
  int ge_bx = !less_bx;

  int less_xb = (diff_sign_bx & sign_x) | (~diff_sign_bx & (diff_xb >> 31));
  int ge_xb = !less_xb;

  int less_ax = (diff_sign_xa & sign_a) | (~diff_sign_xa & (diff_ax >> 31));
  int ge_ax = !less_ax;

  return (ge_xa & ge_bx) | (ge_xb & ge_ax);
}

// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
  int x5 = (x << 2) + x;
  int sx = x >> 31;

  int a = 0x99 | (0x99 << 8);
  int L = a | (a << 16);
  L = L ^ (1 << 31);

  int diff_pos = x + ~L + 1;
  int pos_ov = ~sx & ~(diff_pos >> 31) & !!diff_pos;

  int diff_neg = x + L;
  int neg_ov = sx & (diff_neg >> 31);

  int is_ov = pos_ov | neg_ov;

  int mask = is_ov << 31 >> 31;

  int sat_val = ~sx ^ (1 << 31);

  return (mask & sat_val) | (~mask & x5);
}

// P14
/*
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {
  int sum_xy = x + y;
  int sum_xyz = sum_xy + z;

  int sign_x = x >> 31;
  int sign_y = y >> 31;
  int sign_z = z >> 31;
  int sign_sum_xy = sum_xy >> 31;
  int sign_sum_xyz = sum_xyz >> 31;

  int pos_ov_xy = ~sign_x & ~sign_y & sign_sum_xy;
  int neg_ov_xy = sign_x & sign_y & ~sign_sum_xy;

  int pos_ov_xyz = ~sign_sum_xy & ~sign_z & sign_sum_xyz;
  int neg_ov_xyz = sign_sum_xy & sign_z & ~sign_sum_xyz;

  int pos = pos_ov_xy | pos_ov_xyz;
  int neg = neg_ov_xy | neg_ov_xyz;

  return neg + ~pos + 1; 
}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
  unsigned s = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;

  if (exp == 255)
  {
    return uf;
  }

  if (exp == 0)
  {
    if (frac == 0)
    {
      return uf;
    }

    unsigned prod = 3 * frac; 
    unsigned m_new = (prod >> 1) + ((prod & 1) & ((prod >> 1) & 1));

    if (m_new >= (1 << 23))
    {
      exp = 1;
      frac = m_new - (1 << 23);
    }
    else
    {
      frac = m_new;
    }
    
    return (s << 31) | (exp << 23) | frac;
  }

  unsigned m = (1 << 23) | frac;
  unsigned prod = 3 * m; 
  unsigned m_new = (prod >> 1) + ((prod & 1) & ((prod >> 1) & 1));

  if (m_new >= (1 << 24))
  {
    m_new = (m_new >> 1) + ((m_new & 1) & ((m_new >> 1) & 1));
    exp++;
  }

  if (exp >= 255)
  {
    return (s << 31) | 0x7F800000;
  }

  frac = m_new & 0x7FFFFF;
  return (s << 31) | (exp << 23) | frac;
}

// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
  unsigned s = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;

  if (exp == 255)
  {
    return uf;
  }

  if (exp < 126)
  {
    return s << 31;
  }

  if (exp == 126)
  {
    if (frac == 0)
    {
      return s << 31;
    }
    else
    {
      return (s << 31) | (127 << 23);
    }
  }

  if (exp >= 150)
  {
    return uf;
  }

  unsigned m = (1 << 23) | frac;
  unsigned shift = 150 - exp;
  unsigned int_part = m >> shift;
  unsigned frac_part = m & ((1 << shift) - 1);
  unsigned half = 1 << (shift - 1);

  if (frac_part > half)
  {
    int_part++;
  }
  else if (frac_part == half)
  {
    if (int_part & 1)
    {
      int_part++;
    }
  }

  if (int_part == 0)
  {
    return s << 31;
  }

  int hb = 0;
  while ((int_part >> hb) > 1)
  {
    hb++;
  }
  
  unsigned exp_new = hb + 127;
  unsigned frac_new = (int_part << (23 - hb)) & 0x7FFFFF;
  
  return (s << 31) | (exp_new << 23) | frac_new;
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
  if (x == 0)
  {
    return 0;
  }
  int sign = x >> 31;
  unsigned abs_x = (x + sign) ^ sign;
  
  int E = 0;
  unsigned temp = abs_x;
  while (temp >> 1)
  {
    temp >>= 1;
    E++;
  }
  
  int exp = E + 127;
  unsigned frac = 0;
  
  if (E <= 23)
  {
    frac = (abs_x << (23 - E)) & 0x7FFFFF;
  }
  else
  {
    int shift = E - 23;
    frac = (abs_x >> shift) & 0x7FFFFF;
    unsigned round_part = abs_x & ((1 << shift) - 1);
    unsigned half = 1 << (shift - 1);
    if (round_part > half || (round_part == half && (frac & 1)))
    {
      frac++;
      if (frac == (1 << 23)) {
        frac = 0;
        exp++;
      }
    }
  }
  return (sign << 31) | (exp << 23) | frac;
}



// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x)
{
  int m1 = 0x55 | (0x55 << 8);
  m1 = m1 | (m1 << 16);
  int m2 = 0x33 | (0x33 << 8);
  m2 = m2 | (m2 << 16);
  int m4 = 0x0F | (0x0F << 8);
  m4 = m4 | (m4 << 16);
  int m8 = 0xFF | (0xFF << 16);

  x = (x & m1) + ((x >> 1) & m1);
  x = (x & m2) + ((x >> 2) & m2);
  x = (x & m4) + ((x >> 4) & m4);
  x = (x & m8) + ((x >> 8) & m8);
  x = (x & 0xFF) + (x >> 16);
  
  return x & 0xFF;
}

// P19
/*
 * bitReverse - Reverse bits in a 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x) {
  int m4 = 0x0F | (0x0F << 8);
  m4 = m4 | (m4 << 16);

  int m2 = m4 ^ (m4 << 2);
  int m1 = m2 ^ (m2 << 1);
  int m8 = 0xFF | (0xFF << 16);
  int m16 = 0xFF | (0xFF << 8);

  x = ((x & m1) << 1) | ((x >> 1) & m1);

  x = ((x & m2) << 2) | ((x >> 2) & m2);

  x = ((x & m4) << 4) | ((x >> 4) & m4);

  x = ((x & m8) << 8) | ((x >> 8) & m8);

  x = (x << 16) | ((x >> 16) & m16);

  return x;
}