# Exo1
- Dans cet exemple simple, le thread principal crée une région parallèle. Tous
les threads du groupe obtiennent leur numéro de thread unique et l’affiche
avec un message "Salam Word".
Le thread principal n'affiche que le nombre total de threads. Il affiche
également le nombre de processeurs/coeurs de la machine.
Les routines de la bibliothèque à utiliser sont :
  
   omp_get_thread_num();
   omp_get_ num _threads(); 
   omp_get_num_procs().
   
   *Output*: 
   
  ![image](https://user-images.githubusercontent.com/51762779/78551535-ca23da80-77fd-11ea-9141-ace43ff6a52f.png)

# Exo2 
- Ecrire un programme en utilisant une boucle parallèle faisant la somme de deux
  tableaux de 1000 éléments.
      Varier la politique du schedule et le chunk correspondant.
  
  *Output* :
  
  ![image](https://user-images.githubusercontent.com/51762779/78551419-9a74d280-77fd-11ea-989c-aa5be21a3e6a.png)
