

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


  您可以假设您的机器:
  1. 使用补码,32位整数表示。
  2. 按算术方式执行右移。
  3.如果移位量小于0或大于31,则在移位时具有不可预测的行为。


// 对于需要实现浮点操作的问题,编码规则不那么严格。允许使用循环和条件控制。可以同时使用int型和unsigned型。
// 您可以使用任意整数和无符号常量。可以对int或unsigned数据使用任何算术、逻辑或比较操作。

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
  int x_flag = x >> 31 & 1, y_flag = y >> 31 & 1;  // x，y符号位 
  int y_x_flag = (y + ~x + 1) >> 31 & 1;    // y - x 的符号位
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
 *  计算 !x：当 x = 0 时返回 1；当 x ≠ 0 时返回 0。
 *  当x不为0时， x | -x  符号位必为 1
 */
int logicalNeg(int x) {
  int pre_flag = (x + 1) >> 31 & 1, ne_flag = (x - 1) >> 31 & 1;
  return ~((x | (~x + 1)) >> 31) & 1;
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
 *  使用二进制补码表示 x 的最少位数。
 *  当 x ≥ 0 时，位数取决于 1 的最高位数；
 *  当 x < 0 时，位数则取决于 0 的最高位数（根据补码表示的定义，符号位起连续的 1 可合并起来用一个位表示）。
 *  首先考虑将负数取反，将问题统一成计算 1 的最高位，利用算术右移即可完成，即 x = x ⊕ ( x >> 31) 。 
 *  然后使用二分法计算 1 的最高位：判断高 16 位是否大于 0，若大于 0 说明高 16 位中存在 1，否则 1 在低 16 位中。
 *  使用 conditional 函数更新 x（取出高 16 位或低 16 位）。迭代判断 8 位、4 位等等。
 */
int howManyBits(int x) {
  int s = (x >> 31);              // 不知道为啥这里 x >> 31 & 1不行
  x = (s & ~x) | (~s & x);
  int ans = 1, bit = 0;

  bit = !!(x >> 16) << 4;    // 如果高16为不为0，就至少有2^4
  x >>= bit; ans += bit;

  bit = !!(x >> 8) << 3;
  x >>= bit; ans += bit;

  bit = !!(x >> 4) << 2;
  x >>= bit; ans += bit;

  bit = !!(x >> 2) << 1;
  x >>= bit; ans += bit;

  bit = !!(x >> 1);
  x >>= bit; ans += bit;

  bit = !!x;
  x >>= bit; ans += bit;

  return ans;
}
//float
/* 
  要求：计算 2 * uf，若 uf 为特殊值值时，直接返回 uf。
  运算：Integer/unsigned 相关运算；||，&&，if 和 while 等判断语句。
*/
unsigned floatScale2(unsigned uf) {
  unsigned s = uf >> 31 & 1;
  unsigned e = (uf >> 23) & 0xff; 
  unsigned f = uf & 0x7fffff;
  if (!(e ^ 0xff)) return uf;
  if (!e) return (s << 31) | (f << 1);
  return (s << 31) | ((e + 1) << 23) | f;     // 这里e + 1是因为题目需要 *２　后的值
}
/* 
要求：将浮点数 uf 转换成整数。
Anything out of range (including NaN and infinity) should return 0x80000000u.
运算：Integer/unsigned 相关运算；||，&&，if 和 while 等判断语句。
*/
int floatFloat2Int(unsigned uf) {
  unsigned s = uf >> 31 & 1;
  unsigned e = (uf >> 23) & 0xff;
  unsigned f = uf & 0x7fffff;
  // 0
  if (e == 0 && f == 0) return 0;
  int E = e - 127;
  // 非规格化
  if (e == 0) return 0;

  // 特殊值   按照规定返回0x80000000u
  if (e == 0xff) return 1 << 31;

  // 规格化
  f = 1 << 23 | f;
  // 整数最大的表示范围
  if (E > 31) return 1 << 31;
  else if (E < 0) return 0;

  if (E >= 23) f <<= E - 23;
  else f >>= 23 - E;
  if (s & 1) f = ~f + 1;
  return f;
}
/* 
要求：使用浮点数表示 2^x。无法表示时：过小返回 0，过大返回 +INF。
运算：Integer/unsigned 相关运算；||，&&，if 和 while 等判断语句。
*/
unsigned floatPower2(int x) {
  if (x > 127) return 0x7f800000;   // 阶码全为1的数
  if (x < -126) return 0;
  return (x + 127) << 23;
}

