# OpenMP-exo1
- Dans cet exemple simple, le thread principal crée une région parallèle. Tous
les threads du groupe obtiennent leur numéro de thread unique et l’affiche
avec un message "Salam Word".
Le thread principal n'affiche que le nombre total de threads. Il affiche
également le nombre de processeurs/coeurs de la machine.
Les routines de la bibliothèque à utiliser sont :
  
   omp_get_thread_num();
   omp_get_ num _threads(); 
   omp_get_num_procs().