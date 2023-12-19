/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QLabel *Titre;
    QPushButton *Quitter;
    QTableView *Caractristiques;

    void setupUi(QWidget *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName("widget");
        widget->resize(800, 600);
        Titre = new QLabel(widget);
        Titre->setObjectName("Titre");
        Titre->setGeometry(QRect(147, 59, 541, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Ubuntu Mono")});
        font.setPointSize(50);
        font.setBold(true);
        font.setItalic(true);
        Titre->setFont(font);
        Titre->setAlignment(Qt::AlignCenter);
        Quitter = new QPushButton(widget);
        Quitter->setObjectName("Quitter");
        Quitter->setGeometry(QRect(289, 490, 271, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Ubuntu Condensed")});
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(true);
        Quitter->setFont(font1);
        Quitter->setFlat(false);
        Caractristiques = new QTableView(widget);
        Caractristiques->setObjectName("Caractristiques");
        Caractristiques->setGeometry(QRect(175, 210, 491, 192));

        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QWidget *widget)
    {
        widget->setWindowTitle(QCoreApplication::translate("widget", "widget", nullptr));
        Titre->setText(QCoreApplication::translate("widget", "Football", nullptr));
        Quitter->setText(QCoreApplication::translate("widget", "Quitter ! ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
