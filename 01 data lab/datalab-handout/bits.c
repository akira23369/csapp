

#if 0
  要求：
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  明确禁止：
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
  您可以假设您的机器:
  1. 使用补码,32位整数表示。
  2. 按算术方式执行右移。
  3.如果移位量小于0或大于31,则在移位时具有不可预测的行为。

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

// 对于需要实现浮点操作的问题,编码规则不那么严格。允许使用循环和条件控制。可以同时使用int型和unsigned型。
// 您可以使用任意整数和无符号常量。可以对int或unsigned数据使用任何算术、逻辑或比较操作。

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.
// 明确禁止您:
// 1. 定义或使用任意宏。
// 2. 在此文件中定义任何附加函数。
// 3.调用任意函数。
// 4. 使用任何形式的铸造。
// 5. 使用除int或unsigned以外的任何数据类型。这意味着不能使用数组、结构体或联合。
// 6. 使用任何浮点数据类型、操作或常量。

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 * 步骤2:
 * 根据编码规则修改以下函数。重要的是,要避免评分意外:
 * 1. 使用dlc编译器检查您的解决方案是否符合编码规则。
 * 2. 使用BDD检查器正式验证您的解决方案是否产生正确的答案。
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */

// 求x ^ y
int bitXor(int x, int y) {
  return ~(~(x & (~y)) & ~(~x & y));
}
/* 
 * tmin - return minimum two's complement integer 
  *   Max ops: 4

 *   Rating: 1
 */

// 您可以假设您的机器:
//   1. 使用补码,32位整数表示。
//   2. 按算术方式执行右移。
//   3.如果移位量小于0或大于31,则在移位时具有不可预测的行为。


int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 * 
 *  要求：判断 x 是否为补码表示的最大整数。
    运算：! ~ & ^ | +
    
 */
int isTmax(int x) {
  return !(~x ^ (x + 1) | !(x + 1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 *    要求：判断 x 二进制表示下的奇数位是否全为 1。
 */
int allOddBits(int x) {
  int t = 0xAAAAAAAA;   
  int y = x & t;
  return !(t ^ y);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 *  要求：计算返回 -x。
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 *  要求：判断值 x 是否在范围 [0x30, 0x39] 中。
 */
int isAsciiDigit(int x) {
  return !((x + ~48 + 1) >> 31) & !!((x + ~58 + 1) >> 31);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 *  要求：执行三目运算符 x ? y : z：当 x 不为 0 时，返回 y；否则返回 z。
 */

// 这题nb
// 主要思想：
// 取数a用 a & (全1)     
// 消数a用 a & (全0)
// ~(全0) = (全1)
// 是'取'还是'消' 取决于x是否为0
int conditional(int x, int y, int z) {
  x = !x + ~0;
  return (y & x) | (z & ~x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 *  要求：判断 x <= y。
 *  比大小思路很简单：无非就是符号相同就y-x   不同就是看符号
 */
int isLessOrEqual(int x, int y) {
  int x_flag = x >> 31 & 1, y_flag = y >> 31 & 1;   
  int y_x_flag = (y + ~x + 1) >> 31 & 1;
  // if (x_flag == y_flag) return y - x >> 31;
  // else if (x_flag == 0) return 0;
  // else return 1;
  return (!(x_flag ^ y_flag) & (!y_x_flag)) | ((x_flag ^ y_flag) & !y_flag);
  }
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return 2;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  return 0;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  return 2;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}

