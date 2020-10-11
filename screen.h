#ifndef SCREEN_H
#define SCREEN_H

#include <QPoint>
#include <QSize>

class Screen
{
public:
    enum STATUS {SELECT, MOV, SET_W_H};
    Screen(){};
    Screen(const QSize &size);

    void setStart(const QPoint &pos);
    void setEnd(const QPoint &pos);
    QPoint getStart();
    QPoint getEnd();

    QPoint getLeftUp();
    QPoint getRightDown();

    STATUS getStatus();
    void setStatus(STATUS status);

    int width();
    int height();
    bool isInArea(const QPoint &pos);  //  检测pos是否在截图区域内
    void move(const QPoint &p);      // 按p移动截图区域

private:
    QPoint leftUpPos, rightDownPos;    // 记录截图区域的 左上角、 右下角
    QPoint startPos, endPos;           // 记录鼠标开始位置， 结束位置
    int maxWidth, maxHeight;           // 记录屏幕大小
    STATUS status;                     // 三个状态：选择区域，移动区域，设置width、height

    void cmpPoint(QPoint &s, QPoint &e);   //比较两位置，判断左上角、右下角
};

#endif // SCREEN_H
