#pragma once

#include <QLineEdit>
#include <QWidget>

namespace Ui
{
class Frame;
}

class QHBoxLayout;
class QPushButton;

class LineEdit : public QWidget
{
public:
    explicit LineEdit(QWidget *parent = nullptr);

    void addButton(QPushButton *button,
                   QLineEdit::ActionPosition position = QLineEdit::ActionPosition::LeadingPosition);
    void setButtonsSpacing(int spacing);
    int buttonsSpacing();
    void setReadOnly(bool cond);

private:
    ::Ui::Frame *ui_;
    QHBoxLayout *leftLayout_;
    QHBoxLayout *rightLayout_;
    QHBoxLayout *mainLayout_;
};
