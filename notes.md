# Clings 招新做题笔记

## 02b format_print 格式化输出
### 知识点
- `%d`：以十进制打印int整数
- `%x`：小写十六进制打印整数，**不会自带0x前缀**，`0x`需要手动写在printf格式字符串内。
- `\n`：字符串内部转义换行字符，`\`与`n`组合成为一个换行字符，不会输出`\`和`n`符号。

### 关键代码
```c
printf("local = %d\n", local);
printf("global = 0x%x\n", global);

