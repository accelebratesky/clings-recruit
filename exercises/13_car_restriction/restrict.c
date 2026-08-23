/*
 * Lesson 13c: 车辆限行完整程序
 *
 * 知识点：enum, switch, 三元表达式，日期计算，函数组合调用
 * 参考原课 restrict.c — 综合使用 get_last_char + is_restricted + get_week_day
 *
 * 任务：实现 get_week_day() + main():
 *       1. get_week_day(year, month, day):
 *          - origin_day = 2 (2013-1-1 为星期二)
 *          - 用 m[12]={31,28,31,30,...} 累加前 month-1 个月天数
 *          - alldays += day - 1
 *          - switch ((alldays + origin_day) % 7) 返回对应 enum day
 *       2. main(): 读入车牌号和日期 → 组合调用三个函数 → 输出结果 ("restricted!\n" / "NOT restricted!\n")
 *
 * 验证："A23456\n2013 1 1\n" → "restricted!\n" (周二限 1/6，尾号 6)
 */

#include <stdio.h>

enum day { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };

char get_last_char(char str[]) {
    char c = 0;
    int i = 0;

    while (str[i]) {
        c = str[i];
        i++;
    }
    return c;
}

int is_restricted(int tail_num, enum day today) {
    int ret = 0;

    switch (tail_num) {
        case 0:
        case 5:
            ret = (today == MONDAY) ? 1 : 0;
            break;
        case 1:
        case 6:
            ret = (today == TUESDAY) ? 1 : 0;
            break;
        case 2:
        case 7:
            ret = (today == WEDNESDAY) ? 1 : 0;
            break;
        case 3:
        case 8:
            ret = (today == THURSDAY) ? 1 : 0;
            break;
        case 4:
        case 9:
            ret = (today == FRIDAY) ? 1 : 0;
            break;
        default:
            ret = 0;
            break;
    }
    return ret;
}

enum day get_week_day(int year, int month, int day) {
    int origin_day = 2; // 2013‑1‑1 星期二
    int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int alldays = 0;
    for(int i=0;i<month-1;i++){
       alldays+=m[i];
       }
alldays+=day-1;
int wk = (alldays + origin_day) %7;
    switch(wk){
        case 1: return MONDAY;
        case 2: return TUESDAY;
        case 3: return WEDNESDAY;
        case 4: return THURSDAY;
        case 5: return FRIDAY;
        case 6: return SATURDAY;
        case 0: return SUNDAY;
        default: return MONDAY;
    }}

int main(void) {
    char plate[128];
    int y,mo,d;
    scanf("%s", plate);
    scanf("%d %d %d", &y, &mo, &d);
    char last_c = get_last_char(plate);
    int tail = last_c - '0'; 

    enum day w = get_week_day(y, mo, d);
    if(is_restricted(tail, w)){
        printf("restricted!\n");
    }else{
    printf("NOT restricted!\n");}
    return 0;
}
