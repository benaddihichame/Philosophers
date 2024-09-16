/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:52:25 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/09/16 11:47:23 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * Fonction: get_curren_time
 * -------------------------
 * Cette fonction renvoie le temps actuel en millisecondes depuis l'époque Unix (1er janvier 1970).
 * Elle est utilisée pour mesurer précisément le temps écoulé entre différentes actions dans le projet Philosopher.
 * La précision en millisecondes permet de gérer avec exactitude le timing des actions des philosophes, 
 * ce qui est crucial pour éviter les conditions de blocage (deadlock) et de famine (starvation).
 *
 */

long get_curren_time(void)
{
    struct timeval time;  // Déclare une structure timeval pour stocker le temps.

    if (gettimeofday(&time, NULL) == -1)  // Récupère l'heure actuelle. Si une erreur se produit, on affiche un message d'erreur.
        write(2, "gettimeofday() error\n", 22);  // Écrit un message d'erreur sur la sortie d'erreur standard (fd 2).
    
    // Retourne le temps en millisecondes : secondes * 1000 + microsecondes / 1000
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/*
* Fonction: ft_usleep
 * -------------------
 * Cette fonction suspend l'exécution du programme pour un certain nombre de millisecondes.
 * Elle utilise une boucle pour vérifier périodiquement si le temps requis s'est écoulé, 
 * tout en dormant par petites périodes (500 microsecondes) pour réduire l'utilisation du CPU.
 * ft_usleep est utile pour introduire des pauses précises et contrôlées dans les actions des philosophes,
 * permettant ainsi une synchronisation efficace et respectueuse des ressources dans le projet.
 */
int ft_usleep(size_t millisecondes, t_philo *philo)
{
    size_t start;
    int health;

    start = get_curren_time();  // Récupère le temps de départ en millisecondes.
    // Boucle jusqu'à ce que le temps écoulé atteigne le nombre de millisecondes spécifié.
    while (get_curren_time() - start < millisecondes)
    {
        handle_mutex(&philo->table->die_mutex, LOCK);
        health = philo->table->died;
        handle_mutex(&philo->table->die_mutex, UNLOCK);
        if (health == 1)
            break ;
        usleep(500);  // Dors pendant 500 microsecondes (0,5 millisecondes) pour réduire la charge CPU.
    }
    return (0);  // Retourne 0 pour indiquer que la fonction s'est terminée correctement.
}
