# Proiect OOP
## Boardgame Retailer



Clasele implementate sunt urmatoarele:

- Boardgame, o clasa care descrie multiple proprietati a unui joc de masa.
- ShoppingCart, o clasa care memoreaza si gestioneaza cosul de cumparaturi al utilizatorului.
- User, clasa care memoreaza datele de login, date functionale cum ar fi soldul, si memoreaza un shopping cart specific fiecarui obiect User.
- Menu, clasa care gestioneaza multipli Useri, si permite afisarea si interactiunea cu meniul printat in consola.
- Boardgame_list, clasa care contine catalogul de jocuri pentru intreaga aplicatie.
- InvalidInputException, clasa care extinde functionalitatea clasei Exception.
- RegularUser, care mosteneste din User si adauga modalitati specifice de a folosi magazinul tipice unui cont obisnuit.
- AdminUser, care mosteneste din User si adauga modalitati specifice de modifica magazinul specifice unui administrator.

## Functionalitati:

- Capabil sa printeze un meniu interactiv in consola.
- Functionalitate de login, impreuna cu privilegii extra daca Userul este admin.
- Capabil sa primeasca input si sa schimbe in mod direct obiectele de ShoppingCart, Boardgame_list si User prin stergere sau adaugare de elemente.
- Functionalitate deplina de magazin, prin gestionarea stocului, a soldului, a stocului, a platii etc.

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

[dill]: <https://github.com/joemccann/dillinger>
[git-repo-url]: <https://github.com/joemccann/dillinger.git>
[john gruber]: <http://daringfireball.net>
[df1]: <http://daringfireball.net/projects/markdown/>
[markdown-it]: <https://github.com/markdown-it/markdown-it>
[Ace Editor]: <http://ace.ajax.org>
[node.js]: <http://nodejs.org>
[Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
[jQuery]: <http://jquery.com>
[@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
[express]: <http://expressjs.com>
[AngularJS]: <http://angularjs.org>
[Gulp]: <http://gulpjs.com>

[PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
[PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
[PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
[PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
[PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
[PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
