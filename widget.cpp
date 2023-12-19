#include "widget.h"
#include "ui_widget.h"

// Constructeur de la classe widget
widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget) // Instanciation de l'objet Ui::widget
{
    ui->setupUi(this); // Appel de la méthode setupUi() pour initialiser l'interface utilisateur
}
// Destructeur de la classe widget
widget::~widget()
{
    delete ui; // Libération de la mémoire occupée par l'objet Ui::widget lors de la destruction de la classe
}
