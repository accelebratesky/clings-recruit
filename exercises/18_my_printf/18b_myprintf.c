/*
 * Lesson 18b: myprintf — 可变参数格式化输出
 *
 * 知识点：stdarg.h, va_list, va_start, va_arg, va_end
 * 参考原课 myprintf.c 中的 myprintf 函数
 *
 * 任务：实现 myprintf(format, ...):
 *       1. va_start(ap, format) 初始化
 *       2. while ((c = *format++) != '\0') 遍历
 *       3. 非 '%' 直接 putchar(c); '%' 后看下一字符：
 *          %d → itoa(va_arg, buf, 10) + myputs
 *          %x → itoa(va_arg, buf, 16) + myputs
 *          %s → myputs(va_arg(ap, char *))
 *          %c → putchar(va_arg(ap, int))
 *       4. va_end(ap)
 *
 * 验证："a = 100, b = 0xC8\nc = A, s = helloworld\n"
 */

#include <stdarg.h>
#include <stdio.h>

void itoa(int num, char *buf, int base) {
    char *hex = "0123456789ABCDEF";
    int i = 0;
    int j;

    do {
        int rest = num % base;
        buf[i++] = hex[rest];
        num /= base;
    } while (num != 0);

    buf[i] = '\0';

    for (j = 0; j < i / 2; j++) {
        char tmp = buf[j];
        buf[j] = buf[i - 1 - j];
        buf[i - 1 - j] = tmp;
    }
}

void myputs(char *buf) {
    while (*buf) putchar(*buf++);
}

int myprintf(const char *format, ...) {
    va_list ap;
    va_start(ap, format);

    char c;
    char buf[64];

    while ((c = *format++) != '\0')
    {
        if (c != '%')
        {
            putchar(c);
        }
        else
        {
            char fmt = *format++;
            if(fmt == 'd')
            {
                int val = va_arg(ap, int);
                itoa(val, buf, 10);
                myputs(buf);
            }
            else if(fmt == 'x')
            {
                int val = va_arg(ap, int);
                itoa(val, buf, 16);
                myputs(buf);
            }
            else if(fmt == 'c')
            {
                int ch = va_arg(ap, int);
                putchar(ch);
            }
            else if(fmt == 's')
            {
                char *str = va_arg(ap, char *);
                myputs(str);
            }
        }
    }
    va_end(ap);
    return 0;
}

int main(void) {
    myprintf("a = %d, b = 0x%x\n", 100, 200);
    myprintf("c = %c, s = %s\n", 'A', "helloworld");

    return 0;
}
