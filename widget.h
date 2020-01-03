#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractNativeEventFilter>
class Widget : public QWidget, public QAbstractNativeEventFilter
{
    Q_OBJECT

#define PADDING 10
    enum Drag_Move
    {
        DragMove_None = 0,
        DragMove_Left,
        DragMove_Right,
        DragMove_Top,
        DragMove_Restore
    };
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void resizeBackground(int w, int h, int round, int margin, QColor color);
    void region(const QPoint &cursorGlobalPoint, bool &activeFlag);
    void checkMouseMoveRegion();
    bool checkLButtonPressRegion();
    void checkSize(void*);
    void checkDragMove(void*);
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
private:
    QImage m_bkImg;
    int m_dir;
    Drag_Move m_drag;
    QSize m_normalSize,m_minSize;
    QRect m_dragRc;
    QPoint m_dragLastPos,m_doubleClickPos;
};
#endif // WIDGET_H
