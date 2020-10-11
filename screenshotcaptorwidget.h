#ifndef SCREENSHOTCAPTORWIDGET_H
#define SCREENSHOTCAPTORWIDGET_H

#include <QWidget>
#include <QMenu>
#include <QPoint>
#include <QSize>

#include "screen.h"


class ScreenShotCaptorWidget : public QWidget
{
    Q_OBJECT

public:
    static ScreenShotCaptorWidget *Instance();  // 单例模式
    explicit ScreenShotCaptorWidget(QWidget *parent = nullptr);
    ~ScreenShotCaptorWidget();

private:
    static QScopedPointer<ScreenShotCaptorWidget> self;
    QMenu *menu;              // 右键菜单对象
    Screen *screen;           // 截屏对象
    QPixmap *fullScreen;      // 保存全屏图像
    QPixmap *bgScreen;        // 模糊背景图
    QPoint movPos;            // 坐标

protected:
    void contextMenuEvent(QContextMenuEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);

private:
    void saveScreen();
    void saveFullScreen();
    void saveScreenOther();
    void saveFullOther();
};
#endif // SCREENSHOTCAPTORWIDGET_H
