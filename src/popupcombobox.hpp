#pragma once

#include <lineedit.hpp>

#include <QWidget>

class LineEdit;
class QListWidget;
class QStringList;
class QListWidgetItem;

class PopUpCombobox : public QWidget
{
public:
    explicit PopUpCombobox(QWidget *parent = nullptr);
    void addItem(const QString &label);
    void addItem(QListWidgetItem *item);
    void addItems(const QStringList &labels);
    void insertItem(int row, QListWidgetItem *item);
    void insertItem(int row, const QString &label);
    void insertItems(int row, const QStringList &labels);
    void setOffset(size_t offset);

private:
    void onButtonClick();

private:
    QListWidget *list_;
    LineEdit *lineEdit_;
    size_t offset_;
};
