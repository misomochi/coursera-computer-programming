/*
題目敘述

寫一個程式計算給定日期為星期幾。輸入會先告訴程式某年的 1 月 1 號為星期幾，例如範例中 2012 年的 1 月 1 號為星期日。接著程式會收到一些日期，並要計算出給定日期為星期幾，例如範例中程式將會收到 11 月 13 號，並計算出該日期為星期二。


輸入格式

第一行包含一個西元年以及該年的一月一日為星期幾，如範例中 2012 0。注意，0 代表星期日，1 代表星期一，以此類推。第二行會告訴程式接下來將有 n 組日期需要計算。n 的範圍為 1 至 10。接下來的 n 行，每一行將會有一組需要計算的日期(月、日)，如範例中的 11 月 13 號。若輸入的「月」有誤請輸出 -1；若輸入的「日」有誤請輸出 -2。

輸出格式

共會輸出 n 個數字。我們用 0 代表星期日，1 代表星期一，以此類推。若輸入的「月」有誤請輸出 -1；若輸入的 「月」無誤但「日」有誤請輸出 -2。(數字間留一個空白)

輸入範例

2012 0
5
11 13
11 14
11 15
13 1
1 200

輸出範例

2 3 4 -1 -2
*/

#include <stdio.h>

int main(void) {
	int year, newYearsDay, leapYear;
	scanf("%d %d", &year, &newYearsDay);
	leapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	
	int num;
	scanf("%d", &num);
	
	int month, day;
	for (int i = 0; i < num; ++i) {
		scanf("%d %d", &month, &day);
		
		//wrong input
		if (month < 1 || month > 12) {
			printf("-1 ");
			continue;
		}
		else if (day < 1) {
			printf("-2 ");
			continue;
		}
		else {
			switch (month) {
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					if (day > 31) {
						printf("-2 ");
						continue;
					}
					break;
				case 4: case 6: case 9: case 11:
					if (day > 30) {
						printf("-2 ");
						continue;
					}
					break;
				case 2:
					if (leapYear && day > 29 || !leapYear && day > 28) {
						printf("-2 ");
						continue;
					}
					break;
				default:
					if (day > 31) {
						printf("-2 ");
						continue;
					}
			}
		}

		//count day
		int dayCount = 0;
		for (int j = 1; j < month; ++j) {
			switch (j) {
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					dayCount += 31;
					break;
				case 4: case 6: case 9: case 11:
					dayCount += 30;
					break;
				case 2:
					dayCount += (leapYear ? 29 : 28);
					break;
				default:
					dayCount += 31;
			}
		}

		dayCount += day;
		printf("%d ", (dayCount - 1 + newYearsDay) % 7);
	}
	
	return 0;
}
