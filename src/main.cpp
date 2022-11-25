#include <lineedit.hpp>
#include <popupcombobox.hpp>

#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QTabWidget>

int main(int argc, char *argv[])
{
    QApplication app{argc, argv};

    QFont font;
    font.setPixelSize(26);

    QTabWidget tabWidget;
    tabWidget.setMinimumSize(800, 600);
    tabWidget.setFont(font);
    tabWidget.show();

    LineEdit *lineEdit = new LineEdit{&tabWidget};
    lineEdit->addButton(new QPushButton);

    tabWidget.addTab(lineEdit, "LineEdit");
    tabWidget.addTab(new PopUpCombobox{&tabWidget}, "PopUpCombobox");

    return app.exec();
}
