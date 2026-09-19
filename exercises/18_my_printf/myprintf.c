/*
 * Lesson 18: 实现 printf — itoa + myprintf 综合
 *
 * 知识点：do-while, 字符映射，字符串逆序，stdarg.h, va_list 可变参数
 * 参考原课 myprintf.c
 *
 * 任务：
 *       1. 实现 itoa(num, buf, base): do-while 取余 + 逆序 (参考 18a)
 *       2. 实现 myprintf(format, ...): va_list 遍历 + %d/%x/%s/%c (参考 18b)
 *
 * 课堂讨论：va_arg 是如何知道下一个参数的地址的？
 *
 * 验证："a = 100, b = 0xC8\nc = A, s = helloworld\n"
 */

#include <stdarg.h>
#include <stdio.h>

void itoa(int num, char *buf, int base) {
    char *hex = "0123456789ABCDEF";

int i = 0;
    int rest;
    do{
        rest = num % base;
        buf[i++] = hex[rest];
        num = num / base;
    }while(num != 0);

    buf[i] = '\0';

    for(int j = 0; j < i/2; j++){
        char temp = buf[j];
        buf[j] = buf[i - 1 - j];
        buf[i - 1 - j] = temp;
    }
}

void myputs(char *buf) {
    while (*buf) putchar(*buf++);
}

int myprintf(const char *format, ...) {
va_list ap;
    va_start(ap, format);
    char buf[32];
    while(*format != '\0')
    {
        if(*format == '%')
        {
            format++;
            switch(*format)
            {
                case 'd':{
                    int n = va_arg(ap, int);
                    itoa(n, buf, 10);
                    myputs(buf);
                    break;
                }
                case 'x':{
                    int n = va_arg(ap, int);
                    itoa(n, buf, 16);
                    myputs(buf);
                    break;
                }
                case 'c':{
                    int ch = va_arg(ap, int);
                    putchar((char)ch);
                    break;
                }
                case 's':{
                    char *str = va_arg(ap, char*);
                    myputs(str);
                    break;
                }
            }
        }
        else
        {
            putchar(*format);
        }
        format++;
    }
    va_end(ap);
    return 0;
}

int main(void) {
    myprintf("a = %d, b = 0x%x\n", 100, 200);
    myprintf("c = %c, s = %s\n", 'A', "helloworld");

    return 0;
}
