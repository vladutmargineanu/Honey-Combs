# Honey-Combs
Homework for the Computer Programming course @ ACS, UPB 2019

# Algorithm

In rezolvarea problemei, am folosit 5 functii pentru modularizare, astfel:
1) Functia citire in care am citit cu ajutorul lui fgets si am salvat fiecare sir intru-un vector de siruri de caractere;
2) Functia matrice in care am creat fagurele intr-o matrice setata initial cu spatii si completata apoi cu elemente caractere pentru formarea celulelor(slash, backslash,space,underscore si Q pentru matca);
3) Functia afisare , care este apelata in functia matrice, este folosita pentru parcurgerea matricei si afisarea caracterelor;
4) Functia prelucrare este functia principala in care se apeleaza functiile:citire,matrice,resetare. In aceasta functie am prelucrat fiecare sir de caractere citit astfel: am salvat intr-un vector de tip int fiecare caracteristica pentru coloane pana la intalnirea literei R sau C, dupa care am salvat coordonatele matcii intr-o structura in care folosim un tablou unidimensional;
5) Functia resetare in care am setat dupa fiecare prelucrare ,elementele matricei cu spatii.
In main apelam doar functia prelucrare.
