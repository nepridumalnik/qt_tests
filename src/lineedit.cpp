#include <lineedit.hpp>
#include <ui_lineedit.h>

#include <QHBoxLayout>
#include <QPushButton>

LineEdit::LineEdit(QWidget *parent)
    : QWidget{parent}
    , ui_{new ::Ui::Frame}
{
    QFrame *frame = new QFrame{this};
    ui_->setupUi(frame);
}

void LineEdit::addButton(QPushButton *button, QLineEdit::ActionPosition position)
{
    auto layout = QLineEdit::ActionPosition::LeadingPosition == position ? ui_->leftLayout : ui_->rightLayout;
    layout->addWidget(button);
}

void LineEdit::setButtonsSpacing(int spacing)
{
    ui_->leftLayout->setSpacing(spacing);
    ui_->rightLayout->setSpacing(spacing);
}

int LineEdit::buttonsSpacing()
{
    return ui_->leftLayout->spacing();
}

void LineEdit::setReadOnly(bool cond)
{
    ui_->lineEdit->setReadOnly(cond);
}
