#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
 
void SetTerminalColor(int color) {
    std::cout << "\033[48;5;" << color << "m\033[38;5;232m";
}
 
void ResetTerminalColor() {
    std::cout << "\033[0m";
}
 
int main() {
    srand(time(0)); // 初始化随机种子
    while (true) {
        int x = rand() % 88; // 产生随机位置
        int y = rand() % 28 + 1; // 产生随机颜色
        SetTerminalColor(rand() % 256); // 设置随机颜色
        for (int i = 0; i < 8; ++i) {
            std::cout << " ";
        }
        std::cout << "@" << std::flush; // 输出“雨”字符
        SetTerminalColor(232); // 重置背景颜色
        for (int i = 0; i < x; ++i) {
            std::cout << " ";
        }
        std::cout << "\033[2A"; // 向上移动两行
        usleep(10000); // 暂停以减少下雨速度
    }
    return 0;
}
