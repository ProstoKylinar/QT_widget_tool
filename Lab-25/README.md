# Лабораторная работа №5 (год 2)
Срок выполнения работы: с 2023-11-21 по 2022-11-28.
Срок сдачи работы: 2023-11-28.

## Библиотека Qt: сетевое взаимодействие

### Ответвление
Необходимо создать ответвление (fork) моего репозитория Lab-25 (название 
оставить без изменения, а видимость поставить приватной). Назничить меня в 
новом репозитории соавтором с правами администратора. Вики, Задачи а также
Проекты отключить.

В локальной копии создавать ветки (branch) по необходимости.

### Этап разработки
Разработать программу с использованием библиотеки Qt. В окне программы 
разместить в ряд строку для ввода адреса и кнопку, под которыми разместить 
поле для ввода текста.

При нажатии на кнопку запускается сканирование узла, который введен 
в поле адреса, на предмет открытых TCP-портов. Результирующая информация 
о статусе открытых портов и обнаруженных на них службах вводится в поле 
для ввода текста (редактирование запрещено).

Для реализации сетевого взаимодействия задействовать возможности класса 
QTcpSocket.

Проект создавать на основе qmake.

Исходные коды программы снабдить краткими комментариями.

UML 2.0 диаграмму разработанных классов включить в состав исходных кодов 
программы в виде файла формата PDF.

Дополнительная информация:
  * [Документация nmap](https://nmap.org/book/vscan.html)

### Запрос слияния
По итогу выполнения работы создать запрос на слияние (pull request) 
и назначить меня рецензентом.

