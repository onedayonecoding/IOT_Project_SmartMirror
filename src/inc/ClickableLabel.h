#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR);
    ~ClickableLabel();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};


#endif // CLICKLABEL_H
