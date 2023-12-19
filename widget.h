#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
// Début de l'espace de noms Qt
QT_BEGIN_NAMESPACE
namespace Ui {
class widget; // Déclaration de la classe widget dans l'espace de noms Ui
}
QT_END_NAMESPACE // Fin de l'espace de noms Qt

// Déclaration de la classe widget qui hérite de QWidget
class widget : public QWidget
{
    Q_OBJECT

public:
    // Constructeur avec un paramètre parent optionnel (la valeur par défaut est nullptr)
    explicit widget(QWidget *parent = nullptr);
    // Destructeur
    ~widget();

private:
    // Pointeur vers la classe Ui::widget, représentant l'interface utilisateur
    Ui::widget *ui;
};
#endif // WIDGET_H
