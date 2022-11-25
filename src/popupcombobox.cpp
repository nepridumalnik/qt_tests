#include <popupcombobox.hpp>

#include <lineedit.hpp>

#include <QDebug>
#include <QHBoxLayout>
#include <QIcon>
#include <QLineEdit>
#include <QPixmap>
#include <QPushButton>

namespace
{

static constexpr char Style[] = "QPushButton::hover{"
                                "background-color: #ffd2cf;"
                                "border: none;"
                                "border-radius: 25%;"
                                "}"
                                "QPushButton{"
                                "background-color: blue;"
                                "color: white;"
                                "border-radius: 5px;"
                                "}";

} // namespace

PopUpCombobox::PopUpCombobox(QWidget *parent)
    : QWidget(parent)

{
    LineEdit *lineEdit = new LineEdit{this};

    const QSize size{64, 64};

    QPixmap map{size};
    map.fill(Qt::red);

    QIcon icon{map};
    QPushButton *button = new QPushButton;
    button->setFixedSize(32, 32);
    button->setIcon(icon);
    button->setFlat(true);

    lineEdit->addButton(button, QLineEdit::TrailingPosition);

    setStyleSheet(Style);
}
