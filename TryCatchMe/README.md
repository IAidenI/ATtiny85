# TryCatchMe

**TryCatchMe** est un petit programme conçu pour créer une fenêtre intrusive et quasi impossible à fermer. Il utilise diverses techniques pour perturber l'utilisateur tout en restant discret et autonome.

## Fonctionnalités

- 🪟 **Fenêtre toujours au premier plan** : la fenêtre se positionne au-dessus de toutes les autres, sans barre de titre ni bouton de fermeture.
- 🌀 **Effet de tremblement** : elle oscille légèrement autour de sa position d'origine (±20 pixels aléatoirement), rendant le focus difficile.
- 🖱️ **Évitement de la souris** : dès que le curseur entre dans la fenêtre, celle-ci se téléporte instantanément à un autre emplacement aléatoire.
- 🔒 **Blocage du gestionnaire des tâches** : le programme intercepte jusqu'à 5 tentatives d'ouverture du gestionnaire des tâches (`Ctrl + Shift + Échap` ou `Ctrl + Alt + Suppr`).
- 🛑 **Méthodes de fermeture limitées** :
  - En cliquant sur le bouton **"TryCatchMe"** (si vous parvenez à l’atteindre).
  - En **tuant manuellement le processus** via un invite de commande ou au bout des 5 essais du gestionnaire des tâches.

Il existe deux versions, en C# qui permet d'avoir un **.exe** et de ne pas dépendre de librairies et en python qui dépend, lui, de python et de librairies spécifiques.

## Démonstration

<p align="center">
  <img src="./src/images/Demo_TryCatchMe.gif"/>
</p>
