# PCBruteForce

**PCBruteForce** est un POC (_Proof of Concept_) démontrant la faisabilité d'une attaque par force brute sur un poste Windows verrouillé.

---

## Fonctionnement

Avant toute tentative, il est **essentiel de vérifier la politique de verrouillage du système** afin d’éviter de déclencher un blocage du compte.

### Étapes de vérification :

1. Ouvrir une invite de commande (CMD).
2. Exécuter la commande suivante :
   ```
   net accounts
   ```
3. Vérifier la ligne suivante :
   - ✅ **Seuil de verrouillage : Jamais** → Aucun risque de verrouillage du compte.
   - ⚠️ **Seuil de verrouillage : 10 (ou autre)** → Le compte sera bloqué après le nombre d’essais défini.  
     Dans ce cas, le verrouillage durera la période spécifiée par :
     ```
     Durée du verrouillage (min) : XX
     ```
