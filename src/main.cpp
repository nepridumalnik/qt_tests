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

    PopUpCombobox *popupCombo = new PopUpCombobox{&tabWidget};
    popupCombo->addItem("Первый");
    popupCombo->addItem("Второй");
    popupCombo->addItem("Третий");
    popupCombo->addItem("Первый");
    popupCombo->addItem("Второй");
    popupCombo->addItem("Третий");
    popupCombo->addItem("Первый");
    popupCombo->addItem("Второй");
    popupCombo->addItem("Третий");
    popupCombo->addItem("Первый");
    popupCombo->addItem("Второй");
    popupCombo->addItem("Третий");
    popupCombo->addItem("Первый");
    popupCombo->addItem("Второй");
    popupCombo->addItem("Третий");
    popupCombo->addItem("Первый");
    popupCombo->addItem("Второй");
    popupCombo->addItem("Третий");
    tabWidget.addTab(popupCombo, "PopUpCombobox");

    LineEdit *lineEdit = new LineEdit{&tabWidget};
    lineEdit->addButton(new QPushButton);

    tabWidget.addTab(lineEdit, "LineEdit");

    return app.exec();
}
