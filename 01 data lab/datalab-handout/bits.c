

#if 0
  Ҫ��
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  ��ȷ��ֹ��
  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  �����Լ������Ļ���:
  1. ʹ�ò���,32λ������ʾ��
  2. ��������ʽִ�����ơ�
  3.�����λ��С��0�����31,������λʱ���в���Ԥ�����Ϊ��


// ������Ҫʵ�ָ������������,���������ô�ϸ�����ʹ��ѭ�����������ơ�����ͬʱʹ��int�ͺ�unsigned�͡�
// ������ʹ�������������޷��ų��������Զ�int��unsigned����ʹ���κ��������߼���Ƚϲ�����

// ��ȷ��ֹ��:
// 1. �����ʹ������ꡣ
// 2. �ڴ��ļ��ж����κθ��Ӻ�����
// 3.�������⺯����
// 4. ʹ���κ���ʽ�����졣
// 5. ʹ�ó�int��unsigned������κ��������͡�����ζ�Ų���ʹ�����顢�ṹ������ϡ�
// 6. ʹ���κθ����������͡�����������

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 * ����2:
 * ���ݱ�������޸����º�������Ҫ����,Ҫ������������:
 * 1. ʹ��dlc������������Ľ�������Ƿ���ϱ������
 * 2. ʹ��BDD�������ʽ��֤���Ľ�������Ƿ������ȷ�Ĵ𰸡�
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

// ��x ^ y
int bitXor(int x, int y) {
  return ~(~(x & (~y)) & ~(~x & y));
}
/* 
 * tmin - return minimum two's complement integer 
  *   Max ops: 4

 *   Rating: 1
 */

// �����Լ������Ļ���:
//   1. ʹ�ò���,32λ������ʾ��
//   2. ��������ʽִ�����ơ�
//   3.�����λ��С��0�����31,������λʱ���в���Ԥ�����Ϊ��


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
 *  Ҫ���ж� x �Ƿ�Ϊ�����ʾ�����������
    ���㣺! ~ & ^ | +
    
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
 *    Ҫ���ж� x �����Ʊ�ʾ�µ�����λ�Ƿ�ȫΪ 1��
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
 *  Ҫ�󣺼��㷵�� -x��
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
 *  Ҫ���ж�ֵ x �Ƿ��ڷ�Χ [0x30, 0x39] �С�
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
 *  Ҫ��ִ����Ŀ����� x ? y : z���� x ��Ϊ 0 ʱ������ y�����򷵻� z��
 */

// ����nb
// ��Ҫ˼�룺
// ȡ��a�� a & (ȫ1)     
// ����a�� a & (ȫ0)
// ~(ȫ0) = (ȫ1)
// ��'ȡ'����'��' ȡ����x�Ƿ�Ϊ0
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
 *  Ҫ���ж� x <= y��
 *  �ȴ�С˼·�ܼ򵥣��޷Ǿ��Ƿ�����ͬ��y-x   ��ͬ���ǿ�����
 */
int isLessOrEqual(int x, int y) {
  int x_flag = x >> 31 & 1, y_flag = y >> 31 & 1;  // x��y����λ 
  int y_x_flag = (y + ~x + 1) >> 31 & 1;    // y - x �ķ���λ
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
 *  ���� !x���� x = 0 ʱ���� 1���� x �� 0 ʱ���� 0��
 *  ��x��Ϊ0ʱ�� x | -x  ����λ��Ϊ 1
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
 *  ʹ�ö����Ʋ����ʾ x ������λ����
 *  �� x �� 0 ʱ��λ��ȡ���� 1 �����λ����
 *  �� x < 0 ʱ��λ����ȡ���� 0 �����λ�������ݲ����ʾ�Ķ��壬����λ�������� 1 �ɺϲ�������һ��λ��ʾ����
 *  ���ȿ��ǽ�����ȡ����������ͳһ�ɼ��� 1 �����λ�������������Ƽ�����ɣ��� x = x �� ( x >> 31) �� 
 *  Ȼ��ʹ�ö��ַ����� 1 �����λ���жϸ� 16 λ�Ƿ���� 0�������� 0 ˵���� 16 λ�д��� 1������ 1 �ڵ� 16 λ�С�
 *  ʹ�� conditional �������� x��ȡ���� 16 λ��� 16 λ���������ж� 8 λ��4 λ�ȵȡ�
 */
int howManyBits(int x) {
  int s = (x >> 31);              // ��֪��Ϊɶ���� x >> 31 & 1����
  x = (s & ~x) | (~s & x);
  int ans = 1, bit = 0;

  bit = !!(x >> 16) << 4;    // �����16Ϊ��Ϊ0����������2^4
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
  Ҫ�󣺼��� 2 * uf���� uf Ϊ����ֵֵʱ��ֱ�ӷ��� uf��
  ���㣺Integer/unsigned ������㣻||��&&��if �� while ���ж���䡣
*/
unsigned floatScale2(unsigned uf) {
  unsigned s = uf >> 31 & 1;
  unsigned e = (uf >> 23) & 0xff; 
  unsigned f = uf & 0x7fffff;
  if (!(e ^ 0xff)) return uf;
  if (!e) return (s << 31) | (f << 1);
  return (s << 31) | ((e + 1) << 23) | f;     // ����e + 1����Ϊ��Ŀ��Ҫ *�������ֵ
}
/* 
Ҫ�󣺽������� uf ת����������
Anything out of range (including NaN and infinity) should return 0x80000000u.
���㣺Integer/unsigned ������㣻||��&&��if �� while ���ж���䡣
*/
int floatFloat2Int(unsigned uf) {
  unsigned s = uf >> 31 & 1;
  unsigned e = (uf >> 23) & 0xff;
  unsigned f = uf & 0x7fffff;
  // 0
  if (e == 0 && f == 0) return 0;
  int E = e - 127;
  // �ǹ��
  if (e == 0) return 0;

  // ����ֵ   ���չ涨����0x80000000u
  if (e == 0xff) return 1 << 31;

  // ���
  f = 1 << 23 | f;
  // �������ı�ʾ��Χ
  if (E > 31) return 1 << 31;
  else if (E < 0) return 0;

  if (E >= 23) f <<= E - 23;
  else f >>= 23 - E;
  if (s & 1) f = ~f + 1;
  return f;
}
/* 
Ҫ��ʹ�ø�������ʾ 2^x���޷���ʾʱ����С���� 0�����󷵻� +INF��
���㣺Integer/unsigned ������㣻||��&&��if �� while ���ж���䡣
*/
unsigned floatPower2(int x) {
  if (x > 127) return 0x7f800000;   // ����ȫΪ1����
  if (x < -126) return 0;
  return (x + 127) << 23;
}

