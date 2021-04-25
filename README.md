# Название семестровой работы

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml)

**_Измените status badge сверху для отображения статуса сборки вашего проекта._**

`Actions > CMake > ... > Create status badge`

_Краткое описание семестрового проекта. Следует отразить информацию по следующим пунктам:_

- _Какая структура данных реализуется?_
- _Что она из себя представляет (сбалансированное дерево, линейный список и пр.)?_
- _Где и как она используется (приложения)?_
- _Какие операции над ней можно выполнять (поиск, удаление, добавление, вставка и пр.)?_
- _Какова теоретическая сложность операций (поиск за `O(log(n))`, вставка за `O(n^2)` и т.д.)?_
- _Какая-то другая справочная информация о проекте._

## Команда "IWS"



| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Алексей       | 33        |  Ramil fan #1   |
| Даниил        | 33        |  Ramil fan #2   |
| Эрика         | 33        |  Ramil fan #3   |

**Девиз команды**
> _Наши цели ясны. Задачи определены. За работу, товарищи!_

## Структура проекта

_Описание основных частей семестрового проекта._

**Пример**. Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

_В этом разделе задаются основые требования к программному и аппаратному обеспечению для успешной работы с проектом._

**Рекомендуемые требования:**

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.8.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 4 ГБ.
5. Свободное дисковое пространство объемом ~ 3 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

### Пример (Windows)

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template.git
```



#### Генерация тестовых данных

Генерация тестовых данных просиходит автоматически при запуске benchmarks.cpp

- `--samples` - количество генерируемых элементов;
- `dataset/data/database` - папка с тестовыми данными

Тестовые данные представлены в CSV формате

```csv
-23476
2345234
-23452345
...
```

**Примечание**. Для удобства запуска контрольных тестов рекомендуется организовывать данные в директориях, например:

```shell
dataset/data/database
  insert/
    01/
      Random_100.csv
      ...
      Random_5000000.csv
    02/ ...
    03/ ...
    ...
    10/ ...
```

По названию директории `/dataset/data/database/insert` можно понять, что здесь хранятся наборы данных для контрольных тестов по
**добавлению** элементов в структуру данных. Названия файлов `Random_100.csv`. `Random_5000000.csv` и т.д. хранят информацию о размере набора данных (т.е. количество элементов). 

## Контрольные тесты (benchmarks)

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `benchmarks.cpp`          | Все тесты в одном файле, просто и удобно  | _время_         |


## Источники

_Список использованных при реализации структуры данных источников._

1) https://brestprog.by/topics/segmenttree/
2) https://habr.com/ru/company/otus/blog/485194/
3) https://e-maxx.ru/algo/segment_tree
4) https://ru.wikipedia.org/wiki/%D0%94%D0%B5%D1%80%D0%B5%D0%B2%D0%BE_%D0%BE%D1%82%D1%80%D0%B5%D0%B7%D0%BA%D0%BE%D0%B2

_**Надеемся, что данная страница смогла помочь вам разобраться в проекте.**_
