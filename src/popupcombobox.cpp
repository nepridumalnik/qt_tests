#include <popupcombobox.hpp>

#include <lineedit.hpp>

#include <QDebug>
#include <QDialog>
#include <QHBoxLayout>
#include <QIcon>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QPixmap>
#include <QPushButton>
#include <QStringList>

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
    , list_{new QListWidget{}}
    , offset_{4}
{
    lineEdit_ = new LineEdit{this};
    lineEdit_->setReadOnly(true);
    const QSize size{64, 64};

    QPixmap map{size};
    map.fill(Qt::red);

    QIcon icon{map};
    QPushButton *button = new QPushButton;
    button->setFixedSize(32, 32);
    button->setIcon(icon);
    button->setFlat(true);

    lineEdit_->addButton(button, QLineEdit::TrailingPosition);

    setStyleSheet(Style);

    connect(button, &QPushButton::clicked, this, &PopUpCombobox::onButtonClick);
}

void PopUpCombobox::onButtonClick()
{
    qDebug() << "PopUpCombobox::onButtonClick";
    qDebug() << mapToGlobal(this->rect().bottomLeft());
    QDialog *dlg = new QDialog{this};
    QVBoxLayout *layout = new QVBoxLayout{dlg};
    layout->addWidget(list_);
    layout->setSpacing(0);
    layout->setMargin(0);

    dlg->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    const int x = mapToGlobal(rect().bottomLeft()).x();
    const int y = mapToGlobal(lineEdit_->rect().bottomLeft()).y() + offset_;

    dlg->move({x, y});
    dlg->show();
}

void PopUpCombobox::addItem(const QString &label)
{
    list_->addItem(label);
}

void PopUpCombobox::addItems(const QStringList &labels)
{
    list_->addItems(labels);
}

void PopUpCombobox::addItem(QListWidgetItem *item)
{
    list_->addItem(item);
}

void PopUpCombobox::insertItem(int row, QListWidgetItem *item)
{
    list_->insertItem(row, item);
}

void PopUpCombobox::insertItem(int row, const QString &label)
{
    list_->insertItem(row, label);
}

void PopUpCombobox::insertItems(int row, const QStringList &labels)
{
    list_->insertItems(row, labels);
}

void PopUpCombobox::setOffset(size_t offset)
{
    offset_ = offset;
}
