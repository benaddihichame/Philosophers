# 🍽️ Philosophers

Une implémentation du problème classique des philosophes qui dînent en utilisant les threads POSIX et les mutex en C.

## 📋 Description

Le problème des philosophes qui dînent est un problème classique en informatique illustrant les défis de la synchronisation et de l'évitement des interblocages (deadlocks) dans la programmation concurrente.

### Le Problème

- Plusieurs philosophes sont assis autour d'une table circulaire
- Chaque philosophe alterne entre trois états : **manger**, **dormir**, et **penser**
- Il y a une fourchette entre chaque paire de philosophes adjacents
- Un philosophe a besoin de **deux fourchettes** (gauche et droite) pour manger
- Un philosophe ne peut pas manger s'il n'a qu'une seule fourchette
- Si un philosophe ne mange pas dans un temps imparti, il meurt

## 🚀 Compilation et Exécution

### Compilation

```bash
make
```

### Exécution

```bash
./philo [nombre_de_philosophes] [temps_pour_mourir] [temps_pour_manger] [temps_pour_dormir] [nombre_de_repas_optionnel]
```

### Paramètres

- `nombre_de_philosophes` : Le nombre de philosophes (et de fourchettes)
- `temps_pour_mourir` : Temps en millisecondes avant qu'un philosophe meure s'il ne mange pas
- `temps_pour_manger` : Temps en millisecondes qu'un philosophe passe à manger
- `temps_pour_dormir` : Temps en millisecondes qu'un philosophe passe à dormir
- `nombre_de_repas_optionnel` : Nombre de fois que chaque philosophe doit manger (optionnel)

### Exemples d'utilisation

```bash
# 5 philosophes, meurent après 800ms, mangent pendant 200ms, dorment pendant 200ms
./philo 5 800 200 200

# 4 philosophes, avec 5 repas maximum par philosophe
./philo 4 410 200 200 5

# Test de mort rapide
./philo 1 400 200 200

# Test sans mort
./philo 5 800 200 200 7
```

## 🏗️ Architecture

### Structures principales

- **`t_philo`** : Représente un philosophe avec son ID, ses fourchettes, et ses statistiques
- **`t_table`** : Contient la configuration globale et tous les philosophes
- **`t_forks`** : Représente une fourchette avec son mutex

### Fichiers source

```
src/
├── philo.h          # Déclarations et structures
├── main.c           # Point d'entrée et validation des arguments
├── start_init.c     # Initialisation des structures et threads
├── creation.c       # Création et gestion des threads
├── action.c         # Actions des philosophes (manger, dormir, penser)
├── time.c           # Gestion du temps et fonctions de timing
├── utils.c          # Fonctions utilitaires et libération mémoire
└── mod_atol.c       # Conversion de chaînes en nombres
```

## 🔧 Fonctionnalités

### Gestion des Threads
- Un thread par philosophe pour simuler leurs actions
- Un thread "undertaker" pour surveiller les morts
- Synchronisation avec des mutex pour éviter les data races

### Prévention des Deadlocks
- Attribution des fourchettes selon un ordre déterministe
- Gestion des cas edge (philosophe unique)

### Monitoring
- Affichage en temps réel des actions des philosophes
- Détection automatique de la mort d'un philosophe
- Arrêt propre de la simulation

### Format de sortie
```
[timestamp_ms] [philosopher_id] has taken a fork
[timestamp_ms] [philosopher_id] is eating
[timestamp_ms] [philosopher_id] is sleeping
[timestamp_ms] [philosopher_id] is thinking
[timestamp_ms] [philosopher_id] died
```

## 🧪 Tests

### Tests basiques
```bash
# Ne doit jamais mourir
./philo 5 800 200 200

# Doit mourir rapidement
./philo 1 400 200 200

# Test avec nombre de repas fixe
./philo 4 410 200 200 5
```

### Tests de stress
```bash
# Beaucoup de philosophes
./philo 200 800 200 200

# Timing serré
./philo 5 310 100 100
```

## ⚠️ Règles et Contraintes

- Un philosophe ne doit pas mourir si la simulation est correctement configurée
- Les messages ne doivent pas être mélangés ou corrompus
- La simulation s'arrête quand un philosophe meurt ou quand tous ont mangé le nombre requis de fois
- Maximum 10ms entre la mort d'un philosophe et l'affichage du message

## 🛠️ Nettoyage

```bash
make clean    # Supprime les fichiers objets
make fclean   # Supprime les fichiers objets et l'exécutable
make re       # Recompile complètement
```

## 📚 Concepts Abordés

- **Threading** : Utilisation des threads POSIX
- **Synchronisation** : Mutex et verrous
- **Deadlock Prevention** : Stratégies d'évitement des interblocages
- **Race Conditions** : Protection des ressources partagées
- **Timing** : Gestion précise du temps en millisecondes
