# philo
branch to work from 42

_philo (threads) ont trois états possibles : magent, pensent, dorment

Chaque état a une durée (en ms), le user choisit la durée pour manger et dormir, on peut choisir la durée pour penser.

Si un philo ne mange pas pendant une certaine durée (donée par le user) il meurt.
Pour manger, un philo doit avoir à sa dispo deux fourchettes (il en existe une par philo nb)
=> Les philo pairs / impairs sont sync entre eux
1 2 3 4 5
___________________________________________________
trois groupes : pairs, impairs, last(si impair)

Impairs mangent
Pairs pensent
Last dort
--
Impairs dorment
Pairs mangent
Last pense
--
Pairs dorment
Last mange
Impairs pensent
___________________________________________________

<!-- On a un tableau 	int *forks		chaque [] a un numéro associé => Numero du philo
C'est une variable statique (conserve sa valeur)
Elle est protégée par un mutex (les philo ne peuvent pas la modifier tous en même temps)
La boucle est conditionnée par un usleep();
Il faut trouver la bonne valeur de time_to_think pour que les philo puissent manger dès que possible.  -->

forks => tableau de mutex (static)