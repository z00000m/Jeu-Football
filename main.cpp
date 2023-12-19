// On inclut les bibliothèques
#include "widget.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>

// Début du main
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    widget w;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); // On ajoute une base de données
    db.setDatabaseName("Jeu Football"); // Nom de la base de données
    db.setUserName("student"); // Nom de l'utilisateur
    db.setPassword("crif2024sn"); // Mot de passe de la base de données
    if(db.open())
    {
        qDebug() << "Vous êtes maintenant connecté à " << db.hostName(); // On dit à l'utilisateur qu'il est connecté à la base de données

        QSqlQuery query;

        query.exec("SELECT * FROM Joueurs "); // On choisit la table
        while (query.next())
        {
            // On affiche les informations de la base de données dans le terminal QT
            QString idJoueurs = query.value(0).toString();
            QString Nom = query.value(1).toString();
            QString Prenom = query.value(2).toString();
            QString Club = query.value(3).toString();
            qDebug() << "\t| -----------------------------------------------------------------------------------";
            qDebug() << "\t|" << idJoueurs << " \t| " << Nom << " \t| " << Prenom << " \t| " << Club << " \t|";
            qDebug() << "\t| -----------------------------------------------------------------------------------";
            db.close();
        }
        qDebug() << "Requete Ok ! :)";
    }
    else
    {

        qDebug() << " La connexion a echouée :( " << db.lastError().text(); // Si la connexion a échouée on dit à l'utilisateur

    }
    // On affiche les informations de la base de données sur le formulaire .ui
    QSqlTableModel table;
    table.clear();
    table.setTable("Joueurs");
    QTableView view;
    QPushButton afficher("Afficher"),note("Note"); // On ajoute 2 boutons
    QHBoxLayout layout;
    layout.addWidget(&view);
    layout.addWidget(&afficher);
    layout.addWidget(&note);
    w.setLayout(&layout);
    // On ajoute les colomnes avec les différentes informations à afficher si on appuie sur afficher
    QObject::connect(&afficher, &QPushButton::clicked,[&](){
        view.setModel(&table);
        view.setColumnHidden(0, false);
        view.setColumnHidden(1, false);
        view.setColumnHidden(2, false);
        view.setColumnHidden(3, false);
        table.setHeaderData(0,Qt::Horizontal,"ID");
        table.setHeaderData(1,Qt::Horizontal,"Prénom");
        table.setHeaderData(2,Qt::Horizontal,"Nom");
        table.setHeaderData(3,Qt::Horizontal,"Club");
        table.select();
    });
    // On ajoute les colomnes avec les différentes informations à afficher si on appuie sur note
    QObject::connect(&note, &QPushButton::clicked,[&](){
        view.setModel(&table);
        view.setColumnHidden(0, false);
        view.setColumnHidden(1, false);
        view.setColumnHidden(2, false);
        view.setColumnHidden(3, false);
        view.setColumnHidden(4, false);
        table.setHeaderData(0,Qt::Horizontal,"ID");
        table.setHeaderData(1,Qt::Horizontal,"Prénom");
        table.setHeaderData(2,Qt::Horizontal,"Nom");
        table.setHeaderData(3,Qt::Horizontal,"Club");
        table.setHeaderData(4,Qt::Horizontal,"Note");
        table.select();
    });
    w.show();
    return a.exec();
}

