/*
題目敘述

寫一個涵式來計算一個金屬塊的價值。函式原型如下：

int value(int type, int width, int height, int length);

一個金屬塊的價值由金屬類型及長、寬、高來決定。共有六種金屬：金、銀、銅、鉛、鐵以及鈦；六種金屬的價值依序為：30、10、4、5、3、9。一個金屬塊必須被切成同樣大小的正方體才能販售，並且不能有任何剩餘的金屬。例如，一個 4 x 8 x 2 大小的金屬塊只能被切成 2 x 2 x 2 或是 1 x 1 x 1 大小的正方體。而金屬正方體的價值計算方式為其體積的平方乘以該金屬單位價值。因此，2 x 2 x 2 大小的正方體金塊價值為 8 x 8 x 30 = 1920；而4 x 8 x 2 的金塊，最高價值就是 1920 x 8 = 15360。

現在，在給予金屬類型 (type)、長 (length)、寬 (width)、高 (height) 的狀況下，計算該金屬塊的最大價值為何。你只需要寫 value 函式，主程式在下面有提供。

輸入格式

type 這個參數將會表明該金屬塊為哪種金屬。若是 79，代表是金。而 47、29、82、26、22 分別代表銀、銅、鉛、鐵以及鈦。width、height、length 代表該金屬塊的長、寬、高。

輸出格式

涵式必須確認 type 參數。若 type 並非上述六種金屬，必須回傳 -1。接著，函式必須確認三個維度的長度。width、 height、 length 皆能以 int 變數儲存。然而任何一個維度的值為零或負時，必須回傳 -2。若參數都沒有問題，請計算並回傳輸入的金屬塊價值。我們保證金屬價值能用 int 變數儲存。

輸入範例 1

79 4 8 2

輸出範例 1

15360

輸入範例 2

100 -4 8 2

輸出範例 2

-1

輸入範例 3

79 0 8 2

輸出範例 3

-2
*/

/* add your value() based on this code */
#include <stdio.h>
int value (int t, int w, int h, int l);

int main ()
{
	int type, width, height, length;
	scanf ( "%d%d%d%d", &type, &width, &height, &length );
	printf ( "%d", value ( type, width, height, length ) );
	return 0;
}

int value (int t, int w, int h, int l) {
	int price, value = 0;

	switch (t) {
		case 79: //Au
			price = 30;
			break;
		case 47: //Ag
			price = 10;
			break;
		case 29: //Cu
			price = 4;
			break;
		case 82: //Pb
			price = 5;
			break;
		case 26: //Fe
			price = 3;
			break;
		case 22: //Ti
			price = 9;
			break;
		default:
			return -1;
	}

	if (w <= 0 || h <= 0 || l <= 0)
		return -2;
	else {
		int max = (w >= h && w >= l) ? w : ((h >= w && h >= l) ? h : l);
		int volume, count, temp;

		for (int i = 1; i < max; ++i) {
			if (w % i == 0 && h % i == 0 && l % i == 0) {
				volume = i * i * i;
				count = (w/i) * (h/i) * (l/i);
				temp = volume * volume * count * price;
				value = (temp > value) ? temp : value;
			}
		}
	}

	return value;
}