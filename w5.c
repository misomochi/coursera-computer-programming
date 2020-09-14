/*
題目敘述

寫一個程式來模擬洗牌。我們將用一個指標陣列 (array of pointer) 來代表牌組。排組內的每張牌都有一個 1 至 10000 的整數點數。陣列的第 i 個元素代表牌組中的第 i 張牌；也就是說，如果牌組的第 i 張牌的點數為 6，那麼陣列第 i 個指標所指到的值就會是 6。如果指標指到 NULL 代表那是牌組的末端 (end of deck)，代表後面將不會有任何牌。我們保證牌組中最多只有 9999 張牌。

現在我們想要洗牌。首先先將 n 張牌分成兩組，第一組中包含了前半 (n/2) 的牌；第二組則包含剩下的牌。例如有 9 張牌的話，分堆後第一組牌有 5 張牌，而第二組牌則有 4 張牌。接著我們將兩組牌合為一組，順序為：第一組的第一張牌、第二組的第一張牌、第一組的第二張牌、第二組的第二張牌，以此類推。也就是說，我們交替著擺，將把兩組牌合為一組。洗牌的函式原型如下：

void shuffle(int *deck[]);

另外，我們也需要一個能印出牌組的涵式。下列的 print() 函式要在一行 (single line) 內按照順序印出所有牌的點數，數字間留一個空白。提醒，根據牌組末端 (end of deck) 就能知道所有的牌都已經印出了。

void print(int *deck[]);

包含 main() 的程式提供如下，請補齊 shuffle() 以及 print() 來完成程式。

#include <stdio.h>

void shuffle(int *deck[]);
void print(int *deck[]);

int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;

  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck);  
  return 0;
}

輸入範例

1 2 3 4 5

輸出範例

1 4 2 5 3
*/

#include <stdio.h>

void shuffle(int *deck[]);
void print(int *deck[]);

int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;

  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck);  
  return 0;
}

void shuffle (int *deck[]) {
  int count = 0;
  int *tmp[10000];

  for (int i = 0; deck[i] != NULL; ++i) {
    tmp[i] = deck[i];
    ++count;
  }

  for (int j = 0; j < count; ++j)
    deck[j] = (j % 2 == 0) ? tmp[j / 2] : tmp[(count + j) / 2];
}

void print (int *deck[]) {
  for (int i = 0; deck[i] != NULL; ++i)
    printf("%d ", *deck[i]);
}