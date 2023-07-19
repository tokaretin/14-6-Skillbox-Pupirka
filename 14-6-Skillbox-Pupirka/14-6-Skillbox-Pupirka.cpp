/*Задание 5. Пупырка
После посылки из Китая осталась спецплёнка для бережной перевозки груза — пупырка. 
Всего в пупырке 12 на 12 шариков-пузырьков. Состояние любого пузырька: он либо целый, 
либо нет, то есть true или false (тип массива — bool). Для начала требуется реализовать 
отдельную функцию инициализации пупырки начальным состоянием: полностью целая пупырка, 
все элементы true.

Программа заключается в последовательном лопании целых регионов пузырьков. Перед каждым 
таким лопанием надо показывать пользователю полностью всю плёнку: o — это целый пузырёк, 
x — лопнутый. Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопание.
Пользователь вводит две координаты: начала региона и конца региона. Процедура лопания 
пузырей должна быть реализована с помощью отдельной функции, все аргументы должны проверяться 
на валидность, что они в в рамках диапазона возможных значений, иначе должна быть выведена 
ошибка. После лопания каждого пузыря, который не был ещё лопнут до того, в консоль должно 
выводиться сообщение “Pop!”.

Лопание должно продолжаться до последнего пузырька. Как только вся пупырка потрачена,
программа заканчивает выполнение. Вы можете подсчитать окончание в самой функции по 
отображению пузырьков плёнки, так как функция выполняется после каждого лопания.

Советы и рекомендации
Обратите внимание, что лопание пузырей делается с помощью региона, а не одной точки.
Регион задаётся двумя координатами, это координаты углов прямоугольника.
При лопании региона достаточно запустить цикл только по этим элементам. Не нужно проходить 
каждый раз по всей матрице.
Всю область плёнки удобно представить в виде двумерного массива типа bool.
Инициализировать вручную такой массив сложно, лучше воспользоваться вложенными циклами.
Для проверки на целостность одной ячейки (если вы используете тип bool) можно не сравнивать 
её с истиной, а указать в условии имя переменной.
Например, вместо:

if (shell[i][j] == true)
{
  …
}
Достаточно записать:

if (shell[i][j])
{
  …
}
Такой трюк можно проделывать с переменными типа bool.

Что оценивается
Программа заканчивает выполнение только после того, как не осталось целых пузырей.
Лопание пузырей производится с помощью прямоугольной области.*/
#include <iostream>
#include <vector>

const int SIZE = 12;

// Функция для инициализации пупырки начальным состоянием: полностью целая пупырка
std::vector<std::vector<bool>> initializeBubbleWrap() {
    std::vector<std::vector<bool>> bubbleWrap(SIZE, std::vector<bool>(SIZE, true));
    return bubbleWrap;
}

// Функция для отображения состояния пупырки в консоль
void displayBubbleWrap(const std::vector<std::vector<bool>>& bubbleWrap) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << (bubbleWrap[i][j] ? "o" : "x") << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

// Функция проверки наличия целых пузырьков
bool hasRemainingBubbles(const std::vector<std::vector<bool>>& bubbleWrap) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (bubbleWrap[i][j]) {
                return true;
            }
        }
    }
    return false;
}

// Функция лопания пупырей в указанном регионе
void popBubbles(std::vector<std::vector<bool>>& bubbleWrap, int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE ||
        endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) {
        std::cout << "Error: invalid region coordinates." << '\n';
        return;
    }

    bool anyBubblesPopped = false;

    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            if (!bubbleWrap[i][j]) {
                continue;
            }

            bubbleWrap[i][j] = false;
            anyBubblesPopped = true;
            std::cout << "Pop! ";
        }
    }
    std::cout << '\n';

    displayBubbleWrap(bubbleWrap);
}

int main() {
    std::vector<std::vector<bool>> bubbleWrap = initializeBubbleWrap();
    displayBubbleWrap(bubbleWrap);

    int startX, startY, endX, endY;

    while (true) {
        std::cout << "Enter the region’s start coordinates (x1): ";
        std::cin >> startX;
        std::cout << "Enter the region’s start coordinates (y1): ";
        std::cin >> startY;
        std::cout << '\n';

        std::cout << "Enter the region’s start coordinates (x2): ";
        std::cin >> endX;
        std::cout << "Enter the region’s start coordinates (y2): ";
        std::cin >> endY;
        std::cout << '\n';

        popBubbles(bubbleWrap, startX, startY, endX, endY);

        if (!hasRemainingBubbles(bubbleWrap)) {
            break;
        }
    }

    std::cout << "All the bubbles are popped." << '\n';
    return 0;
}
